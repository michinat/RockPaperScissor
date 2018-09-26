/*
 * CPU.h
 *
 *  Created on: Sep 25, 2018
 *      Author: michellenatasha
 */

#ifndef CPU_H_
#define CPU_H_
#include "Player.h"

class CPU : public Player {
private:
	// TODO make chooser
public:
	CPU();
	virtual ~CPU();
	void makeRPSChoice();
};

#endif /* CPU_H_ */
