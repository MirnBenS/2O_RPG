//
// Created by PC on 3/13/2024.
//
#ifndef INC_2O_RPG_CHARACTER_H
#define INC_2O_RPG_CHARACTER_H
#include <string>
#include <vector>
#include "../Combat/Action.h"

using namespace std;

class Character {
protected:
    char name[30];
    int health;
    int attack;
    int defense;
    int speed;
    bool isPlayer;
    bool fleed;
    //int experience;
    //int level;
    //int max_health;

public:
    Character(char*, int, int, int, int, bool);

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;

    void setName(char[30]);
    char* getName();
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
    bool hasFleed();
};

#endif //INC_2O_RPG_CHARACTER_H
