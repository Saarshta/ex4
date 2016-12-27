//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//

#ifndef EX2_LUXURYCAB_H
#define EX2_LUXURYCAB_H


#include "Cab.h"

/**
 * LuxuryCab class. Inherits from Cab.
 */
class LuxuryCab : public Cab{

public:
     ~LuxuryCab();
    virtual int getType();
    LuxuryCab(int id, Manufacturer manu, Color color);
};


#endif //EX2_LUXURYCAB_H
