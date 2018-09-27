/**
 * Human subclass header
 *
 */

#ifndef HUMAN_H_
#define HUMAN_H_

#include "Player.h"
#include "CommandLineSelection.h"

class Human : public Player {
public:

    // enum defines modes of selection
    typedef enum {
        COMMAND_LINE
    } humanInput_t;

    Human(humanInput_t mode);
    ~Human() override;

};

#endif /* HUMAN_H_ */
