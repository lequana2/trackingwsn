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

#ifndef __TRACKINGWSN_APP_H_
#define __TRACKINGWSN_APP_H_

#include <omnetpp.h>

/**
 * Abstract module for Application layer
 */
class App : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
    public:
        /* Notify application that some events happened */
        virtual void notifyEvent();
        /* Shutdown system. Can be used by energy module to simulate running out of energy */
        virtual void poweroff();
        /* Check if the node is working or not. One node is not working when it totally powered off. */
        virtual bool isWorking();
};

#endif
