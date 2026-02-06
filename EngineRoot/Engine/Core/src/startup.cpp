#include "raylib.h"
#include <span>
#include <array>

#include "startup.h"

#include "player.h"
#include "aiming.h"
#include "bullet_system.h"
#include "monster.h"
#include "rendering.h"

void startup()
{
    InitWindow(1000, 800, "Game_Engine");
    SetTargetFPS(120);
    constexpr int MAX_BULLETS = 12;
    constexpr int MAX_GRUNTS = 3;
    std::array<Bullet, MAX_BULLETS> bullets = {};
    Player player = {
        .position = Vector2{500, 400},
        .bullet_speed = 150.0f,
        .bullet_damage = 10.0f,
        .fire_rate = 6.0f,
        .fire_cooldown = 0.0f,
        .dash_cooldown = 0.0f,
        .health = 3,
    };

    std::array<Monster, MAX_GRUNTS> grunts = {};
    for (int i = 0; i < MAX_GRUNTS; ++i)
    {
        grunts[i] = create_grunt(Vector2{100.0f + static_cast<float>(i) * 100.0f, 200.0f});
    }

    // Monster shooter = {};
    //     // .position = Vector2{300, 300},
    //     // .type = MonsterType::Shooter,
    //     // .speed = 100.0f,
    //     // .health = 10.0f,
    //
    // Monster dasher = {};
    // Monster turret = {};

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ESCAPE)) break;

        const float delta_time = GetFrameTime();
        const auto aim_direction = compute_aim_direction(player.position);
        const auto gun_position = compute_gun_position(player.position, aim_direction);
        const auto muzzle_position = compute_muzzle_position(gun_position, aim_direction);

        spawn_bullet(bullets,player,muzzle_position, aim_direction, delta_time);
        player_move(player, delta_time, 100.0f);
        for (auto & grunt : grunts) move_grunt(grunt, player, delta_time);
        player_dash(player, delta_time);
        update_bullets(bullets, delta_time);
        render(bullets, grunts, player, gun_position, MAX_BULLETS);
    }

    CloseWindow();
}