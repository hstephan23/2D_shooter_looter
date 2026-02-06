#include <span>

#include "raylib.h"
#include "raymath.h"

#include "rendering.h"
#include "player.h"
#include "monster.h"
#include "bullet_system.h"

void render(
    const std::span<Bullet> bullets,
    const std::span<Monster> grunts,
    const Player& player,
    const Vector2 gun_position,
    const int MAX_BULLETS
)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawFPS(10,10);

    DrawCircleV(player.position, 20, RED);
    DrawCircleV(gun_position, 5, BLACK);

    for (const auto & bullet : bullets)
        if (bullet.active) DrawCircleV(bullet.position, 3, GREEN);

    DrawText(TextFormat("Lives: "), 10, 35, 20, BLACK);
    for (int i = 0; i < player.health; ++i) DrawCircle(20 + i * 25, 70, 10, RED);

    constexpr float dash_cooldown_max = 2.0f;
    constexpr int dash_bar_width = 100;
    float dash_ratio = player.dash_cooldown / dash_cooldown_max;
    if (dash_ratio < 0.0f) dash_ratio = 0.0f;
    if (dash_ratio > 1.0f) dash_ratio = 1.0f;

    DrawText(TextFormat("Dash Cooldown:"), 10, 110, 20, BLACK);
    DrawRectangle(170, 115, dash_bar_width, 15, LIGHTGRAY);
    DrawRectangle(170, 115, static_cast<int>(dash_ratio * dash_bar_width), 15, ORANGE);

    DrawText(TextFormat("Bullets Remaining: %d", count_active_bullets(bullets, MAX_BULLETS)), 10, 85, 20, BLACK);
    for (const auto & grunt: grunts)
    {
        DrawTriangle(Vector2Add(grunt.position, Vector2(25, 0)),
            Vector2Add(grunt.position, Vector2(0, 25)),
            Vector2Add(grunt.position, Vector2(25, 25)), DARKGREEN);
    }
    EndDrawing();
}