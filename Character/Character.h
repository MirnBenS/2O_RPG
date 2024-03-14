//
// Created by PC on 3/13/2024.
//

#ifndef INC_2O_RPG_CHARACTER_H
#define INC_2O_RPG_CHARACTER_H
#include <string>
#include "../Combat/Action.h"

using namespace std;

class Character {
protected:
    string name;
    int health;
    int attack;
    int defense;
    int speed;
    bool isPlayer;
    bool hasFleed;

public:
    Character(string, int, int, int, int, bool);

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;

    void setName(string);
    string getName();
    void setHealth(int);
    int getHealth();
    void setAttack(int);
    int getAttack();
    void setDefense(int);
    int getDefense();
    void setSpeed(int);
    int getSpeed();
    string toString();
    bool getIsPlayer();

};

#endif //INC_2O_RPG_CHARACTER_H
