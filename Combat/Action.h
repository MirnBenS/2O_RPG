//
// Created by PC on 3/13/2024.
//

#ifndef INC_2O_RPG_ACTION_H
#define INC_2O_RPG_ACTION_H
#include <functional>
#include"../Character/Character.h"

class Character;

struct Action {
    int speed = 0;
    Character* subscriber = nullptr;
    Character* target = nullptr;
    std::function<void(void)> action = nullptr;

    Action(std::function<void(void)> _action, int _speed, Character* _subscriber, Character* _target) {
        action = _action;
        speed = _speed;
        subscriber = _subscriber;
        target = _target;
    }
    Action(){};

    bool operator<(const Action& p) const
    {
        return this->speed < p.speed;
    }
};

#endif //INC_2O_RPG_ACTION_H
