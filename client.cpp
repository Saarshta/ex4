//
// Created by yanaiela on 12/10/16.
//

#include "src/Udp.h"
#include <unistd.h>
#include "src/DriverOperator.h"

using namespace std;

int main(int argc, char *argv[]) {
    std::cout << "Hello, from client" << std::endl;

    cout << argv[2] << endl;
    Socket* udp = new Udp(0, atoi(argv[2]));
    udp->initialize();

    DriverOperator driverOperator(udp);
    driverOperator.initializeDriver(); // wait for input
    // Sending the serialized driver.
    driverOperator.sendDriver();
    // Receiving a cab.
    driverOperator.receiveCab();



    while(true) {
        // Receiving input from server.
        driverOperator.receivingData();
        // Check if it's 7, if it is, break
        if(driverOperator.isDataEnd()){
            cout << "ok, bye bye"<< endl;
            break;
        }
        // Otherwise: check if driver has a trip
        if (driverOperator.isActiveTrip()) {
            //we recieved a new location
            driverOperator.updateLocation();
        } else {
            //test
            cout << "new trip"<<endl;
            //we revieved a trip
            driverOperator.updateTrip();
        }
        //test current position
        cout << *(driverOperator.getDriver()->getCurrPos()) << endl;

    }
    return 0;
}