//
// Created by PC on 3/13/2024.
//

#include "Combat.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool compareSpeed(Character *a, Character *b) {
    return a->getSpeed() > b->getSpeed();
}

Combat::Combat(vector<Character *> _participants) {
    participants = std::move(_participants);
    for(auto participant: participants) {
        if(participant->getIsPlayer()) {
            teamMembers.push_back((Player*)participant);
        }
        else {
            enemies.push_back((Enemy*)participant);
        }
    }
}

Combat::Combat(vector<Player*> _teamMembers, vector<Enemy*> _enemies) {
    teamMembers = std::move(_teamMembers);
    enemies = std::move(_enemies);
}

Combat::Combat() {
    participants = vector<Character*>();
}

void Combat::addParticipant(Character *participant) {
    participants.push_back(participant);
    if(participant->getIsPlayer()) {
        teamMembers.push_back((Player*)participant);
    }
    else {
        enemies.push_back((Enemy*)participant);
    }
}

void Combat::prepareCombat() {
    sort(participants.begin(), participants.end(), compareSpeed);
}

void Combat::doCombat() {
    prepareCombat();

    while(enemies.size() != 0 && teamMembers.size() != 0) {
        registerActions();
        executeActions();
    }
    //WHO WIN?
    if(enemies.size() == 0) {
        cout<<" You have won the combat!"<<endl;
        cout<<" This match... I think I've learned something from this. You're nothing."<<endl;
    }
    else {
        cout<<" The enemies have won the combat\n  --------Game Over--------"<<endl;
    }
}

void Combat::registerActions() {
    vector<Character*>::iterator participant = participants.begin();
    while(participant != participants.end()) {
        Character* target = nullptr;
        Action currentAction;
        if((*participant)->getIsPlayer()) {
            currentAction = ((Player*)*participant)->takeAction(enemies);
        }
        else {
            currentAction = ((Enemy*)*participant)->takeAction(teamMembers);
        }
        actions.push(currentAction);
        participant++;
    }
}

void Combat::executeActions() {
    //Aqui se ejecutan las acciones
    while(!actions.empty()) {
        Action currentAction = actions.top();
        currentAction.action();
        checkForFlee(currentAction.subscriber);
        checkParticipantStatus(currentAction.subscriber);
        checkParticipantStatus(currentAction.target);
        actions.pop();
    }
}

void Combat::checkParticipantStatus(Character* participant) {
    if(participant != nullptr && participant->getHealth() <= 0) {
        if(participant->getIsPlayer()) {
            teamMembers.erase(remove(teamMembers.begin(), teamMembers.end(), participant), teamMembers.end());
        }
        else {
            enemies.erase(remove(enemies.begin(), enemies.end(), participant), enemies.end());
        }
        participants.erase(remove(participants.begin(), participants.end(), participant), participants.end());
    }
}

void Combat::checkForFlee(Character *character) {
    bool fleed = character->hasFleed();
    if(fleed) {
        if(character->getIsPlayer()) {
            cout<<" You have fled the combat |COWARD|"<<endl;
            teamMembers.erase(remove(teamMembers.begin(), teamMembers.end(), character), teamMembers.end());
            //character->hasDied()
        }
        else {
            cout<<character->getName()<<" has fled the combat"<<endl;
            enemies.erase(remove(enemies.begin(), enemies.end(), character), enemies.end());
        }
        participants.erase(remove(participants.begin(), participants.end(), character), participants.end());
    }
}

string Combat::participantsToString() {
    string result = "";
    for (int i = 0; i < participants.size(); i++) {
        result += participants[i]->toString() + "\n";
    }
    return result;
}