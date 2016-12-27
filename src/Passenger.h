//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//
#ifndef EX2_PASSENGER_H
#define EX2_PASSENGER_H


#include "AbstractNode.h"

/**
 * Passenger.
 */
class Passenger {

private:
    AbstractNode* start;
    AbstractNode* end;
    int satisfaction;
public:
    int generateRandomSatisfaction();
    int getSatisfaction() const;
    Passenger(AbstractNode *start, AbstractNode *end);

};


#endif //EX2_PASSENGER_H
