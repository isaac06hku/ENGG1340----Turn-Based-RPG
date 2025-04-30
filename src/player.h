#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

// 物品结构体
struct Item {
    std::string name;
    int speed;
    int attack;
    int armour;
    int health;
};

// 玩家物品结构体
struct Player_item{
    std::string name;
    int speed;
    int attack;
    int armour;
    int health;
    std::vector<Item> inventory;
    Item* equipment[3];
};

struct total_statue{
    int total_Speed;
    int total_Attack;
    int total_Armour;
    int total_Health;
};

// 打印玩家状态的函数声明
void printPlayerStatus(const Player_item& player);

#endif    
