#include "raylib.h"

#include "player.h"

void player_move(Player &player, const float delta_time, const float speed)
{
    if (IsKeyDown(KEY_W))
    {
        if (IsKeyDown(KEY_A))
        {
            player.position.x -= speed * delta_time;
            player.position.y -= speed * delta_time;
        } else if (IsKeyDown(KEY_D))
        {
            player.position.x += speed * delta_time;
            player.position.y -= speed * delta_time;
        } else
        {
            player.position.y -= speed * delta_time;
        }
    } else if (IsKeyDown(KEY_S))
    {
        if (IsKeyDown(KEY_A))
        {
            player.position.x -= speed * delta_time;
            player.position.y += speed * delta_time;
        } else if (IsKeyDown(KEY_D))
        {
            player.position.x += speed * delta_time;
            player.position.y += speed * delta_time;
        } else
        {
            player.position.y += speed * delta_time;
        } 
    } else if (IsKeyDown(KEY_D))
    {
        player.position.x += speed * delta_time;
    } else if (IsKeyDown(KEY_A))
    {
        player.position.x -= speed * delta_time;
    }
}

void player_dash(Player &player, const float delta_time)
{
    player.dash_cooldown -= delta_time;
    if (player.dash_cooldown < 0.0f) player.dash_cooldown = 0.0f;
    if (IsKeyPressed(KEY_SPACE) && player.dash_cooldown <= 0.0f)
    {
        player_move(player, delta_time, (player.speed * 35.0f));
        player.dash_cooldown = 2.0f;
    }
}