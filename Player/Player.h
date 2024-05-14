//
// Created by PC on 3/13/2024.
//

#ifndef INC_2O_RPG_PLAYER_H
#define INC_2O_RPG_PLAYER_H
#include "../Character/Character.h"
#include "../Enemy/Enemy.h"
#include "../Combat/Action.h"
#include <vector>

struct Action;
class Enemy;

class Player:public Character {

public:
    Player(char _name[30], int _health, int _attack, int _defense, int _speed, int _experience, int _level);

    void doAttack(Character *target) override;
    void takeDamage(int damage) override;

    Character* getTarget(vector<Enemy*> enemies);
    void flee(vector<Enemy*> enemies);
    void LevelUp();

    Action takeAction(vector<Enemy*> enemies);

/*private:
    char buffer[Player::BUFFER_SIZE];

    Player *unserialize(char *_buffer);*/
};

#endif //INC_2O_RPG_PLAYER_H
