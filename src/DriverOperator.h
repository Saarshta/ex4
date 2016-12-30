//
// Created by saar on 29/12/16.
//

#ifndef EX4_DRIVEROPERATOR_H
#define EX4_DRIVEROPERATOR_H


#include "Driver.h"
#include "Socket.h"

class DriverOperator {
private:
    Driver* driver;
    Socket* udp;
    char buffer[4096];
    char* end;
public:
    DriverOperator(Socket* udp);

    virtual ~DriverOperator();

    void initializeDriver();
    Driver *getDriver() const;
    bool isActiveTrip();

    void sendDriver();

    void receiveCab();

    void updateLocation();
    void updateTrip();

};


#endif //EX4_DRIVEROPERATOR_H
