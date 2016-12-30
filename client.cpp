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
    driverOperator.receiveCab();

    // create and serialize driver into buffer


//    while(true) {
//        // Receiving input from server.
//        udp->reciveData(buffer, sizeof(buffer));
//        // Check if it's 7, if it is, break
//        // Otherwise:
//        if (driverOperator.isActiveTrip()) {
//            driverOperator.updateLocation(buffer, end);
//        }
//        else {
//            driverOperator.updateTrip(buffer, end);
//        }
//        cout << driverOperator.getDriver()->getCurrPos() << "!!" << endl;
        // if we got 7 then break
        // if currentTrip is null wait for trip
            //deserelize trip and set into driver

        // else we wait for move (get current time)
            //this.driver.move(time)



    //}
    delete udp;
    return 0;
}