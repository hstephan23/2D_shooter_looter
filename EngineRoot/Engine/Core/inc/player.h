#pragma once

#include "raylib.h"


// TODO: These will change with power ups in the future

struct Player
{
    Vector2 position;
    float health;
    float bullet_speed;
    float bullet_damage;
    float fire_rate;
    float fire_cooldown;
};

void player_move(Player &player, float delta_time);