#include "raylib.h"

#include "player.h"

void player_move(Player &player, const float delta_time)
{
    if (IsKeyDown(KEY_W))
    {
        if (IsKeyDown(KEY_A))
        {
            player.position.x -= 100.0f * delta_time;
            player.position.y -= 100.0f * delta_time;
        } else if (IsKeyDown(KEY_D))
        {
            player.position.x += 100.0f * delta_time;
            player.position.y -= 100.0f * delta_time;
        } else
        {
            player.position.y -= 100.0f * delta_time;
        }
    } else if (IsKeyDown(KEY_S))
    {
        if (IsKeyDown(KEY_A))
        {
            player.position.x -= 100.0f * delta_time;
            player.position.y += 100.0f * delta_time;
        } else if (IsKeyDown(KEY_D))
        {
            player.position.x += 100.0f * delta_time;
            player.position.y += 100.0f * delta_time;
        } else
        {
            player.position.y += 100.0f * delta_time;
        } 
    } else if (IsKeyDown(KEY_D))
    {
        player.position.x += 100.0f * delta_time;
    } else if (IsKeyDown(KEY_A))
    {
        player.position.x -= 100.0f * delta_time;
    }
}