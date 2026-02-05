#pragma once

#include "raylib.h"


// TODO: These will change with power ups in the future
// TODO: Should we move the player on the existing map? Or move the map behind them??

struct Player
{
    Vector2 position;
    float health;
    float bullet_speed;
    float bullet_damage;
    float fire_rate;
    float fire_cooldown;
};