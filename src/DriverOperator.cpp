//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//

#include "DriverOperator.h"

/**
 * Constructor of DriverOperator
 * @param udp - socket to assign to the member
 * @return
 */
DriverOperator::DriverOperator(Socket *udp) : udp(udp) {
    driver = 0;
    end = buffer + 4095;
}
/**
 * initializeDriver - get input from user throgh console and
 * create a new driver and assign it as member.
 */
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

    AbstractNode* startNode = new MatrixNode(Point(0,0));
    this->driver = new Driver(id, age, marital, exp, cabID);
    this->driver->setCurrPos(startNode);
}
/**
 * getter of driver member.
 * @return driver
 */
Driver *DriverOperator::getDriver() const {
    return driver;
}
/**
 * Destructor of DriverOperator.
 * delete the udp, the driver and its members like:
 * cab, current position, trip.
 */
DriverOperator::~DriverOperator() {
    delete udp;
    delete (driver->getCab());
    MatrixNode* tempNode = (MatrixNode*)this->driver->getCurrPos();
    //tempNode->destroyLocation();
    delete tempNode;
    if(isActiveTrip()) {
        delete (MatrixNode *) this->driver->getCurrTrip()->getStart();
        delete (MatrixNode *) this->driver->getCurrTrip()->getEnd();
    }
    //delete this->driver->getCurrPos();
    delete driver;
}
/**
 * sendDriver - serialize the driver and send it through the udp.
 */
void DriverOperator::sendDriver() {

    std::string serial_str;
    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    oa << (this->driver);
    s.flush();
    udp->sendData(serial_str);

}
/**
 * receiveCab - get a serialized cab through udp, deserialize it
 * and assign it to the driver.
 */
void DriverOperator::receiveCab() {

    Cab* cab = 0;
    udp->reciveData(buffer, sizeof(buffer));
    boost::iostreams::basic_array_source<char> device(buffer, end);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> cab;
    this->driver->setCab(cab);

}
/**
 * updateLocation - get a serialized position, deserialize it and assign it
 * to the driver. check if the position is in end of trip, then end trip.
 */
void DriverOperator::updateLocation() {
    AbstractNode* node = 0;
    boost::iostreams::basic_array_source<char> device(buffer, end);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> node;
    MatrixNode* tempNode = (MatrixNode*)this->driver->getCurrPos();
    //tempNode->destroyLocation();
    delete tempNode;
    //delete this->driver->getCurrPos();
    this->driver->setCurrPos(node);
    if (*(node) == *(this->driver->getCurrTrip()->getEnd())) {
        delete (MatrixNode*)this->driver->getCurrTrip()->getStart();
        delete (MatrixNode*)this->driver->getCurrTrip()->getEnd();
        delete (driver->getCurrTrip());
        this->driver->setClientTrip(0);
    }
}
/**
 * updateTrip - get a serialized trip, deserialize it and assign to driver.
 */
void DriverOperator::updateTrip() {

    Trip* trip = 0;
    boost::iostreams::basic_array_source<char> device(buffer, end);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> trip;
    this->driver->setClientTrip(trip);

}
/**
 * isActiveTrip - return true if the driver has a trip, else otherwise.
 * @return
 */
bool DriverOperator::isActiveTrip() {

    return !this->driver->getCurrTrip() == 0;
}
/**
 * receivingData - wait for data through the socket.
 */
void DriverOperator::receivingData() {
    udp->reciveData(buffer, sizeof(buffer));
}
/**
 * isDataEnd - check if we got a "7" thorugh socket that indicates the
 * end of program.
 * @return
 */
bool DriverOperator::isDataEnd() {
    return strcmp(buffer, "7")==0;
}
