//
// Created by PC on 3/13/2024.
//
#ifndef INC_2O_RPG_CHARACTER_H
#define INC_2O_RPG_CHARACTER_H
#include <string>
#include "../Combat/Action.h"
#include <cstring>
#include <vector>

using namespace std;

class Character {
public:
    char name[30];
    int attack;
    int defense;
    int speed;
    bool isPlayer;
    bool fleed;
    int health;
    int experience;
    int level;

public:
    Character(char[30], int, int, int, int, bool, int, int);

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
    int getExperience();
    int getLevel();


};

#endif //INC_2O_RPG_CHARACTER_H
