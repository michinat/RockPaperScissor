/**
 * RPS selection file
 * Defines RPS types and helper functions
*/

#ifndef RPS1_RPS_TYPE_H
#define RPS1_RPS_TYPE_H

#include <iostream>
#include <vector>
#include <fstream>

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

// global rps log of all rounds
extern std::vector<char> rps;

// RPS to char helper function
static char convertRPStoChar(selection_t rps) {

    if (rps == selection_t::ROCK) {
        return 'R';
    } else if (rps == selection_t::PAPER) {
        return 'P';
    } else if (rps == selection_t::SCISSOR) {
        return 'S';
    }
    // return invalid
    return 'I';
}

// when rps vector size >= 5; store last 5 occurrences as new entry, or increase frequency of found entry
// EX: RPRPS 1       (new entry)
// EX: RPRPS 4 -> 5  (found entry)
/// WARNING: rps must be >= 5 in length
// TODO: remove past entries
static void pushRPSLog() {
    std::ifstream in("rpsPattern.txt");
    std::ofstream out("rpsPattern.txt", std::ios_base::app | std::ios_base::out);
    if (in.fail() || out.fail() || rps.size() < 5) {
        return;
    }
    std::string entry;
    std::string temp;
    int frequency;

    // set entry of last 5 entered
    for (unsigned long long int i = (rps.size()-5); i < rps.size(); i++) {
        entry += rps.at(i);
    }

    while (in >> temp >> frequency) {
        // found a hit
        if (entry == temp) {
            out << entry << ' ' << (frequency+1) << std::endl;
            in.close();
            out.close();
            return;
        }
    }

    // no entry found? insert new entry
    out << entry << ' ' << 1 << std::endl;

    in.close();
    out.close();
}

#endif //RPS1_RPS_TYPE_H
