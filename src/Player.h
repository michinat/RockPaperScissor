/**
 * CraZ CoderZ RPS
 * base class file for RPS players
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "RPS_type.h"
#include "Selection.h"

class Player {
private:
    selection_t RPS;
    std::string name;

protected:
    Selection * selection;
    void setName(std::string in);

public:
    Player() = default;
    virtual ~Player() = default;

	void setRPS(selection_t type);
    selection_t getRPS();
    std::string getName();
    void makeRPSChoice();
};

#endif /* PLAYER_H_ */
