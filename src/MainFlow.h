//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//

#ifndef EX2_MAINFLOW_H
#define EX2_MAINFLOW_H


#include "TaxiCenter.h"
#include "StandardCab.h"
#include "LuxuryCab.h"
#include <stdexcept>

/**
 * MainFlow.
 */
class MainFlow {
private:
    TaxiCenter* taxiCenter;
    Map* map;
public:
    MainFlow(int sizeX, int sizeY, vector<Point> obstacle);

    ~MainFlow();

    void run(char** argv);

};


#endif //EX2_MAINFLOW_H
