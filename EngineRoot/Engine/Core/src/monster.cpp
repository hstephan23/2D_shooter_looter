#include <cmath>
#include <random>

#include "raylib.h"

#include "monster.h"
#include "player.h"

/** @brief move the monster towards character
 *
 * This is pulled out for reuse
 *
 * @param [in] monster the information of the monster type and speed
 * @param [out] monster the updated position of the monster
 * @param [in] player the position of the player
 * @param [in] delta_time the time since the last frame was drawn
 */
void move(Monster &monster, const Player &player, const float delta_time);

void move_monster(Monster &monster, const Player &player, const float delta_time)
{
    const float dx = player.position.x - monster.position.x;
    const float dy = player.position.y - monster.position.y;
    const float distance = sqrtf(dx * dx + dy * dy);
    if (monster.type == MonsterType::Grunt)
    {
        if (distance <= 250.0f)
        {
            move(monster, player, delta_time);
        }
    } else if (monster.type == MonsterType::Shooter)
    {
        if (distance >= 100.0f && distance <= 250.0f)
        {
            move(monster, player, delta_time);
        }
    } else if (monster.type == MonsterType::Dasher)
    {
        if (distance <= 300.0f)
        {
            move(monster, player, delta_time);
        }
    }
    // Turret DOES not move, so we don't need to add else if for it
}

Monster create_grunt(const Vector2 position)
{
    return Monster {
        .position = position,
        .type = MonsterType::Grunt,
        .speed = 50.0f,
        .health = 35.0f
    };
}

Monster create_shooter(const Vector2 position)
{
    return Monster {
        .position = position,
        .type = MonsterType::Shooter,
        .speed = 30.0f,
        .health = 45.0f
    };
}

Monster create_dasher(const Vector2 position)
{
    return Monster {
        .position = position,
        .type = MonsterType::Dasher,
        .speed = 80.0f,
        .health = 25.0f,
    };
}

Monster create_turret(const Vector2 position)
{
    return Monster {
        .position = position,
        .type = MonsterType::Turret,
        .speed = 0.0f,
        .health = 100.0f
    };
}

MonsterType random_monster_type()
{
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, static_cast<int>(MonsterType::COUNT) - 1);

    return static_cast<MonsterType>(dist(rng));
}

void move(Monster & monster, const Player &player, const float delta_time)
{

    if (monster.position.x <= player.position.x)
    {
        monster.position.x += monster.speed * delta_time;
    } else if (monster.position.x >= player.position.x)
    {
        monster.position.x -= monster.speed * delta_time;
    }

    if (monster.position.y <= player.position.y)
    {
        monster.position.y += monster.speed * delta_time;
    }else if (monster.position.y >= player.position.y)
    {
        monster.position.y -= monster.speed * delta_time;
    }
}
