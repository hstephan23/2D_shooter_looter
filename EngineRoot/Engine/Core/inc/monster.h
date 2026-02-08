#pragma once

#include "raylib.h"

#include "player.h"

/**
 * @enum MonsterType
 * @brief the type of monster spawned in (different stats)
 *
 * The COUNT is used to measure the length for random placement
 */
enum class MonsterType
{
    /** speed = 50.0f, health = 35.0f*/
    Grunt,
    /** speed = 30.0f, health = 45.0f */
    Shooter,
    /** speed = 80.0f, health = 25.0f */
    Dasher,
    /** speed = N/A, health = 100.0f */
    Turret,

    COUNT
};

/**
 * @struct Monster
 * @brief the necessary information used to place and move monsters
 */
struct Monster
{
    /** 2D vector that has an x-axis  and a y-axis coordinate for where the monster is relative on the window */
    Vector2 position;
    /** the enum type that determines its stats*/
    MonsterType type;
    /** speed of the monster at which it moves*/
    float speed;
    /** the health of the monster, decremented by damage done through the player property damage*/
    float health;
};

/**
 * @brief this is the generic way that a monster moves on the map
 *
 * @param [in] monster the information necessary to determine current position
 * @param [out] monster the updated new position
 * @param [in] player the information about the player position
 * @param [in] delta_time time passed since the last frame was drawn
 */
void move_monster(Monster &monster, const Player &player, float delta_time);

/**
 * @brief the way to initialize the grunt and its capabilities
 *
 * @param position the spawn location (initial position will be random around the board)
 *
 * @return the created grunt used by the caller
 */
Monster create_grunt(Vector2 position);

/**
 * @brief the way to initialize the shooter and its capabilities
 *
 * @param position the spawn location (initial position will be random around the board)
 *
 * @return the created shooter used by the caller
 */
Monster create_shooter(Vector2 position);

/**
 * @brief the way to initialize the dasher and its capabilities
 *
 * @param position the spawn location (initial position, will be random around the board)
 *
 * @return the created dasher used by the caller
 */
Monster create_dasher(Vector2 position);

/**
 * @brief the way to initialize the turret and its capabilities
 *
 * @param position the spawn location (initial position, will be random around the board)
 *
 * @return the created turret used by the caller
 */
Monster create_turret(Vector2 position);

/**
 * @brief the random monster type chosen to spawn
 *
 * This allows for us to randomly spawn different kind of monsters
 *
 * @return the enum value that is used to determine what monster type is being created
 */
MonsterType random_monster_type();