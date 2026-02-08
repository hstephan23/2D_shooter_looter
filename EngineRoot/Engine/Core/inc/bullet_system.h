#pragma once
#include <span>
#include "raylib.h"

#include "player.h"

/**
 * @struct Bullet
 * @brief struct that contains the necessary information about bullets
 */
struct Bullet
{
    /** 2D Vector that holds the position of the bullet*/
    Vector2 position;
    /** 2D Vector that stores the velocity of the y-axis and x-axis*/
    Vector2 velocity;
    /** the stored time that a bullet has left to be displayed*/
    float lifetime;
    /** TODO - Is this necessary? */
    /** whether the bullet slot is being used in the array */
    bool active;
};

/**
 * @brief the function that controls the spawning of a bullet when the left mouse button is pressed
 *
 * @param [in] bullets this gives information to as the bullet which can be used in the array
 * @param [out] bullets the position is updated based on the muzzle position
 * @param [in] player the stats about the bullet that can be fired by the player
 * @param [in] muzzle_position the position that the muzzle is at when the bullet is fired
 * @param [in] aim_direction the direction of the mouse so that the muzzle lines up with the bullet being fired
 * @param [in] delta_time for the change in time since the last frame was drawn see GetFrameTime()
 */
void spawn_bullet(
    std::span<Bullet> bullets,
    Player & player,
    Vector2 muzzle_position,
    Vector2 aim_direction,
    float delta_time
);

/**
 * @brief updating the bullet on each frame so that it moves smoothly
 *
 * @param [in] bullets this determines the initial details about the bullet
 * @param [out] bullets this is used to update the positions which are rendered later
 * @param [in] delta_time this measures the time since the last frame so that we can see how much the bullet should move depending on velocity of bullet
 */
void update_bullets(std::span<Bullet> bullets, float delta_time);

/**
 * @brief This gives a count of how many active bullets are on the window
 *
 * @param [in] bullets used for the active property to read if it is being used
 * @param [in] MAX_BULLETS the maximum total allowed
 *
 * @return the total number of bullets out between 0 and MAX_BULLETS
 */
int count_active_bullets(std::span<Bullet> bullets, int MAX_BULLETS);
