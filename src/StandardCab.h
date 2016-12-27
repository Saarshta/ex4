//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//

#ifndef EX2_STANDARDCAB_H
#define EX2_STANDARDCAB_H


#include "Cab.h"

/**
 * StandardCab. Inherits from Cab.
 */
class StandardCab : public Cab{

public:
    StandardCab(int id, Manufacturer manu, Color color);
    virtual int getType();
     ~StandardCab();
};




#endif //EX2_STANDARDCAB_H
