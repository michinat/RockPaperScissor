/**
 * RPS selection file
 * Defines RPS types
*/

#ifndef RPS1_RPS_TYPE_H
#define RPS1_RPS_TYPE_H

#include <iostream>

typedef enum {
    INVALID = -1,
    ROCK = 0,
    PAPER,
    SCISSOR
} selection_t;

/// istream helper function for selection_t
static std::istream &operator>>(std::istream & in, selection_t & type) {
    std::string hold;
    in >> hold;

    // lowercase input string
    for (char &i : hold) i = (char)std::tolower(i);

    if (hold == "rock") {
        type = selection_t::ROCK;
    } else if (hold == "paper") {
        type = selection_t::PAPER;
    } else if (hold == "scissor") {
        type = selection_t::SCISSOR;
    } else {
        type = selection_t::INVALID;
    }

    return in;
}

#endif //RPS1_RPS_TYPE_H
