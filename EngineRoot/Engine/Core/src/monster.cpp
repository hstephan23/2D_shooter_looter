
#include "raylib.h"

#include "monster.h"

#include <cmath>

#include "player.h"

void move_grunt(Monster &grunt, const Player &player, const float delta_time)
{
    const float dx = player.position.x - grunt.position.x;
    const float dy = player.position.y - grunt.position.y;
    if (const float distance = sqrtf(dx * dx + dy * dy); distance <= 250.0f)
    {
        if (grunt.position.x <= player.position.x)
        {
            grunt.position.x += grunt.speed * delta_time;
        } else if (grunt.position.x >= player.position.x)
        {
            grunt.position.x -= grunt.speed * delta_time;
        }

        if (grunt.position.y <= player.position.y)
        {
            grunt.position.y += grunt.speed * delta_time;
        }else if (grunt.position.y >= player.position.y)
        {
            grunt.position.y -= grunt.speed * delta_time;
        }
    }
}

Monster create_grunt(const Vector2 position)
{
    Monster grunt = {};
    grunt.position = position;
    grunt.type = MonsterType::Grunt;
    grunt.speed = 60.0f;
    grunt.health = 30.0f;
    return grunt;
}

