//
// Created by PC on 3/13/2024.
//

#ifndef INC_2O_RPG_COMBAT_H
#define INC_2O_RPG_COMBAT_H
#pragma once
#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"
#include "Action.h"
#include <Combat.h>
#include <vector>
#include <string>
#include <queue>

using namespace std;
class Enemy;
class Player;

class Combat {
private:
    vector<Character*> participants;
    vector<Player*> teamMembers;
    vector<Enemy*> enemies;
    priority_queue<Action> actions;

    void prepareCombat();
    Character* getTarget(Character* target);
    void registerActions();
    void executeActions();

    void checkParticipantStatus(Character* participant);
    void checkForFlee(Character* character);

public:
    Combat(vector<Character*> _participants);
    Combat(vector<Player*> _teamMembers, vector<Enemy*> _enemies);
    Combat();
    void addParticipant(Character *participant);
    void doCombat();
    string participantsToString();
};

#endif //INC_2O_RPG_COMBAT_H