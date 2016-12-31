//
// Created by itayoktan on 02/12/16.
//

#include "StandardCab.h"

/**
 * StandardCab constructor.
 * @param id the cab's ID.
 * @param manu the cab's manufacturer.
 * @param color the cab's color.
 * @param tariff the cab's Tariff.
 * @return nothing.
 */
StandardCab::StandardCab(int id, Manufacturer manu, Color color) : Cab(id, manu, color, 1
                                                                                 ) {
}
/**
 *
 * @return
 */
int StandardCab::getType() {
    return 1;
}
/**
 * StandardCab default destructor.
 */
StandardCab::~StandardCab() {

}

BOOST_CLASS_EXPORT(StandardCab)
