//
// Created by PC on 3/13/2024.
//

#include "Player.h"
#include <iostream>
#include "../Utils.h"
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
using namespace combat_utils;

bool compareSpeed(Enemy *a, Enemy *b) {
    return a->getSpeed() > b->getSpeed();
}

Player::Player(char name[30], int health, int attack, int defense, int speed) : Character(name, health, attack, defense,speed, true) {
    experience = 0;
    level = 1;
}
Player::Player(char* _name, int _health, int _attack, int _defense, int _speed, bool _isPlayer, int _experience, int _level): Character(_name, _health, _attack, _defense,
                                                                                                                                        _speed, _isPlayer) {
    experience = _experience;
    level = _level;
}

void Player::doAttack(Character *target) {
    int rolledAttack = getRolledAttack(getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    target->takeDamage(trueDamage);
}

void Player::takeDamage(int damage) {
    setHealth(health - damage);
    if (health <= 0) {
        cout << " > You have died :(" << endl;
    }
    else{
        cout << " > You have taken " << damage << " damage" << endl;
    }
}

void Player::flee(vector<Enemy *> enemies) {
    std::sort(enemies.begin(), enemies.end(), compareSpeed);
    Enemy *fastestEnemy = enemies[0];
    bool fleed = false;
    if (this->getSpeed() > fastestEnemy->getSpeed()) {
        fleed = true;
    } else {
        srand(time(NULL));
        int chance = rand() % 100;
        cout << " > chance: " << chance << endl;
        fleed = chance > 99;
    }

    this->fleed = fleed;
}

void Player::levelUp() {
    level++;
    setHealth(getHealth() + 10);
    setAttack(getAttack() + 5);
    setDefense(getDefense() + 5);
    setSpeed(getSpeed() + 5);
}

void Player::gainExperience(int exp) {
    experience += exp;
    if (experience >= 100) {
        levelUp();
        experience = 0;
    }
}

Character *Player::getTarget(vector<Enemy *> enemies) {
    cout << "\n ------------------------" << endl;
    cout << "   Choose a target:" << endl;
    int targetIndex = 0;
    for (int i = 0; i < enemies.size(); i++) {
        cout << "   " << i << ". " << enemies[i]->getName() << endl;
    }
    cin >> targetIndex;
    return enemies[targetIndex];
}

Action Player::takeAction(vector<Enemy *> enemies) {
    int option = 0;
    cout << "\n ------------------------" << endl;
    cout << "   Choose an action:" << endl;
    cout << "   1. Attack" << endl;
    cout << "   2. Flee" << endl;
    cin >>option;
    Character *target = nullptr;

    Action myAction;
    myAction.speed = this->getSpeed();
    myAction.subscriber = this;

    switch (option) {
        case 1:
            target = getTarget(enemies);
            myAction.target = target;
            myAction.action = [this, target]() {
                doAttack(target);
            };
            break;
        case 2:
            myAction.action = [this, enemies]() {
                flee(enemies);
            };
            break;
        default:
            cout << "   /Invalid option/" << endl;  //Aún imprime daño después
            break;
    }

    return myAction;
}

char* Player::serialize(){
    char* iterator = buffer;

    memcpy(iterator, &name, sizeof name);
    iterator += sizeof name;

    memcpy(iterator,&attack, sizeof attack);
    iterator += sizeof attack;

    memcpy(iterator, &health, sizeof health);
    iterator += sizeof health;

    memcpy(iterator, &defense, sizeof defense);
    iterator += sizeof defense;

    memcpy(iterator, &isPlayer, sizeof isPlayer);
    iterator += sizeof isPlayer;

    memcpy(iterator, &speed, sizeof speed);
    iterator += sizeof speed;

    memcpy(iterator, &experience, sizeof experience);
    iterator += sizeof experience;

    memcpy(iterator, &level, sizeof level);
    iterator+=sizeof level;

    memcpy(iterator, &experience, sizeof experience);
    iterator+=sizeof experience;

    }

    Player* Player::unserialize(char *_buffer){
        char* iterator = _buffer;
        char _name[30];
        int _health;
        int _attack;
        int _defense;
        int _speed;
        bool _isPlayer;
        int _experience;
        int _level;

        memcpy(&_name, iterator, sizeof _name);
        iterator += sizeof _name;

        memcpy(&_health, iterator, sizeof _health);
        iterator += sizeof _health;

        memcpy(&_attack, iterator, sizeof _attack);
        iterator += sizeof _attack;

        memcpy(&_defense, iterator, sizeof _defense);
        iterator += sizeof _defense;

        memcpy(&_speed, iterator, sizeof _speed);
        iterator += sizeof _speed;

        memcpy(&_isPlayer, iterator, sizeof _isPlayer);
        iterator += sizeof _isPlayer;

        memcpy(&_experience, iterator, sizeof _experience);
        iterator += sizeof _experience;

        memcpy(&_level, iterator, sizeof _level);
        iterator += sizeof _level;

        return new Player(_name,_health, _attack, _defense, _speed, _isPlayer, _experience, _level);
    }
    

