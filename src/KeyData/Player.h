#ifndef WARCRAFTKEYCOUNTVISUALISER_PLAYER_H
#define WARCRAFTKEYCOUNTVISUALISER_PLAYER_H

#include <string>

enum PlayerRole {
    PlayerRole_Invalid,
    PlayerRole_Tank,
    PlayerRole_Healer,
    PlayerRole_Damage,
};

enum PlayerClass {
    PlayerClass_Invalid,
    PlayerClass_DeathKnight,
    PlayerClass_DemonHunter,
    PlayerClass_Druid,
    PlayerClass_Evoker,
    PlayerClass_Hunter,
    PlayerClass_Mage,
    PlayerClass_Monk,
    PlayerClass_Paladin,
    PlayerClass_Priest,
    PlayerClass_Rouge,
    PlayerClass_Shaman,
    PlayerClass_Warlock,
    PlayerClass_Warrior,
};

struct Player {
    std::string Name;
    PlayerRole Role = PlayerRole_Invalid;
    PlayerClass Class = PlayerClass_Invalid;
    int32_t Deaths;
    int32_t TotalDamage;
    int32_t DamagePerSecond;
    int32_t TotalHealing;
    int32_t HealingPerSecond;

    friend std::ostream& operator<<(std::ostream& os, const Player& player) {
        os << player.Name << "\n{\n" <<
           "   Role: " << "NONE" << "\n" <<
           "   Class: " << "NONE" << "\n" <<
           "   Deaths: " << player.Deaths << "\n" <<
           "   Total Damage: " << player.TotalDamage << "\n" <<
           "   DPS: " << player.DamagePerSecond << "\n" <<
           "   Total Healing: " << player.TotalHealing << "\n" <<
           "   HPS: " << player.HealingPerSecond << "\n" <<
           "}";
        return os;
    }
};

#endif //WARCRAFTKEYCOUNTVISUALISER_PLAYER_H
