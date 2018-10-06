//
// Created by Linda Nguyen on 10/5/18.
//

#ifndef ROCKPAPERSCISSOR_SMARTSELECTION_H
#define ROCKPAPERSCISSOR_SMARTSELECTION_H

#include "Selection.h"
#include "Player.h"
#include "Referee.h"
#include <fstream>
#include <string>
#include "RandomSelection.h"

class SmartSelection : public Selection {
private:
    std::string trackPattern;
    std::string newPattern = "RSSSS";
    char prediction = '\0';
    int frequency = 0;
    bool matchFound = false;
    int counter=0;
    RandomSelection rs;


public:

    ~SmartSelection() override {
        delete this;
    }

    /// random selection [0, 2]
    selection_t makeSelection() override
    {
        std::ifstream rpsPatterns;
        std::ofstream insertPattern;
        rpsPatterns.open("rpsPatterns.txt");
        insertPattern.open("rpsPatterns.txt");

        counter++;

        if (counter++ < 3) {
            return rs.makeSelection();
        }
        else {
            if (!rpsPatterns)
                std::cout << "RPS Patterns file failed to open!\n";

            else {
                // Compare User's Pattern to History
                while (!matchFound) {
                    rpsPatterns >> trackPattern >> frequency;

                    if (newPattern == trackPattern) {
                        prediction = trackPattern[4];
                        matchFound = true;
                    }
                }

                // Insert New Pattern
                if (!matchFound) {
                    insertPattern << trackPattern << " " << frequency << '\n';
                }

                if (prediction != '\0') {
                    if (prediction == 'R') {
                        return PAPER;
                    } else if (prediction == 'P') {
                        return SCISSOR;
                    } else
                        return ROCK;
                }
            }

            rpsPatterns.close();
            insertPattern.close();
        }
    }
};


#endif //ROCKPAPERSCISSOR_SMARTSELECTION_H
