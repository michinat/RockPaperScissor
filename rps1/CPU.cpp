/**
 * CPU subclass implementation
 *
 */

#include "CPU.h"

CPU::CPU(CPU::cpuMode_t mode) {
    setName("CPU");
    if (mode == CPU::RANDOM)
        selection = new RandomSelection();
}

CPU::~CPU() {
    delete this;
}
