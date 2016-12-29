////
//// Saar Shtalryd 307838854 & Itay Oktan 203036512
////
//
//#include <gtest/gtest.h>
//#include "../src/Driver.h"
//#include "../src/TaxiCenter.h"
//#include "../src/LuxuryCab.h"
///**
// * TaxiCenterTest - test class for the TaxiCenter.
// */
//class TaxiCenterTest: public:: testing:: Test{
//protected:
//    Driver* driver;
//    TaxiCenter* taxiCenter;
//    Map* map;
//    Cab* cab;
//    AbstractNode* driverPos;
//    MapRestartListener* listener;
//    vector<Passenger*> passengers;
//    Point point;
//    virtual void SetUp(){
//        Point point(5,5);
//        Point endPoint(2,2);
//        map = new Map(10,10, vector<Point>());
//        taxiCenter = new TaxiCenter(map);
//        driverPos = map->getNode(&point);
//        listener = new MapRestartListener(map);
//        driver= new Driver(5, 30, Status::SINGLE,20, driverPos, listener, map);
//        cab = new LuxuryCab(555, Manufacturer::FIAT,Color::BLUE);
//        taxiCenter->addCab(cab);
//        driver->setCab(cab);
//        taxiCenter->addDriver(driver);
//        taxiCenter->addCall(10, &point, &endPoint, passengers, 2);
//    }
//    virtual void TearDown(){
//        delete map;
//        delete taxiCenter;
//        delete listener;
//
//    }
//public:
//    TaxiCenterTest(){}
//};
//
///*
// * addDriver - test the addDriver function of TaxiCenter.
// */
//TEST_F(TaxiCenterTest, addDriver){
//    Driver* driver2 = new Driver(6, 30, Status::SINGLE,20, driverPos, listener, map);
//    int driversNumber = (int)taxiCenter->getDrivers().size();
//    taxiCenter->addDriver(driver2);
//    EXPECT_EQ(driversNumber +1, (int)taxiCenter->getDrivers().size());
//
//}
//
///*
// * addCab- test the addCab function of TaxiCenter.
// */
//TEST_F(TaxiCenterTest, addCab){
//    Cab* cab2 = new LuxuryCab(555, Manufacturer::FIAT,Color::BLUE);
//    int cabsNumber = (int)taxiCenter->getCabs().size();
//    taxiCenter->addCab(cab2);
//    EXPECT_EQ(cabsNumber +1, (int)taxiCenter->getCabs().size());
//
//}
///*
// * assignCabToDriver - test the assignCabToDriver function of TaxiCenter.
// */
//TEST_F(TaxiCenterTest, assignCabToDriver){
//    EXPECT_EQ(driver->getCab()->getId(), cab->getId());
//
//}
///**
// * handleOpenCalls- test the handleOpenCalls funcion of TaxiCenter.
// */
//TEST_F(TaxiCenterTest, executeTrips){
//    int openCallsNumber = (int)taxiCenter->getOpenCalls().size();
//    taxiCenter->handleOpenCalls();
//    EXPECT_EQ(openCallsNumber - 1, (int)taxiCenter->getOpenCalls().size());
//    taxiCenter->drive();
//    Point point(2,2);
//    EXPECT_EQ(true, (driver->getCurrPos()) == (map->getNode(&point)));
//
//}