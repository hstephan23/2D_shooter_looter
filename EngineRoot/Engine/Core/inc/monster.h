#pragma once

#include "raylib.h"

#include "player.h"

enum class MonsterType
{
    Grunt,
    Shooter,
    Dasher,
    Turret,

    COUNT
};

struct Monster
{
    Vector2 position;
    MonsterType type;
    float speed;
    float health;
};

void move_monster(Monster &monster, const Player &player, float delta_time);

Monster create_grunt(Vector2 position);
Monster create_shooter(Vector2 position);
Monster create_dasher(Vector2 position);
Monster create_turret(Vector2 position);

MonsterType random_monster_type();