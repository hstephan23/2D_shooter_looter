#include "raylib.h"
#include "raymath.h"

#include "aiming.h"


Vector2 compute_aim_direction(const Vector2 player_position)
{
    return Vector2Normalize(Vector2Subtract(GetMousePosition(), player_position));
}

Vector2 compute_gun_position(const Vector2 player_position, const Vector2 aim_direction)
{
    return Vector2Add(player_position, Vector2Scale(aim_direction, 20.0f) );
}

Vector2 compute_muzzle_position(const Vector2 gun_position, const Vector2 aim_direction)
{
   return Vector2Add(gun_position, Vector2Scale(aim_direction, 5.0f));
}

