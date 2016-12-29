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
    Udp udp(0, atoi(argv[2]));
    udp.initialize();
    char buffer[1024];

    DriverOperator driverOperator;
    driverOperator.initializeDriver(); // wait for input
    //serialize driver into buffer


    udp.sendData("the serialized driver");
    udp.reciveData(buffer, sizeof(buffer)); // get serialized cab
    udp.reciveData(buffer, sizeof(buffer)); // get serialized map

    //deserialize cab and map and set into driver
    cout << buffer << endl;

    udp.reciveData(buffer, sizeof(buffer)); // get serialized trip
    //deserelize trip and set into driver


    return 0;
}