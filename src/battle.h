#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <string>
#include <random>
#include <ctime>


struct character_statue {
    std::string name;
    int speed;
    int attack;
    int armor;
    int health;
};


int roll(int number_dies);


void print_board(character_statue player, character_statue enemy, int current_health_player, int current_health_enemy);

// 战斗函数声明
bool battle(character_statue player, character_statue enemy);

#endif 
