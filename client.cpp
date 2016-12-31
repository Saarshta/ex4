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
    char buffer[4096];
    char* end = buffer + 4095;

//    AbstractNode* startNode = new MatrixNode(Point(0,0));
//    AbstractNode* endNode = new MatrixNode(Point(2,2));
//    vector<Passenger *> passengers;
//    Trip* trip = new Trip(0, startNode, endNode, 1, passengers,1);
//    std::string serial_str;
//    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
//    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
//    boost::archive::binary_oarchive oa(s);
//    oa << trip;
//    s.flush();
//    udp->sendData(serial_str);

    DriverOperator driverOperator(udp);
    driverOperator.initializeDriver(); // wait for input
    // Sending the serialized driver.
    driverOperator.sendDriver();
    // Receiving a cab.
    //test
    cout << "now we try to get cab" << endl;
    driverOperator.receiveCab();



    while(true) {
        // Receiving input from server.
        udp->reciveData(buffer, sizeof(buffer));
        // Check if it's 7, if it is, break
        if (strcmp(buffer, "7") == 0) {
            break;
        }
        // Otherwise: check if driver has a trip
        if (driverOperator.isActiveTrip()) {
            //we recieved a new location
            //test
            cout << "we looking for a new pos now" << endl;
            driverOperator.updateLocation();
        } else {
            //we revieved a trip
            //test
            cout << "we looking for a trip now" << endl;
            driverOperator.updateTrip();
        }
        //test current position
        cout << driverOperator.getDriver()->getCurrPos() << "!!" << endl;


    }
    delete udp;
    return 0;
}