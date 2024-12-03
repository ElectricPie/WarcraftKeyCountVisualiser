#ifndef WARCRAFTKEYCOUNTVISUALISER_PLAYER_H
#define WARCRAFTKEYCOUNTVISUALISER_PLAYER_H

#include <string>

enum PlayerRole {
    Tank,
    Healer,
    Damage,
};

enum PlayerClass {
    DeathKnight,
    DemonHunter,
    Druid,
    Evoker,
    Hunter,
    Mage,
    Monk,
    Paladin,
    Priest,
    Rouge,
    Shaman,
    Warlock,
    Warrior,
};

struct Player {
    std::string Name;
    PlayerRole Role;
    PlayerClass Class;
    int32_t deaths;
    int32_t DamagePerSecond;
    int32_t TotalDamage;
    int32_t HealingPerSecond;
    int32_t TotalHealing;
};

#endif //WARCRAFTKEYCOUNTVISUALISER_PLAYER_H
