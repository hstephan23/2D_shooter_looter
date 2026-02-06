#pragma once

#include "raylib.h"


// TODO: These will change with power ups in the future

struct Player
{
    Vector2 position;
    float bullet_speed;
    float bullet_damage;
    float fire_rate;
    float fire_cooldown;
    float dash_cooldown;
    int health;
};

void player_move(Player &player, float delta_time, float speed);
void player_dash(Player &player, float delta_time);