//
// Created by PC on 3/13/2024.
//

#ifndef INC_2O_RPG_UTILS_H
#define INC_2O_RPG_UTILS_H
#include <cstdlib>

namespace combat_utils {
    int getRolledAttack(int attack) {
        srand(time(NULL));
        int lowerLimit = attack * .80;
        return (rand() % (attack - lowerLimit)) + lowerLimit;
    }
}

#endif //INC_2O_RPG_UTILS_H
