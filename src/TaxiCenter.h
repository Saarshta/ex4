//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//

#ifndef EX2_TAXICENTER_H
#define EX2_TAXICENTER_H

/**
 * TaxiCenter.
 */

#include "Driver.h"
#include "Udp.h"

class Driver;
class Cab;
class Trip;
class Passenger;
class TaxiCenter {
private:
    Map* map;
    vector<Driver*> drivers;
    vector<Cab*> cabs;
    int currentTime;
public:
    void setUdp(Udp *udp);

private:
    vector<Trip*> openCalls;
    Udp* udp;

    void removeCall(int CallID);
    bool findClosestDriver(Trip* call);
public:
    TaxiCenter(Map *map);
    virtual ~TaxiCenter();
    const vector<Cab *> &getCabs() const;
    const vector<Trip *> &getOpenCalls() const;
    const vector<Driver *> &getDrivers() const;

    Driver* getDriverByID(int id);
    Cab* getCabByID(int id);
    void addDriver(Driver* newDriver);
    void addCall(int id, AbstractPoint* start, AbstractPoint* end, const vector<Passenger *> passengers, float tariff);
    void addCab(Cab* newCab);
    void handleOpenCalls();
    void drive();

    void timePassed();

    void assignCabToDriver(int driverID, int CabID);

};


#endif //EX2_TAXICENTER_H
