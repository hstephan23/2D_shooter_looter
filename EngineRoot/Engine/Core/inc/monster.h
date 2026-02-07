#pragma once

#include "raylib.h"

#include "player.h"

enum class MonsterType
{
    Grunt,
    Shooter,
    Dasher,
    Turret
};

struct Monster
{
    Vector2 position;
    MonsterType type;
    float speed;
    float health;
};

void move_grunt(Monster &grunt, const Player &player, float delta_time);
Monster create_grunt(Vector2 position);
void move_shooter(Monster &shooter, const Player &player, float delta_time);
Monster create_shooter(Vector2 position);