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
import trackingwsn.applications.tracking.appsensor.AppSensor;
import trackingwsn.applications.tracking.estimator.IEstimator;
import trackingwsn.sensors.ass.Ass;

module Sensor extends Node802154
{
    parameters:
        mobility.moving = false;
        net.isBaseStation = false;
        // Tracking algorithm. Default estimator always return (0, 0).
        string estimatorName = default("Estimator");
        @display("i=misc/node2;is=s");
    submodules:
        ass: Ass;
        app: AppSensor;
        est: <estimatorName> like IEstimator;
    connections:
        app.ssGate <--> ass.appGate;
        app.netGate <--> net.appGate;
}
