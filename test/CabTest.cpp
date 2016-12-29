////
//// Saar Shtalryd 307838854 & Itay Oktan 203036512
////
//#include <gtest/gtest.h>
//#include "../src/Cab.h"
//#include "../src/LuxuryCab.h"
//#include "../src/StandardCab.h"
///**
// * CabTest - Test of the Cab class.
// */
//class CabTest: public:: testing:: Test{
//protected:
//    virtual void SetUp(){
//
//    }
//    virtual void TearDown(){
//
//    }
//public:
//    CabTest(){}
//};
///**
// * CabInputValidation - test the input validation of class Cab.
// */
//TEST_F(CabTest, CabInputValidation){
//    //Testing wrong id of LuxuryCab
//    try {
//        LuxuryCab(-1, Manufacturer::FIAT, Color::BLUE);
//        ASSERT_EQ(-1,1);
//    } catch (std::invalid_argument& err){
//        ASSERT_STREQ(err.what(), "id is invalid");
//    }
//    //Testing wrong id of StandardCab
//    try {
//        StandardCab(-1, Manufacturer::FIAT, Color::BLUE);
//        ASSERT_EQ(-1,1);
//    } catch (std::invalid_argument& err){
//        ASSERT_STREQ(err.what(), "id is invalid");
//    }
//}
