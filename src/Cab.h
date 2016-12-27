//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//

#ifndef EX2_CAB_H
#define EX2_CAB_H
#include "Color.h"
#include "Manufacturer.h"

/**
 * Abstract Cab class.
 * Different Cab types will inherit from this class.
 */
class Cab {

protected:
    int id;
    float kilometrage;
    Manufacturer manu;
    Color color;
    int speed;

    void validate(int id);

    Cab(int id, Manufacturer manu, Color color, int speed);

public:
    void setKilometrage(float kilometrage);

    int getId() const;
    float getKilometrage() const;
    Manufacturer getManu() const;
    Color getColor() const;
    int getSpeed() const;
    virtual int getType() =0;

    virtual ~Cab();

};


#endif //EX2_CAB_H
