
#include "raylib.h"

#include "monster.h"

#include <cmath>

#include "player.h"

void move_monster(Monster & monster, const Player &player, const float delta_time);

void move_grunt(Monster &grunt, const Player &player, const float delta_time)
{
    const float dx = player.position.x - grunt.position.x;
    const float dy = player.position.y - grunt.position.y;
    if (const float distance = sqrtf(dx * dx + dy * dy); distance <= 250.0f)
    {
        move_monster(grunt, player, delta_time);
    }
}

Monster create_grunt(const Vector2 position)
{
    return Monster {
        .position = position,
        .type = MonsterType::Grunt,
        .speed = 60.0f,
        .health = 30.0f
    };
}

void move_shooter(Monster & shooter, const Player &player, float delta_time)
{
    const float dx = player.position.x - shooter.position.x;
    const float dy = player.position.y - shooter.position.y;

    if (const float distance = sqrtf(dx * dx + dy * dy); distance <= 250.0f && distance >= 100.0f)
    {
        move_monster(shooter, player, delta_time);
    }
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

void move_monster(Monster & monster, const Player &player, const float delta_time)
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
