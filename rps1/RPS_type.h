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

// helper selection_t overloaded operator<<
static std::ostream & operator<<(std::ostream & out, selection_t rps) {

    if (rps == selection_t::ROCK) {
        out << "Rock";
    } else if (rps == selection_t::PAPER) {
        out << "Paper";
    } else if (rps == selection_t::SCISSOR) {
        out << "Scissor";
    } else if (rps == selection_t::INVALID) {
        out << "INVALID_INPUT";
    }

    return out;
}

#endif //RPS1_RPS_TYPE_H
