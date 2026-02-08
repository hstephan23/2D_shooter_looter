#pragma once

#include "raylib.h"


/**
 * @struct Player
 * @brief the necessary information to create a new player
 */
struct Player
{
    /** a 2D vector of where the player is in the window */
    Vector2 position;
    /** the speed at which bullets travel
     * TODO - imagining a new system where this can be increased/decreased depending on gun  */
    float bullet_speed;
    /** the damage at which bullets inflict
     * TODO - imagining powerups that change this*/
    float bullet_damage;
    /** the rate at which a player can fire their gun
     * TODO - imagining powerups that increase this */
    float fire_rate;
    /** the amount of time between shots
     * TODO - imagining powerups that decrease and different amounts depending on the weapon */
    float fire_cooldown;
    /** the amount of time between dashes */
    float dash_cooldown;
    /** the general speed of the user
     * TODO - imagining powerups the increase this
     */
    float speed;
    /** the amount of hearts a user has (3 to start)
     * TODO - powerup that can increase the number of lifes one has
     */
    int hearts;
};

/**
 * @brief the way that a player moves
 *
 * @param [in] player this is used to pull the current position
 * @param [out] player this is updated with the new position
 * @param [in] delta_time the time since the last frame was drawn
 * @param [in] speed the player moves (we want this separate for dashes)
 */
void player_move(Player &player, float delta_time, float speed);

/**
 * @brief the ability for a player to dash
 *
 * @param [in] player is used for the initial position and the initial speed
 * @param [out] player is updated with the new position
 * @param [in] delta_time is the time since the last frame was drawn
 */
void player_dash(Player &player, float delta_time);