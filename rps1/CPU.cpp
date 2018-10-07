/**
 * CPU subclass implementation
 *
 */

#include "CPU.h"

CPU::CPU(CPU::cpuMode_t mode) {
    setName("CPU");

    if (mode == CPU::SIMPLEML)
        selection = new SimpleMLSelection();
    else if (mode == CPU::RANDOM)
        selection = new RandomSelection();

}
