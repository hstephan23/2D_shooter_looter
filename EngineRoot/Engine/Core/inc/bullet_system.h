#pragma once
#include <span>
#include "raylib.h"

#include "player.h"

struct Bullet
{
    Vector2 position;
    Vector2 velocity;
    float lifetime;
    bool active;
};

void spawn_bullet(
    std::span<Bullet> bullets,
    Player & player,
    Vector2 muzzle_position,
    Vector2 aim_direction,
    float delta_time
);
void update_bullets(std::span<Bullet> bullets, float delta_time);
int count_active_bullets(std::span<Bullet> bullets, int MAX_BULLETS);
