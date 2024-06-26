//
// Created by PC on 3/13/2024.
//

#include "Enemy.h"
#include <iostream>

using namespace std;

int getRolledAttack(int attack) {
    int lowerLimit = attack * .80;
    return (rand() % (attack - lowerLimit)) + lowerLimit;
}

Enemy::Enemy(char name[30], int health, int attack, int defense, int speed, int experience, int level) : Character(name, health, attack, defense, speed, false, experience, level) {
}

void Enemy::doAttack(Character *target) {
    int rolledAttack = getRolledAttack(getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    target->takeDamage(trueDamage);
}

void Enemy::takeDamage(int damage) {
    setHealth(getHealth() - damage);
    if(getHealth() <= 0) {
        cout<<"  "<<getName()<<" has died"<<endl;
    }
    else {
        cout<<"  "<<getName()<<" has taken " << damage << " damage" << endl;
    }
}

Character* Enemy::getTarget(vector<Player *> teamMembers) {
    //Quién tiene menos vida?
    int targetIndex = 0;
    int lowestHealth = INT_MAX;
    for(int i=0; i < teamMembers.size(); i++) {
        if(teamMembers[i]->getHealth() < lowestHealth) {
            lowestHealth = teamMembers[i]->getHealth();
            targetIndex = i;
        }
    }

    return teamMembers[targetIndex];
}

Action Enemy::takeAction(vector<Player *> player) {
    Action myAction;
    myAction.speed = getSpeed();
    myAction.subscriber = this;

    Character *target = getTarget(player);
    if (this->getHealth() < Max_Health &&rand() %100 < 100) {
        myAction.action = [this, target] {
            this->fleed = true;
        };
    } else{
        myAction.target = target;
        myAction.action = [this, target]() {
            doAttack(target);
        };
    };
    return myAction;
}

