#include "raylib.h"
#include "raymath.h"

#include "startup.h"

void startup()
{
    InitWindow(800, 600, "Game_Engine");
    constexpr int MAX_BULLETS = 12;
    Bullet bullets[MAX_BULLETS] = {};
    // TODO: These will change with power ups in the future
    float fire_rate = 6.0f;
    float bullet_speed = 100.0f;
    float fire_cool_down = 0.0f;
    // TODO: Should we move the player on the existing map? Or move the map behind them??
    auto player_position = Vector2{400, 300};

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ESCAPE)) break;

        const float delta_time = GetFrameTime();
        fire_cool_down -= delta_time;

        auto aim_direction = Vector2Normalize(Vector2Subtract(GetMousePosition(), player_position));
        auto gun_position =  Vector2Add(player_position, Vector2Scale(aim_direction, 20.0f) );
        auto muzzle_position = Vector2Add(gun_position, Vector2Scale(aim_direction, 5.0f));
        bool want_to_fire = IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_LEFT);

        if (want_to_fire && fire_cool_down <= 0.0f)
        {
            for (auto & bullet : bullets)
            {
                if (!bullet.active)
                {
                    bullet.position = muzzle_position;
                    bullet.velocity = Vector2Scale(aim_direction, bullet_speed);
                    bullet.active = true;
                    bullet.lifetime = 4.0f;
                    fire_cool_down = 1.0f / fire_rate;
                    break;
                }
            }
        }

        for (auto & [position, velocity, lifetime, active] : bullets)
        {
            if (!active) continue;

            position.x += velocity.x * delta_time;
            position.y += velocity.y * delta_time;
            lifetime -= delta_time;

            if (lifetime <= 0.0f
                || position.x < 0.0f || position.x > static_cast<float>(GetScreenWidth()) + 20
                || position.y < 0.0f || position.y > static_cast<float>(GetScreenHeight()) + 20
            )
            {
                active = false;
            }
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawFPS(10,10);

        DrawCircleV(player_position, 20, RED);
        DrawCircleV(gun_position, 5, BLACK);
        for (const auto & bullet : bullets)
            if (bullet.active) DrawCircleV(bullet.position, 3, GREEN);

        int active_num_bullets = MAX_BULLETS;
        for (const auto & bullet : bullets) active_num_bullets -= bullet.active ? 1 : 0;

        DrawText(TextFormat("Bullets Remaining: %d", active_num_bullets), 10, 30, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
}