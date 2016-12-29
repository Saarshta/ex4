//
// Created by saar on 29/12/16.
//

#include "DriverOperator.h"


DriverOperator::DriverOperator() {
    driver = 0;
};

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
    this->driver = new Driver(id, age, marital, exp, cabID);
}