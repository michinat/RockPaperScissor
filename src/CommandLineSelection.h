/**
 * CommandLineSelection subclass
 * Player is asked to input
*/

#ifndef RPS1_COMMANDLINESELECTION_H
#define RPS1_COMMANDLINESELECTION_H

#include "Selection.h"
#include <iostream>

/// overloaded istream helper function for selection_t
static std::istream & operator>>(std::istream & in, selection_t & type) {
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

class CommandLineSelection : public Selection {
public:
    CommandLineSelection() = default;
    ~CommandLineSelection() override = default;

    selection_t makeSelection() override {
        selection_t hold;
        std::cout << "Enter your selection: Rock, Paper, or Scissor\n";
        std::cin >> hold;
        return hold;
    }
};

#endif //RPS1_COMMANDLINESELECTION_H
