/*
 * Human.h
 *
 *  Created on: Sep 25, 2018
 *      Author: michellenatasha
 */

#ifndef HUMAN_H_
#define HUMAN_H_

#include "Player.h"

class Human : public Player {
public:
    Human();
    virtual ~Human();

    void makeRPSChoice() override;
};

#endif /* HUMAN_H_ */
