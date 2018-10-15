/**
 * CPU subclass header
 *
 */

#ifndef CPU_H_
#define CPU_H_

#include "Player.h"
#include "RandomSelection.h"
#include "SimpleMLSelection.h"

class CPU : public Player {
public:

    // enum defines modes of selection
    typedef enum {
        RANDOM = 0,
        SIMPLEML = 1
    } cpuMode_t;

    explicit CPU(cpuMode_t mode);
    ~CPU() override = default;

};

#endif /* CPU_H_ */
