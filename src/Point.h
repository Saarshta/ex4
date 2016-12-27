//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//

#ifndef EX1_ADV_PROGRAMMING_POINT_H
#define EX1_ADV_PROGRAMMING_POINT_H

#include <iostream>
#include "AbstractPoint.h"

/**
 * Class Point
 * represents a point, including X and Y axis values.
 */
using namespace std;
class Point : public AbstractPoint {
private:
    int x;
    int y;
public:
    Point(int x = -1, int y = -1);
    int getX() const;
    int getY() const;
    bool operator==(const Point& other);
    bool operator!=(const Point& other);
    friend ostream& operator<<(std::ostream& os, const Point& p);

};


#endif //EX1_ADV_PROGRAMMING_POINT_H
