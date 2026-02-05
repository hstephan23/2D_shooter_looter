#include <span>
#include "raylib.h"

#include "rendering.h"
#include "bullet_system.h"

void render(std::span<Bullet> bullets, Vector2 player_position, Vector2 gun_position, int max_bullets)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawFPS(10,10);

    DrawCircleV(player_position, 20, RED);
    DrawCircleV(gun_position, 5, BLACK);
    for (const auto & bullet : bullets)
        if (bullet.active) DrawCircleV(bullet.position, 3, GREEN);

    const auto active_num_bullets = count_active_bullets(bullets, max_bullets);

    DrawText(TextFormat("Bullets Remaining: %d", active_num_bullets), 10, 30, 20, BLACK);

    EndDrawing();
}
