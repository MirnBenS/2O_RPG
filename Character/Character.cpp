//
// Created by PC on 3/13/2024.
//
#include "Character.h"
#include <cstring>
#include <iostream>

Character::Character(char _name[30], int _health, int _attack, int _defense, int _speed, bool _isPlayer, int _experience, int _level) {
    strcpy(name,_name);
    health = _health;
    attack = _attack;
    defense = _defense;
    speed = _speed;
    isPlayer = _isPlayer;
    fleed = false;
    experience = _experience;
    level= _level;
}

void Character::setName(char _name[30]) {
    strcpy (name, _name);
}

char* Character::getName() {
    return name;
}

void Character::setHealth(int _health) {
    health = _health;
}

int Character::getHealth() {
    return health;
}

void Character::setAttack(int _attack) {
    attack = _attack;
}

int Character::getAttack() {
    return attack;
}

void Character::setDefense(int _defense) {
    defense = _defense;
}

int Character::getDefense() {
    return defense;
}

void Character::setSpeed(int _speed) {
    speed = _speed;
}

int Character::getSpeed() {
    return speed;
}

string Character::toString() {
    cout << "\nName: " << name << "\nHealth: " + to_string(health) + "\nAttack: " + to_string(attack) + "\nDefense: " + to_string(defense) + "\nSpeed: " + to_string(speed);
}

bool Character::getIsPlayer() {
    return isPlayer;
}

bool Character::hasFleed() {
    return fleed;
}


int Character::getExperience(){
    return experience;
}

int Character::getLevel(){
    return level;
}
