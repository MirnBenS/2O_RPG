#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Combat/Combat.h"
#include <queue>

using namespace std;

int main() {
    Player *player = new Player("Luke", 50, 7, 2, 5,10,1);
    Enemy *enemy = new Enemy("Jabba", 15, 9, 2, 7,10,1);
    Enemy *enemy2 = new Enemy("Palpatine", 5, 5, 2, 7, 10,1);

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