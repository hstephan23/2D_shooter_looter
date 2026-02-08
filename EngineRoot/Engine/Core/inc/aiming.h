#pragma once
#include "raylib.h"
/**
 * @brief this is used to calculate the aim direction of the mouse relative to the player position
 *
 * @param [in] player_position this is a 2D vector of where the player is position
 *
 * @return the 2D vector that indicates the direction of the mouse relative to the player
 */
Vector2 compute_aim_direction(Vector2 player_position);

/**
 * @brief determines the position of the gun relative to the player position using the aim_direction
 *
 * @param [in] player_position this is the 2D vector of the position of the player
 * @param [in] aim_direction this is the 2D vector of the aim direction found in compute_aim_direction
 *
 * @return the position where the gun belongs relative to player position and aim direction
 */
Vector2 compute_gun_position(Vector2 player_position, Vector2 aim_direction);

/**
 * @brief the position where the bullets need to come out of
 *
 * @param gun_position the position where the gun is (center of it)
 * @param aim_direction the direction that the user is pointer the cursor (mouse)
 * @param length_of_gun the length of half of the gun (so that you can determine from the center of the gun)
 *
 * @return the 2D vector of the position of the muzzle of the gun using gun_position and aim_direction
 */
Vector2 compute_muzzle_position(Vector2 gun_position, Vector2 aim_direction, float length_of_gun);

