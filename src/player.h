#ifndef PLAYER_H
#define PLAYER_H

#include "core_types.h"
#include <string>
#include <vector>

// 玩家物品结构体
struct Player{
    std::string name;
    CharacterStats base_stats;
    std::vector<Item> inventory;
    Item* equipment[3];

    CharacterStats get_total_stats() const;

};

// 打印玩家状态的函数声明
void printPlayerStatus(const Player& player);

#endif    
