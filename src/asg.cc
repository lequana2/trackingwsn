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

#include "asg.h"
#include "sensedsignal_m.h"

Define_Module(Asg);

void Asg::initialize()
{
    // TODO - Generated method body
}

void Asg::handleMessage(cMessage *msg)
{
    // Create signal message and send back to sensor
    SensedSignal *sig = new SensedSignal("SensedSignal");
    // TODO Add content to message
    //sig->setTarId(par("id"));
    //sig->setSignal(par("signal"));
    // sig->setDistance(distance(sensor));

    send(sig, gate("gate"));

    // Delete requesting message
    delete msg;
}
