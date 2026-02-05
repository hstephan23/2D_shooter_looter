#pragma once

#include <span>

#include "raylib.h"

#include "bullet_system.h"

void render(std::span<Bullet> bullets, Vector2 player_position, Vector2 gun_position, int MAX_BULLETS);