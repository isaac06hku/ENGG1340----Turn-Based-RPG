#include <iostream>
#include "player.h"

CharacterStats Player::get_total_stats() const {
    CharacterStats total = base_stats;

    for (const Item* item : equipment) {
        if (item) {
            total.speed += item->modifiers.speed;
            total.attack += item->modifiers.attack;
            total.armour += item->modifiers.armour;
            total.health += item->modifiers.health;
        }
    }

    return total;
}

// printting player statue
void printPlayerStatus(const Player& player) {
    CharacterStats total = player.get_total_stats();

    std::cout << "Player name: " << player.name << std::endl;
    std::cout << "Total speed: " << total.speed << std::endl;
    std::cout << "Total attack: " << total.attack << std::endl;
    std::cout << "Total armour: " << total.armour << std::endl;
    std::cout << "Total health: " << total.health << std::endl;
}
