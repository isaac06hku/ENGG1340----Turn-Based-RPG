#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <string>
#include <random>
#include <ctime>


struct Player_item {
    std::string name;
    int speed;
    int attack;
    int armour;
    int health;
};


int roll(int number_dies);

total_statue calculating_total_statue(Player_item Player_item);

void print_board(Player_item player, Player_item enemy, int current_health_player, int current_health_enemy);

// 战斗函数声明
bool battle(Player_item player, Player_item enemy);

#endif 
