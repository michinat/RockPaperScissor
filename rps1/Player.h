/**
 * Player.h
 *
 * Interface file for RPS players
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "RPS_type.h"

class Player {
private:
    selection_t RPS;
    std::string name;

protected:
    void setRPS(selection_t type);
    void setName(std::string in);

public:
    Player();
    virtual ~Player();

    selection_t getRPS();
    std::string getName();
    virtual void makeRPSChoice() = 0;

};

#endif /* PLAYER_H_ */
