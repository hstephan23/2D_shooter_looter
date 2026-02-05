#pragma once
#include "raylib.h"

Vector2 compute_aim_direction(Vector2 player_position);
Vector2 compute_gun_position(Vector2 player_position, Vector2 aim_direction);
Vector2 compute_muzzle_position(Vector2 gun_position, Vector2 aim_direction);

