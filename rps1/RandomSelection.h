//
// Created by drnuc on 9/26/2018.
//

#ifndef RPS1_RANDOMSELECTION_H
#define RPS1_RANDOMSELECTION_H

#include "Selection.h"
#include <random>

class RandomSelection : public Selection {
private:
    std::mt19937 rng;

public:
    RandomSelection() {
        rng.seed(std::random_device()());
    }

    ~RandomSelection() {
        delete this;
    }

    /// random selection [0, 2]
    selection_t makeSelection() override {
        std::uniform_int_distribution<std::mt19937::result_type> dist(0,2);
        return (selection_t)dist(rng);
    }

};

#endif //RPS1_RANDOMSELECTION_H
