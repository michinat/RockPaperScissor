/**
 * Human subclass implementation
 *
 */

#include "Human.h"

Human::Human(humanInput_t mode) {
    setName("Human");
    if (mode == Human::COMMAND_LINE)
        selection = new CommandLineSelection();
}

Human::~Human() {
    delete this;
}
