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

package trackingwsn.nodes;

import trackingwsn.linklayer.Link802154;
import trackingwsn.networklayer.INet;
import trackingwsn.networklayer.emrp.NetEMRP;
import trackingwsn.energy.Energy;

module Node802154 extends Entity
{
    parameters:
    	// Network layer module name
        string netModuleName = default("NetEMRP");
    submodules:
        net: <netModuleName> like INet;
        link: Link802154;
        energy: Energy;
    connections:
        net.linkGate <--> link.netGate;
}
