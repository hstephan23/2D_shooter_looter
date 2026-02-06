#include <span>
#include "raylib.h"

#include "rendering.h"
#include "bullet_system.h"

void render(
    const std::span<Bullet> bullets,
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

    DrawText(TextFormat("Lives: "), 10, 30, 20, BLACK);
    for (int i = 0; i < player.health; ++i) DrawCircle(20 + i * 25, 60, 10, RED);

    DrawText(TextFormat("Dash Cooldown:"), 10, 90, 20, BLACK);
    constexpr float dash_cooldown_max = 2.0f;
    constexpr int dash_bar_width = 100;
    float dash_ratio = player.dash_cooldown / dash_cooldown_max;
    if (dash_ratio < 0.0f) dash_ratio = 0.0f;
    if (dash_ratio > 1.0f) dash_ratio = 1.0f;
    DrawRectangle(170, 95, dash_bar_width, 15, LIGHTGRAY);
    DrawRectangle(170, 95, static_cast<int>(dash_ratio * dash_bar_width), 15, ORANGE);

    const auto active_num_bullets = count_active_bullets(bullets, MAX_BULLETS);
    DrawText(TextFormat("Bullets Remaining: %d", active_num_bullets), 10, 70, 20, BLACK);

    EndDrawing();
}
