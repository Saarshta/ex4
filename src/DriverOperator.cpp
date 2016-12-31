//
// Created by saar on 29/12/16.
//

#include "DriverOperator.h"


DriverOperator::DriverOperator(Socket *udp) : udp(udp) {
    driver = 0;
    end = buffer + 4095;
}

void DriverOperator::initializeDriver() {
    int id, age, exp, cabID;
    char blank;
    char maritalSign;
    Status marital;
    cin >> id >> blank >> age >> blank >> maritalSign >> blank >>
        exp >> blank >> cabID;
    switch (maritalSign) {
        // Options are Widowed, Divorced, Single, Married.
        case 'W':
            marital = Status::WIDOWED;
            break;
        case 'D':
            marital = Status::DIVORCED;
            break;
        case 'S':
            marital = Status::SINGLE;
            break;
        case 'M':
            marital = Status::MARRIED;
            break;
        default:
            throw invalid_argument("marital status is invalid");
    }
    this->driver = new Driver(id, age, marital, exp, cabID);
    AbstractNode* startNode = new MatrixNode(Point(0,0));
    this->driver->setCurrPos(startNode);
}

Driver *DriverOperator::getDriver() const {
    return driver;
}

DriverOperator::~DriverOperator() {
    delete udp;
    delete driver;
}

void DriverOperator::sendDriver() {

    std::string serial_str;
    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    oa << (this->driver);
    s.flush();
    udp->sendData(serial_str);

}

void DriverOperator::receiveCab() {


    Cab* cab = 0;
    udp->reciveData(buffer, sizeof(buffer));
    boost::iostreams::basic_array_source<char> device(buffer, end);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> cab;
    this->driver->setCab(cab);
    //test
    cout << "cab id is:" ;
    cout << cab->getId()<< endl;
}

void DriverOperator::updateLocation() {
    AbstractNode* node = 0;
    boost::iostreams::basic_array_source<char> device(buffer, end);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> node;
    this->driver->setCurrPos(node);
    //test
    cout << node << endl;
}

void DriverOperator::updateTrip() {

    //test
    cout << "we enter to updatetrip!" << endl;
    Trip* trip = 0;
    boost::iostreams::basic_array_source<char> device(buffer, end);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> trip;
    this->driver->setClientTrip(trip);
    //test
    cout << trip->getId() << endl;
}
// check if driver has a trip
bool DriverOperator::isActiveTrip() {

    return !this->driver->getCurrTrip() == NULL;
}