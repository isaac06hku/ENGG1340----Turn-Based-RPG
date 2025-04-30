#include <iostream>
#include "player.h"

// printting player statue
void printPlayerStatus(const Player_item& player) {
    int totalSpeed = player.speed;
    int totalAttack = player.attack;
    int totalArmour = player.armour;
    int totalHealth = player.health;

    for (int i = 0; i < 3; ++i) {
        if (player.equipment[i] != nullptr) {
            totalSpeed += player.equipment[i]->speed;
            totalAttack += player.equipment[i]->attack;
            totalArmour += player.equipment[i]->armour;
            totalHealth += player.equipment[i]->health;
        }
    }

    std::cout << "Player name: " << player.name << std::endl;
    std::cout << "Total speed: " << totalSpeed << std::endl;
    std::cout << "Total attack: " << totalAttack << std::endl;
    std::cout << "Total armour: " << totalArmour << std::endl;
    std::cout << "Total health: " << totalHealth << std::endl;
}

extern Player_item player;
