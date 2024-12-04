#ifndef WARCRAFTKEYCOUNTVISUALISER_PLAYER_H
#define WARCRAFTKEYCOUNTVISUALISER_PLAYER_H

#include <string>

enum PlayerRole {
    PlayerRole_Invalid,
    PlayerRole_Tank,
    PlayerRole_Healer,
    PlayerRole_Damage,
};

std::string RoleToString(const PlayerRole role) {
    std::string roleString = "MISSING ROLE";
    switch (role)
    {
        case PlayerRole_Invalid:
            roleString = "Invalid";
            break;
        case PlayerRole_Tank:
            roleString = "Tank";
            break;
        case PlayerRole_Healer:
            roleString = "Healer";
            break;
        case PlayerRole_Damage:
            roleString = "Damage";
            break;
    }

    return roleString;
}

PlayerRole StringToRole(const std::string& roleString) {
    static const std::unordered_map<std::string, PlayerRole> roleMap = {
            {"TANK", PlayerRole_Tank},
            {"HEALER", PlayerRole_Healer},
            {"DAMAGER", PlayerRole_Damage},
    };

    auto it = roleMap.find(roleString);
    return (it != roleMap.end()) ? it->second : PlayerRole_Invalid;
}

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

std::string ClassToString(const PlayerClass role) {
    std::string roleString = "MISSING ROLE";
    switch (role)
    {
        case PlayerClass_Invalid:
            roleString = "Invalid";
            break;
        case PlayerClass_DeathKnight:
            roleString = "Death Knight";
            break;
        case PlayerClass_DemonHunter:
            roleString = "DemonHunter";
            break;
        case PlayerClass_Druid:
            roleString = "Druid";
            break;
        case PlayerClass_Evoker:
            roleString = "Evoker";
            break;
        case PlayerClass_Hunter:
            roleString = "Hunter";
            break;
        case PlayerClass_Mage:
            roleString = "Mage";
            break;
        case PlayerClass_Monk:
            roleString = "Monk";
            break;
        case PlayerClass_Paladin:
            roleString = "Paladin";
            break;
        case PlayerClass_Priest:
            roleString = "Priest";
            break;
        case PlayerClass_Rouge:
            roleString = "Rogue";
            break;
        case PlayerClass_Shaman:
            roleString = "Shaman";
            break;
        case PlayerClass_Warlock:
            roleString = "Warlock";
            break;
        case PlayerClass_Warrior:
            roleString = "Warrior";
            break;
    }

    return roleString;
}

PlayerClass StringToClass(const std::string& classString) {
    static const std::unordered_map<std::string, PlayerClass> classMap = {
            {"Death Knight", PlayerClass_DeathKnight},
            {"Demon Hunter", PlayerClass_DemonHunter},
            {"Druid", PlayerClass_Druid},
            {"Evoker", PlayerClass_Evoker},
            {"Hunter", PlayerClass_Hunter},
            {"Mage", PlayerClass_Mage},
            {"Monk", PlayerClass_Monk},
            {"Paladin", PlayerClass_Paladin},
            {"Priest", PlayerClass_Priest},
            {"Rogue", PlayerClass_Rouge},
            {"Shaman", PlayerClass_Shaman},
            {"Warlock", PlayerClass_Warlock},
            {"Warrior", PlayerClass_Warrior},
    };

    auto it = classMap.find(classString);
    return (it != classMap.end()) ? it->second : PlayerClass_Invalid;
}

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
        os << "    " << player.Name <<
        "\n    {\n" <<
        "       Role: " << RoleToString(player.Role) << "\n" <<
        "       Class: " << ClassToString(player.Class) << "\n" <<
        "       Deaths: " << player.Deaths << "\n" <<
        "       Total Damage: " << player.TotalDamage << "\n" <<
        "       DPS: " << player.DamagePerSecond << "\n" <<
        "       Total Healing: " << player.TotalHealing << "\n" <<
        "       HPS: " << player.HealingPerSecond << "\n" <<
        "    }";
        return os;
    }
};

#endif //WARCRAFTKEYCOUNTVISUALISER_PLAYER_H
