#include "raylib.h"
#include <span>
#include <array>

#include "startup.h"

#include "player.h"
#include "aiming.h"
#include "bullet_system.h"
#include "rendering.h"

void startup()
{
    InitWindow(800, 600, "Game_Engine");
    constexpr int MAX_BULLETS = 12;
    std::array<Bullet, MAX_BULLETS> bullets = {};
    Player player = {
        .position = Vector2{400, 300},
        .health = 100.0f,
        .bullet_speed = 150.0f,
        .bullet_damage = 10.0f,
        .fire_rate = 6.0f,
        .fire_cooldown = 0.0f,
    };
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ESCAPE)) break;

        const auto aim_direction = compute_aim_direction(player.position);
        const auto gun_position = compute_gun_position(player.position, aim_direction);
        const auto muzzle_position = compute_muzzle_position(gun_position, aim_direction);

        const float delta_time = GetFrameTime();

        // This controls auto-fire as well (just hold left-click on the mouse)
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            spawn_bullet(
               bullets,
               player,
               muzzle_position,
               aim_direction,
               delta_time
           );
        }
        player_move(player, delta_time);

        update_bullets(bullets, delta_time);
        render(bullets, player.position, gun_position, MAX_BULLETS);
    }

    CloseWindow();
}
