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

package trackingwsn;

import trackingwsn.nodes.Node802154;
import trackingwsn.applications.tracking.appbasestation.AppBaseStation;

module BaseStation extends Node802154
{
    parameters:
        mobility.moving = false;
        energy.hasLinePower = true;
        net.isBaseStation = true;
        @display("i=device/antennatower");
    submodules:
        app: AppBaseStation;
    connections:
        app.netGate <--> net.appGate;
}
