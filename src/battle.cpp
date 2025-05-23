#include <iostream>
#include <random>
#include <algorithm>
#include "battle.h"
#include "utils.h"

using namespace std;

namespace {
    std::mt19937 rng(std::random_device{}());
    
    int roll_successes(int dice_count, double success_prob = 0.5) {
        std::binomial_distribution<int> dist(dice_count, success_prob);
        return dist(rng);
	}
}

//battle system that randomly initiate the battle 
bool BattleSystem::run_battle(BattleCharacter& player, BattleCharacter& enemy) {
    vector<string> attacks = {
        CombatText::ATTACK1,
        CombatText::ATTACK2,
        CombatText::ATTACK3
    };

    // Determine turn order
    std::cout << "\n";
    // output enemy counter message
    scrollText(enemy.name + " appears!", 50);
    //determine who acts first by speed
    bool player_first = (player.stats.speed >= enemy.stats.speed);
    //minus hp by damage if roll successful
    auto take_turn = [&attacks](BattleCharacter& attacker, BattleCharacter& defender) {
        int damage = roll_successes(
            std::max(1, attacker.stats.attack - defender.stats.armour)
        );

	
        defender.current_hp -= damage;
	//output the damage message
        if (attacker.name == "Player") {
            int randomIndex = randint(0, 2);
            scrollText(attacks[randomIndex], 50);
            scrollText(defender.name + " took " + to_string(damage) + " damage!", 50);
        } else {
            scrollText("You took " + to_string(damage) + " damage!", 50);
        }

        std::cout << "\n";
        return damage;
    };

    // If player are the First to move
    if (player_first) {
        int damage = take_turn(player, enemy);
        if (enemy.current_hp <= 0) return true;
        std::cout << "\n";
        print_battle_status(player, enemy);
        std::cout << "\n";

    } else {
        int damage = take_turn(enemy, player);
        if (player.current_hp <= 0) return false;
        std::cout << "\n";
        print_battle_status(player, enemy);
        std::cout << "\n";
    }

    // Subsequent turns
    while (true) {
        int damage = take_turn(player, enemy);
        std::cout << "\n";
        if (enemy.current_hp <= 0) return true;
        
        damage = take_turn(enemy, player);
        std::cout << "\n";
        if (player.current_hp <= 0) return false;

        print_battle_status(player, enemy);
        std::cout << "\n";
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

BattleCharacter to_battle_character(const Player& player) {
    CharacterStats total = player.get_total_stats();
    return BattleCharacter(
        player.name,
        total,
        total.health
    );
}
