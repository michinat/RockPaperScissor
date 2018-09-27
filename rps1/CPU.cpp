/**
 * CPU subclass implementation
 *
 */

#include "CPU.h"

CPU::CPU() {
    setName("CPU");
    selection = new RandomSelection();
}

CPU::~CPU() {
    delete this;
}

void CPU::makeRPSChoice() {
    setRPS(selection->makeSelection());
}
