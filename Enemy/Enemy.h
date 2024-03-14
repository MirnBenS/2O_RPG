//
// Created by PC on 3/13/2024.
//

#ifndef INC_2O_RPG_ENEMY_H
#define INC_2O_RPG_ENEMY_H
#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../Combat/Action.h"

struct Action;
class Player;

class Enemy: public Character {
public:
    Enemy(string, int, int, int, int);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Character* getTarget(vector<Player*> teamMembers);
    Action takeAction(vector<Player*> player);
};

#endif //INC_2O_RPG_ENEMY_H
