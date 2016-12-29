////
//// Saar Shtalryd 307838854 & Itay Oktan 203036512
////
//#include <gtest/gtest.h>
//#include "../src/Trip.h"
//#include "../src/Point.h"
//#include "../src/MatrixNode.h"
//#include "../src/Defines.h"
//
///**
// * TripTest - test for the Trip class.
// */
//class TripTest: public:: testing:: Test{
//protected:
//    Trip* trip;
//    Point* p1;
//    Point* p2;
//    MatrixNode* maNode1;
//    MatrixNode* maNode2;
//    vector<Passenger*> passengers;
//    Passenger* pass1;
//    Passenger* pass2;
//    virtual void SetUp(){
//        p1 = new Point(0, 0);
//        p2 = new Point(2, 2);
//        pass1 = new Passenger(maNode1, maNode2);
//        pass2 = new Passenger(maNode1, maNode2);
//        maNode1 = new MatrixNode(*p1);
//        maNode2 = new MatrixNode(*p2);
//        passengers.push_back(pass1);
//        passengers.push_back(pass2);
//        trip = new Trip(1,maNode1, maNode2, 4.0, passengers );
//    }
//    virtual void TearDown(){
//        delete p1;
//        delete p2;
//        delete pass1;
//        delete pass2;
//        delete maNode1;
//        delete maNode2;
//        delete trip;
//    }
//
//public:
//    TripTest(){}
//
//};
//
///**
// * TripInputValidation - test the input validation of class Cab.
// */
//TEST_F(TripTest, TripInputValidation){
//    //Testing wrong id of LuxuryCab
//    try {
//        Trip(-1, maNode1, maNode2, 4.0, passengers);
//        ASSERT_EQ(-1,1);
//    } catch (std::invalid_argument& err){
//        ASSERT_STREQ(err.what(), "id or tariff is invalid");
//    }
//    //Testing wrong id of StandardCab
//    try {
//        Trip(0, maNode1, maNode2, -1.0, passengers);
//        ASSERT_EQ(-1,1);
//    } catch (std::invalid_argument& err){
//        ASSERT_STREQ(err.what(), "id or tariff is invalid");
//    }
//}
//
////TEST_F()
///*
// * testSatisfaction - test the testSatisfaction function of Trip.
// */
////TEST_F(TripTest, testSatisfaction){
////    float avgSatis= trip->avgSatisfaction();
////    float testAvg = (pass1->getSatisfaction() + pass2->getSatisfaction())/2;
////    EXPECT_EQ(testAvg,avgSatis);
////}