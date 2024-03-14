//
// Created by PC on 3/13/2024.
//

#ifndef INC_2O_RPG_PLAYER_H
#define INC_2O_RPG_PLAYER_H

#include "../Character/Character.h"
#inlcude "../Enemy/Enemy.h"
#include "../Combat/Action.h"

structAction;
class Enemy;

class Player:public Character {
protected:
    int experience;
    int level;
public:
    Player(string _name, int _health, int _attack, int _defense, int _speed);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Action takeAction(vactor<std::shared_ptr<Character>> possibleTargets) override;

    Character* getTarget(vector<Enemy*> enemies);

    bool flee(vector<Enemy*> enemies, vector, <Player*> teamMembers, vector<Character*> participants);
    void emote();
    void levelUp();
    void gainExperience(int);

    Action takeAction(vector<Enemy*> enemies);

};
