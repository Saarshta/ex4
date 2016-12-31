//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//

#ifndef EX2_DRIVER_H
#define EX2_DRIVER_H

/**
 * Driver class.
 */
#include <stack>
#include "Status.h"
#include "Cab.h"
#include "Trip.h"
#include "Map.h"
#include "MapRestartListener.h"
#include "Bfs.h"

class Driver {

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & id;
        ar & age;
        ar & marital;
        ar & exp;
        ar & cabID;
        ar & isAvailable;
        ar & searchAlgorithm;
    }
private:
    int id;
    int age;
    Status marital;
    SearchAlgorithm* searchAlgorithm;
    int exp;
    float avgCostumersSat;
    Cab* cab;
    int totalCostumersNumber;
    Trip* currTrip;
    AbstractNode* currPos;
    bool isAvailable;
    stack<AbstractNode*> trail;
    MapRestartListener* mapListener;
    Map* map;
    int cabID;
    void updateSat();



private:
    void validate(int age, int exp, int id);
public:
    Driver(int id, int age, Status marital, int exp,
           int cabID);
    Driver();

    void setAge(int age);
    void setMarital(Status marital);
    void setTrail(const stack<AbstractNode *> &trail);
    void setExp(int exp);
    void setCab(Cab *cab);
    bool setCurrTrip(Trip *newTrip);
    void setIsAvailable(bool isAvailable);
    void setMap(Map* map);
    void setClientTrip(Trip* trip);

    void setCurrPos(AbstractNode *currPos);

    int getCabID() const;

    int getId() const;
    int getAge() const;
    Status getMarital() const;
    int getExp() const;
    float getAvgCostumersSat() const;
    Cab *getCab() const;
    int getTotalCostumersNumber() const;
    Trip *getCurrTrip() const;
    AbstractNode *getCurrPos() const;


    bool isIsAvailable() const;

    int distanceFromNode(AbstractNode* node);

    void moveOneStep(int time);

    virtual ~Driver();
};


#endif //EX2_DRIVER_H
