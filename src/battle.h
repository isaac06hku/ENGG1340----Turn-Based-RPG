#ifndef BATTLE_H
#define BATTLE_H

#include "core_types.h"
#include "player.h"
#include <array>


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
