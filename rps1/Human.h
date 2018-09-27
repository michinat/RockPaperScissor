/**
 * Human subclass header
 *
 */

#ifndef HUMAN_H_
#define HUMAN_H_

#include "Player.h"

class Human : public Player {
public:
    Human();
    ~Human() override;

    void makeRPSChoice() override;

};

#endif /* HUMAN_H_ */
