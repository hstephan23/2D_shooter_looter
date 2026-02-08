#pragma once

#include <span>

#include "raylib.h"

#include "player.h"
#include "monster.h"
#include "bullet_system.h"

/**
 * @brief This is used to render the window and pieces inside the window
 *
 * This is might need broken up TODO - Break up function
 *
 * @param [in] bullets This is used to track the positions other details found in the Bullet struct
 * @param [in] monsters This tracks all the information about the monsters found in the Monster struct
 * @param [in] player This tracks the player stats, found in the Player struct
 * @param [in] gun_position This is a 2D vector that tracks where the gun is so the bullets can be displayed accordingly
 * @param [in] MAX_BULLETS This determines the max number of bullets that can be out at a time
 */
void render(std::span<Bullet> bullets,
            std::span<Monster> monsters,
            const Player& player,
            Vector2 gun_position,
            int MAX_BULLETS);