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
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Combat {
private:
    vector<Character*> participants;
    vector<Player*> teamMembers;
    vector<Enemy*> enemies;
    //Priority queue de acciones
    priority_queue<Action> actions;

    void prepareCombat();
    Character* getTarget(Character* target);
public:
    Combat(vector<Character*> _participants);
    Combat(vector<Player*> _teamMembers, vector<Enemy*> _enemies);
    Combat();
    void addParticipant(Character *participant);
    void doCombat();
    string participantsToString();
};