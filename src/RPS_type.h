/**
 * CraZ CoderZ RPS
 * RPS selection file
 * Defines RPS types and helper functions
*/

#ifndef RPS1_RPS_TYPE_H
#define RPS1_RPS_TYPE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

typedef enum {
    INVALID = -1,
    ROCK = 0,
    PAPER,
    SCISSOR
} selection_t;

// helper selection_t to string
static inline std::string rpsToString(selection_t rps) {
    std::string s;
    if (rps == selection_t::ROCK) {
        s = "Rock";
    }
    else if (rps == selection_t::PAPER) {
        s = "Paper";
    }
    else if (rps == selection_t::SCISSOR) {
        s = "Scissor";
    }
    else if (rps == selection_t::INVALID) {
        s = "INVALID_INPUT";
    }
    return s;
}

// helper selection_t overloaded operator<<
static inline std::ostream & operator<<(std::ostream & out, selection_t rps) {

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
static inline char convertRPStoChar(selection_t rps) {

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
static void pushRPSLog() {
    std::ifstream in("rpsPattern.txt");
    std::vector<std::string> rpsLog;

    if (in.fail() || rps.size() < 5) {
        std::cout << "File failed to open\n";
        return;
    }

    bool foundEntry = false;
    // set entry of last 5 entered
    std::string entry(rps.end()-5, rps.end());
    std::string temp;
    int frequency;

    while (in >> temp >> frequency) {
        // found a hit
        if (entry == temp) {
            foundEntry = true;
            rpsLog.push_back(temp + ' ' + std::to_string(frequency+1));
        } else {
            rpsLog.push_back(temp + ' ' + std::to_string(frequency));
        }
    }

    // no entry found? insert new entry
    if (!foundEntry) rpsLog.push_back(entry + " 1");
    // sort rps log
    std::sort(rpsLog.begin(), rpsLog.end());

    std::ofstream out("rpsPattern.txt");
    if (out.fail()) return;
    // place sorted rps entry into rps log
    for (const auto &rpsEntry : rpsLog) out << rpsEntry << "\n";

    in.close();
    out.close();
}

extern selection_t predictedChoice;
static inline selection_t getPredictedChoice() { return predictedChoice; }

#endif //RPS1_RPS_TYPE_H
