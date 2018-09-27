/**
 *  RPS selection
 *  pure abstract interface file
 */

#ifndef RPS1_SELECTION_H
#define RPS1_SELECTION_H

#include "RPS_type.h"

class Selection {
public:
    Selection() = default;

    virtual ~Selection() {
        delete this;
    }

    /// abstract virtual function
    /// to be defined in subclasses
    virtual selection_t makeSelection() = 0;

};

#endif //RPS1_SELECTION_H
