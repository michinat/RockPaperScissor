/*
 * player2Selection.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: michellenatasha
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
