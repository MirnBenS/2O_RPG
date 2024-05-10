#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Combat/Combat.h"
#include <queue>

using namespace std;

int main() {
    Player *player = new Player("Luke", 60, 10, 2, 5);
    Enemy *enemy = new Enemy(" Jabba", 10, 11, 3, 11);
    Enemy *enemy2 = new Enemy(" Palpatine", 30, 8, 5, 2);

    vector<Character*> participants;
    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);

    Combat* combat = new Combat(participants);
    combat->doCombat();


    delete player;
    delete enemy;
    delete enemy2;
    delete combat;

    return 0;
}