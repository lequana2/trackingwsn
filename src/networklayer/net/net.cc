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

#include "net.h"
#include "mobility.h"
#include "link802154.h"
#include "worldutil.h"
#include "app.h"

Define_Module(Net);

void Net::initialize()
{}

void Net::handleMessage(cMessage *msg)
{}

Net::Net()
{
    macAddr = -1;
}

Net::~Net()
{}

/* Store position of base station */
void Net::setBSPos(double x, double y)
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
int Net::getMacAddr()
{
    if (macAddr <= 0) {
        macAddr = ((Link802154*) getParentModule()->getSubmodule("link"))->getAddr();
    }
    return macAddr;
}

/* Notify application layer that some events occur */
void Net::notifyApp()
{
    App *app = check_and_cast<App*>(getParentModule()->getSubmodule("app"));
    app->notifyEvent();
}
