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

#ifndef __TRACKINGWSN_ARPEES_H_
#define __TRACKINGWSN_ARPEES_H_

#include "net.h"
#include "messagecr_m.h"
#include "packetarpees_m.h"
#include <omnetpp.h>

/**
 * Network layer using ARPEES protocol
 */
class NetARPEES : public Net
{
    private:
        // MAC addresses for routing
        // Value 0 means connection info is not initialized.
        int bsAddr; // Base station
        int rnAddr; // Relay node

        // Stored information about relay/backup nodes
        double enerRn; // Energy
        double dRnBs; // Distance from relay node to base station in meter
        double dRn; // Distance from relay node to this node

        cPacketQueue outQueue; // Packet queue waiting for sending
        cMessage *recvRelayInfoTimer; // For finishing receiving relay info and start sending

        /* Process received message from upper layer */
        void recvMessage(MessageCR *msg);
        /* Process received packet from lower layer */
        void recvPacket(PacketARPEES *pkt);

        /* Send packet to link layer for sending out */
        void sendPacket(PacketCR *pkt);
        /* Create a packet encapsulating a message. */
        PacketARPEES* createPacket(MessageCR *msg);
        /* Send all queued packets.
         * When finish reset relay node address (to find new relay node next time). */
        void sendQueuedPackets();

        /* Broadcast packet for requesting relay information */
        void requestRelay();
        /* Response to a request for relay node, given the requesting packet */
        void sendRelayInfo(PacketARPEES *reqPkt);
        /*
         * Compare new relay info with current relay node; if it's better, select it as new relay
         * node.
         */
        void considerRelay(PacketARPEES_RelayInfo *ri);
        /*
         * Function for assessing a candidate for relaying.
         * Parameters:
         *  ener: energy of relay candidate
         *  dRc: distance from this node to relay candidate
         *  dBs: distance from this node to base station
         *  dRcBs: distance from relay candidate to base station
         */
        double assessRelay(double ener, double dRc, double dBs, double dRcBs);

    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);

    public:
        NetARPEES();
        ~NetARPEES();
};

#endif
