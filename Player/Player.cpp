//
// Created by PC on 3/13/2024.
//

#include "Player.h"
#include <iostream>
#include "../Utils.h"

bool compareSpeed(Enemy *a, Enemy *b){
    return a->getSpeed() > b->getSpeed();
}

Player::Player(string name, int health, int attack, int defense, int speed) : Character(name, health, attack, defense, speed, true) {
    experience = 0;
    level = 1;
}

void Player::doAttack(Character *target){
    int rolledAttack = getRolledAttack(attack: getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    target->takeDamage(damage: trueDamage)
}

void Player::takeDamage(int damage) {
    setHealth(health - damage);
    cout<<"You have taken " << damage << " damage" << endl;
    if(health <= 0){
        cout<<"You have died"<<endl;
    }
}
bool Player::flee(vector<Enemy*> enemies){
    std::sort(first: enemies begin(), last: enemies.end(), comp: compareSpeed);
    Enemy* fastestEnemy = enemies[0];
    bool fleed = false;
    if(this->getSpeed() >fastestEnemy->getSpeed()){
        fleed = true;
    }
    else{
        srand(time(NULL));
        int chance = rand() %100;
        cout<< "chance: " << chance << endl;
        fleed = chance > 99;
    }
    hasFleed = fleed;

    return fleed;
}
    if(fleed){

    }
void Player::emote() {
        cout<<"Jokes on you"<<endl;
    }


void Player::gainExperience(int exp) {
        experience +=exp;
        if (experience >= 100){
            levelUp();
            experience = 0;
        }
}

Character* Player::getTarget(vector<Enemy *>enemies) {
        cout<< "Choose a target" <<endl;
        int targetIndex = 0;
        for(int i = 0; i < enemies.size(); i++){
            cout<< i << "." << enemies[i]->getName() <<endl;
        }
        cin >> targetIndex;

        return enemies[targetIndex];
    }

Action Player::takeAction(vector<std::shared_ptr<Character>> possibleTargets) {
        int option = 0;
        cout<<"Choose an action."<<endl;
        cout<<"1. Attack"<<endl;
        cin >> option;
        Character* target = nullptr;


        Action myAction;
        myAction.speed = getSpeed();

        switch(option){
            case 1:
                target = getTarget(enemies: enemies);
                myAction.action=[this, target]()->void{
                    doAttack(target);
                };
                break;
            default:
                cout<<"Invalid option."<<endl;
                break;
        }
        return myAction;
    }

Action Player::takeAction(vector<Enemy*>enemies){
        int option = 0;
        cout<<"Choose an action:"<<endl;
        cout<<"1. Attck"<<endl;
        cin>>option;
        Character* target = nullptr;

        Action myAction;
        myAction.speed = this->getSpeed();

        switch(option){
            case 1:
                target = getTarget(enemies);
                myAction.action = [this, target]()->void{
                    doAttack(target);
                };
                break;
            case 2:
                myAction.action=[]
            default:
                cout<<"Invalid option"<<endl;
                break;
        }

        return myAction;
    }

