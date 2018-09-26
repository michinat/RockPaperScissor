/*
 * Player.h
 *
 *  Created on: Sep 25, 2018
 *      Author: michellenatasha
 */

#ifndef PLAYER_H_
#define PLAYER_H_

typedef enum {
	ROCK = 0,
	PAPER,
	SCISSOR
} selection_t;

class Player {
protected:
	selection_t RPS;
public:
	Player();
	virtual ~Player();

	selection_t getRPS();
	void setRPS(selection_t type);
	virtual void makeRPSChoice() = 0;
};

#endif /* PLAYER_H_ */
