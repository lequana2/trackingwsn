//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "netemrp.h"
#include "packetemrp_m.h"
#include "link802154.h" // TODO This should be module interface
#include "energy.h"
#include "mobility.h"
#include "worldutil.h"
#include "msgkind.h"

Define_Module(NetEMRP);

void NetEMRP::initialize()
{
    // Set timer for initialize EMRP first time
    scheduleAt(uniform(0, par("initPeriod")), initMsg);
}

void NetEMRP::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage()) {
        if (msg == initMsg) {
            requestRelay();
        } else if (msg->getKind() == EMRP_RES_RELAY) {
            sendRelayInfo((PacketEMRP*) msg->getContextPointer());
            delete msg;
        }
    } else {
        if (msg->getArrivalGate() == gate("linkGate$i")) {
            recvPacket((PacketEMRP*) msg);
        }
    }
}

NetEMRP::NetEMRP()
{
    macAddr = -1;
    bsAddr = 0;
    rlAddr = 0;
    bkAddr = 0;

    enerRl = 0;
    dRlBs = 0;
    enerBk = 0;
    dBkBs = 0;

    initMsg = new cMessage("InitEmrpMsg");
}

NetEMRP::~NetEMRP()
{
    cancelAndDelete(initMsg);
}

/* Store position of base station */
void NetEMRP::setBSPos(double x, double y)
{
    Mobility *mob = (Mobility*) getParentModule()->getSubmodule("mobility");
    bsPosX = x;
    bsPosY = y;
    dBS = distance(x, y, mob->getX(), mob->getY());
}

/*
 * Get MAC address from link layer. At initial stage, this address may not available
 * and this function may not work correctly.
 */
int NetEMRP::getMacAddr()
{
    if (macAddr < 0) {
        macAddr = ((Link802154*) getParentModule()->getSubmodule("link"))->getAddr();
    }
    return macAddr;
}

/*
 * Process received packet
 */
void NetEMRP::recvPacket(PacketEMRP *pkt)
{
    if (pkt->getPkType() == PK_REQ_RELAY) {
        cMessage *resRelayMsg = new cMessage("ResRelayMsg");
        resRelayMsg->setKind(EMRP_RES_RELAY);
        resRelayMsg->setContextPointer(pkt->dup());
        scheduleAt(simTime() + uniform(0, par("resRelayPeriod").doubleValue()), resRelayMsg);
    } else if (pkt->getPkType() == PK_RELAY_INFO) {
        PacketEMRP_RelayInfo *ri = check_and_cast<PacketEMRP_RelayInfo*>(pkt);
        if (ri->getBsFlag() == true) {
            bsAddr = ri->getSrcMacAddr();
        } else {
            if (bsAddr <= 0) {
                bool ret = considerRelay(ri);
                if (!ret) considerBackup(ri);
            }
        }
    }

    delete pkt;
}

/*
 * Broadcast request for info of base station/relay/backup node.
 */
void NetEMRP::requestRelay()
{
    // Send request for relay node
    PacketEMRP *pkt = new PacketEMRP();
    pkt->setTxType(TX_BROADCAST);
    pkt->setPkType(PK_REQ_RELAY);
    pkt->setSrcMacAddr(getMacAddr());
    // No need to set desMacAddr here

    pkt->setByteLength(86); // TODO hard code

    send(pkt, "linkGate$o");
}

/*
 * Response to a request for relay node, given the requesting packet
 */
void NetEMRP::sendRelayInfo(PacketEMRP *reqPkt)
{
    PacketEMRP_RelayInfo *pkt = new PacketEMRP_RelayInfo();
    pkt->setTxType(TX_PPP);
    pkt->setPkType(PK_RELAY_INFO); // WARNING: do not confuse with PK_REQ_RELAY
    pkt->setSrcMacAddr(getMacAddr());
    pkt->setDesMacAddr(reqPkt->getSrcMacAddr());

    // Add relay info
    if (par("isBaseStation").boolValue() == true) {
        pkt->setBsFlag(true);
    } else {
        pkt->setBsFlag(false);
    }
    pkt->setEnergy(((Energy*) getParentModule()->getSubmodule("energy"))->getCapacity());
    Mobility *mob = (Mobility*) getParentModule()->getSubmodule("mobility");
    pkt->setPosX(mob->getX());
    pkt->setPosY(mob->getX());
    pkt->setDBS(dBS);

    pkt->setByteLength(86); // TODO hard code

    send(pkt, "linkGate$o");
    delete reqPkt;
}

/*
 * Compare new relay info with current relay node; if it's better, select it as new relay node.
 * Return true when new the node having new relay info is selected as new relay node.
 */
bool NetEMRP::considerRelay(PacketEMRP_RelayInfo *ri)
{
    Mobility *mob = (Mobility*) getParentModule()->getSubmodule("mobility");
    // Distance from this node to candidate
    double dRc = distance(mob->getX(), mob->getY(), ri->getPosX(), ri->getPosY());

    if (rlAddr <= 0) {
        // No relay node has been selected, select this candidate
        rlAddr = ri->getSrcMacAddr();

        enerRl = ri->getEnergy();
        dRlBs = ri->getDBS();
        dRl = dRc;

        return true;
    } else {
        // Compare relay info of candidate to current relay node
        double a1 = assessRelay(enerRl, dRl, dBS, dRlBs);
        double a2 = assessRelay(ri->getEnergy(), dRc, dBS, ri->getDBS());

        if (a2 > a1) {
            rlAddr = ri->getSrcMacAddr();

            enerRl = ri->getEnergy();
            dRlBs = ri->getDBS();
            dRl = dRc;

            return true;
        } else {
            return false;
        }
    }
}

/*
 * Compare new relay info with current backup node; if it's better, select it as new backup node.
 * Return true when new the node having new relay info is selected as new backup node.
 */
bool NetEMRP::considerBackup(PacketEMRP_RelayInfo *ri)
{
    Mobility *mob = (Mobility*) getParentModule()->getSubmodule("mobility");
    // Distance from this node to candidate
    double dRc = distance(mob->getX(), mob->getY(), ri->getPosX(), ri->getPosY());

    if (bkAddr <= 0) {
        // No relay node has been selected, select this candidate
        bkAddr = ri->getSrcMacAddr();

        enerBk = ri->getEnergy();
        dBkBs = ri->getDBS();
        dBk = dRc;

        return true;
    } else {
        // Compare relay info of candidate to current relay node
        double a1 = assessRelay(enerBk, dBk, dBS, dBkBs);
        double a2 = assessRelay(ri->getEnergy(), dRc, dBS, ri->getDBS());

        if (a2 > a1) {
            bkAddr = ri->getSrcMacAddr();

            enerBk = ri->getEnergy();
            dBkBs = ri->getDBS();
            dBk = dRc;

            return true;
        } else {
            return false;
        }
    }
}

/*
 * Function for assessing a candidate for relaying.
 * Parameters:
 *  ener: energy of relay candidate
 *  dRc: distance from this node to relay candidate
 *  dBs: distance from this node to base station
 *  dRcBs: distance from relay candidate to base station
 */
double NetEMRP::assessRelay(double ener, double dRc, double dBs, double dRcBs)
{
    double cosa = (dRc*dRc + dBs*dBs - dRcBs*dRcBs) / (2 * dRcBs * dBs);
    return ener / dRcBs * cosa;
}
