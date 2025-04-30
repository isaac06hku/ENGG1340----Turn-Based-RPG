#include <iostream>
#include <random>
#include <algorithm>
#include "player.h"
#include "battle.h"

using namespace std;

namespace {
    std::mt19937 rng(std::random_device{}());
    
    int roll_successes(int dice_count, double success_prob = 0.5) {
        std::binomial_distribution<int> dist(dice_count, success_prob);
        return dist(rng);
	}
}


bool BattleSystem::run_battle(BattleCharacter& player, BattleCharacter& enemy) {
    // Determine turn order
    bool player_first = (player.stats.speed >= enemy.stats.speed);
    
    auto take_turn = [](BattleCharacter& attacker, BattleCharacter& defender) {
        int damage = roll_successes(
            std::max(1, attacker.stats.attack - defender.stats.armour)
        );
        defender.current_hp -= damage;
        return damage;
    };

    // First turn
    if (player_first) {
        int damage = take_turn(player, enemy);
        if (enemy.current_hp <= 0) return true;
    } else {
        int damage = take_turn(enemy, player);
        if (player.current_hp <= 0) return false;
    }

    // Subsequent turns
    while (true) {
        int damage = take_turn(player, enemy);
        if (enemy.current_hp <= 0) return true;
        
        damage = take_turn(enemy, player);
        if (player.current_hp <= 0) return false;
    }
}

void BattleSystem::print_battle_status(const BattleCharacter& player, const BattleCharacter& enemy) {
    std::cout << "=== BATTLE STATUS ===\n"
              << player.name << ":\n"
              << "  Health: " << player.current_hp << "/" << player.stats.health << "\n"
              << "  Attack: " << player.stats.attack << "\n"
              << enemy.name << ":\n"
              << "  Health: " << enemy.current_hp << "/" << enemy.stats.health << "\n"
              << "  Attack: " << enemy.stats.attack << std::endl;
}