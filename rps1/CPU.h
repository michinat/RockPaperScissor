/*
 * player2Selection.h
 *
 *  Created on: Sep 25, 2018
 *      Author: michellenatasha
 */

#ifndef CPU_H_
#define CPU_H_

#include "Player.h"
#include "RandomSelection.h"

class CPU : public Player {
private:
    Selection * selection;
public:
    CPU();
    ~CPU() override;

	void makeRPSChoice() override;

};

#endif /* CPU_H_ */
