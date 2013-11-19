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

#ifndef __TRACKINGWSN_APPSENSOR_H_
#define __TRACKINGWSN_APPSENSOR_H_

#include "sensedresult_m.h"
#include "messagetracking_m.h"
#include "meacoll.h"
#include <omnetpp.h>

/*
 * Working modes of sensor
 * WORK_MODE_OFF: Sensor will not do anything (mode for out of energy)
 * WORK_MODE_SLEEP: Cannot sense for target or send/receive packets but can be waken up
 * WORK_MODE_ACTIVE: Full features mode
 */
#define WORK_MODE_OFF 0
#define WORK_MODE_SLEEP 1
#define WORK_MODE_ACTIVE 2

/**
 * Sensor's Application Layer
 */
class AppSensor : public cSimpleModule
{
    private:
        int workMode;

        bool syncSense;
        cMessage *senseTimer; // Self message for start sensing
        cMessage *reportTimer; // Timer for reporting measurement
        cMessage *collTimer; // Timer for collecting measurements
        std::list<Measurement> meaList; // Measurement list of recent sensing
        MeaColl mc; // Measurement collection

        void sendSenseResult();
        void recvSenseResult(SensedResult *result);
        void recvMessage(MsgTracking *msg); // Receive message from other node
        void trackTargets();

    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);

    public:
        AppSensor();
        ~AppSensor();
};

#endif
