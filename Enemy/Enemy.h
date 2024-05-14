//
// Created by PC on 3/13/2024.
//

#ifndef INC_2O_RPG_ENEMY_H
#define INC_2O_RPG_ENEMY_H
#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../Combat/Action.h"

struct Action;
class Player;

class Enemy: public Character {
private:
    int experienceValue;
    vector<Enemy*> enemies;

public:
    int Max_Health;
    Enemy(char name[30], int, int, int, int, int, int );
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    void mostrarEstado ();
    void incrementarEstadisticas(int cantidad);
    Character* getTarget(vector<Player*> teamMembers);
    Action takeAction(vector<Player*> player);
    int getExperienceValue();

    const std::vector<Enemy*>& getEnemies() const {
        return enemies;
    }
};

#endif //INC_2O_RPG_ENEMY_H
