//
// Created by PC on 3/13/2024.
//

#ifndef INC_2O_RPG_PLAYER_H
#define INC_2O_RPG_PLAYER_H
#include "../Character/Character.h"
#include "../Enemy/Enemy.h"
#include "../Combat/Action.h"

struct Action;
class Enemy;

class Player:public Character {
protected:
    int experience;
    int level;
public:
    Player(string _name, int _health, int _attack, int _defense, int _speed);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;

    Character* getTarget(vector<Enemy*> enemies);

    void flee(vector<Enemy*> enemies);
    void levelUp();
    void gainExperience(int);

    Action takeAction(vector<Enemy*> enemies);

};

#endif //INC_2O_RPG_PLAYER_H
