#ifndef BATTLE_H
#define BATTLE_H

#include "core_types.h"
#include "player.h"
#include <array>

namespace CombatText {
    const std::string ATTACK1 = "You strike with all your might!";
    const std::string ATTACK2 = "You swing your blade with precision!";
    const std::string ATTACK3 = "You seize the opening and attack!";
}


struct BattleCharacter {
    std::string name;
    CharacterStats stats;
    int current_hp;

    BattleCharacter(const std::string& name, const CharacterStats& stats, int health)
        : name(name), stats(stats), current_hp(health) {}

};

namespace BattleSystem {
    bool run_battle(BattleCharacter& player, BattleCharacter& enemy);
    void print_battle_status(const BattleCharacter& player, const BattleCharacter& enemy);
}

BattleCharacter to_battle_character(const Player& player);

#endif 
