#pragma once

#include <span>

#include "raylib.h"

#include "player.h"
#include "monster.h"
#include "bullet_system.h"

void render(std::span<Bullet> bullets,
    std::span<Monster> grunts,
    std::span<Monster> shooters,
    const Player& player,
    Vector2 gun_position,
    int MAX_BULLETS);