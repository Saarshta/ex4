////
//// Saar Shtalryd 307838854 & Itay Oktan 203036512
////
//
//#include <gtest/gtest.h>
//#include "../src/Passenger.h"
//#include "../src/Trip.h"
//#include "../src/Driver.h"
//#include "../src/LuxuryCab.h"
//
//
///**
// * DriverTest - test of the Driver class.
// */
//class DriverTest: public:: testing:: Test{
//protected:
//    AbstractNode* start;
//    AbstractNode* end;
//    Passenger* p1;
//    Passenger* p2;
//    vector<Passenger*> passengers;
//    Trip* trip;
//    Driver* driver;
//    vector<Point> obst;
//    Map* map;
//    MapRestartListener* listener;
//    Point startPoint;
//    Point endPoint;
//    virtual void SetUp(){
//        map =new Map(10,10, obst);
//        startPoint = Point(0,0);
//        endPoint = Point(2,2);
//        start= map->getNode(&startPoint);
//        end= map->getNode(&endPoint);
//        p1= new Passenger(start, end);
//        p2=new Passenger(start,end);
//        passengers.push_back(p1);
//        passengers.push_back(p2);
//        trip = new Trip(1,start, end, 3.0, passengers );
//        listener = new MapRestartListener(map);
//        driver = new Driver(1,30,Status::SINGLE, 20, start, listener, map);
//        driver->setCurrTrip(trip);
//    }
//    virtual void TearDown(){
//        delete p1;
//        delete p2;
//        delete driver;
//        delete map;
//        delete listener;
//    }
//
//public:
//    DriverTest(){}
//
//};
//
///**
// * DriverInputValidation - test input validation of Driver class.
// */
//
//
//TEST_F(DriverTest, DriverInputValidation) {
//    //Testing wrong id
//    try{
//        Driver(-1,30,Status::SINGLE, 20, start, listener, map);
//        ASSERT_EQ(-1,1);
//    } catch (std::invalid_argument& err){
//        ASSERT_STREQ(err.what(), "age,id or exp is invalid");
//    }
//    //Testing wrong age
//    try{
//        Driver(30,0,Status::SINGLE, 20, start, listener, map);
//        ASSERT_EQ(-1,1);
//    } catch (std::invalid_argument& err){
//        ASSERT_STREQ(err.what(), "age,id or exp is invalid");
//    }
//    //Testing wrong years of experience
//    try{
//        Driver(206535412,40,Status::SINGLE, -2, start, listener, map);
//        ASSERT_EQ(-1,1);
//    } catch (std::invalid_argument& err){
//        ASSERT_STREQ(err.what(), "age,id or exp is invalid");
//    }
//}
///**
// * DriverTestFunctions - test for the functions of Driver,
// * like moveOneStep, distanceToPoint, satisfaction.
// */
//TEST_F(DriverTest, DriverTestFunctions){
//
//    //Testing distanceToPoint function.
//    ASSERT_EQ(5,driver->distanceFromNode(end));
//    EXPECT_EQ(1,driver->distanceFromNode(start));
//
//    //Testing moveOneStep function.
//    driver->moveOneStep();
//    driver->moveOneStep();
//    EXPECT_EQ(4,driver->distanceFromNode(end));
//    EXPECT_EQ(2,driver->distanceFromNode(start));
//    driver->drive();
//    EXPECT_EQ(1,driver->distanceFromNode(end));
//    EXPECT_EQ(5,driver->distanceFromNode(start));
//
//    //now trip is over and moveOneStep is updating satisfaction
//    //float avg = (p1->getSatisfaction()+p2->getSatisfaction())/2;
//    //EXPECT_EQ(avg,driver->getAvgCostumersSat());
//
//}
///**
// * DriverTestPrint - test the printing of Driver.
// */
//TEST_F (DriverTest, DriverTestPrint) {
//    ostringstream output;
//    output << *(driver->getCurrPos());
//    ASSERT_EQ("(0,0)", output.str());
//}