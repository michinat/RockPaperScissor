/**
    CraZ CoderZ RPS
	Simple Machine Learning Selection subclass
*/

#ifndef ROCKPAPERSCISSOR_SMARTSELECTION_H
#define ROCKPAPERSCISSOR_SMARTSELECTION_H

#include "Selection.h"
#include <fstream>
#include <string>
#include "RandomSelection.h"
#include "RPS_type.h"

class SimpleMLSelection : public Selection {
private:
    // "has a" random selection algorithm
    RandomSelection rs;

public:
    SimpleMLSelection() = default;
    ~SimpleMLSelection() override = default;

    selection_t makeSelection() override {
        selection_t selection = INVALID;

        // make random selections for first 2 inputs + 2 including opponents input
        if (rps.size() < 4) {
            selection = rs.makeSelection();
        } else {
            std::ifstream rpsLog("rpsPattern.txt", std::ifstream::in);
            std::string trackPattern = "";
            std::string newPattern = "";
            char holdPrediction = 'I';
            char prediction = 'I';
            int frequency = 0;
            int maxFrequency = 0;
            bool matchFound = false;

            if (rpsLog.fail()) {
                std::cout << "RPS Patterns file failed to open!\n";
                selection = rs.makeSelection();
            } else {
                // set new pattern based on last 4 entries
                for (unsigned int i = (rps.size() - 4); i < rps.size(); i++) {
                    newPattern += rps.at(i);
                }

                // go through entire rpsPatterns file until end of file reached
                while (rpsLog >> trackPattern >> frequency) {
                    holdPrediction = trackPattern[4];
                    trackPattern.pop_back();
                    if (newPattern == trackPattern) {
                        // constantly set new prediction based on frequency
                        if (maxFrequency < frequency) {
                            maxFrequency = frequency;
                            prediction = holdPrediction;
                        }
                        matchFound = true;
                    }
                }
                rpsLog.close();

                // make random selection
                if (!matchFound) {
                    selection = rs.makeSelection();
                } else {
                    if (prediction == 'R') {
                        selection = PAPER;
                    } else if (prediction == 'P') {
                        selection = SCISSOR;
                    } else if (prediction == 'S') {
                        selection = ROCK;
                    } else if (prediction == 'I') {
//                        selection = INVALID;
                        selection = rs.makeSelection();
                    }
                }
            }
        }
        return selection;
    }
};


#endif //ROCKPAPERSCISSOR_SMARTSELECTION_H
