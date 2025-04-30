#ifndef CORE_TYPES_H
#define CORE_TYPES_H
#include <string>

struct CharacterStats {
    int speed, attack, armour, health;
};

struct Item {
    std::string name;
    CharacterStats modifiers;
};

#endif