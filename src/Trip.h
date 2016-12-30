//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//

#ifndef EX2_TRIP_H
#define EX2_TRIP_H


#include "AbstractNode.h"
#include "Passenger.h"
#include <stdexcept>

/**
 * Trip.
 */
class Trip {
private:
    int id;
    int currMeters;
    AbstractNode* startNode;
    AbstractNode* endNode;
    int passNum;
    float tariff;
    vector<Passenger*> passengers;
    void validate(int id, float tariff);
    int startingTime;

public:
    Trip(int id, AbstractNode *startNode, AbstractNode *endNode, float tariff,
          const vector<Passenger *> &passengers, int startingTime);
    float avgSatisfaction();
    int getPassNum();
    AbstractNode* getEnd();
    AbstractNode* getStart();

    int getStartingTime() const;

    int getId() const;

};


#endif //EX2_TRIP_H
