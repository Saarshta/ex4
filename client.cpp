//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//

#include "src/Udp.h"
#include <unistd.h>
#include "src/DriverOperator.h"

using namespace std;

int main(int argc, char *argv[]) {

    // Reading port.
    Socket* udp = new Udp(0, atoi(argv[2]));
    udp->initialize();
    // Initializing driverOperator.
    DriverOperator driverOperator(udp);
    // Initializing driver.
    driverOperator.initializeDriver(); // wait for input
    // Sending the serialized driver.
    driverOperator.sendDriver();
    // Receiving a cab.
    driverOperator.receiveCab();


    while(true) {
        // Receiving input from server.
        driverOperator.receivingData();
        // Check if it's 7, if it is, break.
        if(driverOperator.isDataEnd()){
            break;
        }
        // Otherwise: check if driver has a trip
        if (driverOperator.isActiveTrip()) {
            // If there is an active trip, expect a new location.
            driverOperator.updateLocation();
        } else {
            // If there is no active trip, expect a new trip.
            driverOperator.updateTrip();
        }

    }
    return 0;
}