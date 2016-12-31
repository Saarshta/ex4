//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//

#include "Trip.h"



/**
 * Trip constructor.
 * @param id the trip's ID.
 * @param startNode the trip's starting node.
 * @param endNode the trip's ending node.
 * @param tariff the trip's Tariff.
 * @param passengers the trip's passengers.
 * @return nothing.
 */
Trip::Trip(int id, AbstractNode* startNode, AbstractNode* endNode,
           float tariff, const vector<Passenger *> &passengers, int startingTime) :
        id(id), startNode(startNode), endNode(endNode), tariff(tariff),
        passengers(passengers), startingTime(startingTime) {
    // Checking validity of ID and tariff.
    validate(id, tariff);
    passNum =(int) passengers.size();
    currMeters = 0;
}

Trip::Trip() {
}

/**
 * avgSatisfaction the trip's passenger's average satisfaction.
 * @return
 */
float Trip::avgSatisfaction() {
    return 0.0;
}

/**
 * getPassNum
 * @return the amount of passengers in the trip.
 */
int Trip::getPassNum() {
    return 0;
}

/**
 * getStart
 * @return the trip's starting node.
 */
AbstractNode* Trip::getStart() {
    return startNode;
}

/**
 * getEnd
 * @return the trip's ending node.
 */
AbstractNode* Trip::getEnd() {
    return endNode;
}

/**
 * getId - returns the trip's ID.
 * @return the trip's ID.
 */
int Trip::getId() const {
    return id;
}

/**
 * validate - checks validity of trip's id and tariff.
 * @param id the trip's ID.
 * @param tariff the trip's tariff.
 */
void Trip::validate(int id, float tariff) {
    // Check for input validity for age, id, exp.
    if(tariff < 0 || id < 0){
        throw invalid_argument("id or tariff is invalid");
    }
}

int Trip::getStartingTime() const {
    return startingTime;
}

void Trip::setPassNum(int passNum) {
    Trip::passNum = passNum;
}
