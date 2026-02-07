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
    constexpr int MAX_MONSTERS = 10;
    std::array<Bullet, MAX_BULLETS> bullets = {};
    Player player = {
        .position = Vector2{500, 400},
        .bullet_speed = 150.0f,
        .bullet_damage = 10.0f,
        .fire_rate = 6.0f,
        .fire_cooldown = 0.0f,
        .dash_cooldown = 0.0f,
        .speed = 100.0f,
        .health = 3,
    };
    std::array<Monster, MAX_MONSTERS> monsters = {};
    for (int i = 0; i < MAX_MONSTERS; i++)
    {
        switch (MonsterType type = random_monster_type())
        {
        case MonsterType::Grunt:
            monsters[i] = create_grunt(Vector2{100.0f + static_cast<float>(i) * 100.0f, 100.0f});
            break;
        case MonsterType::Shooter:
            monsters[i] = create_shooter(Vector2{100.0f + static_cast<float>(i) * 100.0f, 200.0f});
            break;
        case MonsterType::Dasher:
            monsters[i] = create_dasher(Vector2{100.0f + static_cast<float>(i) * 100.0f, 300.0f});
        case MonsterType::Turret:
            monsters[i] = create_turret(Vector2{100.0f + static_cast<float>(i) * 100.0f, 400.0f});
        default:
            break;
        }

    }

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ESCAPE)) break;

        const float delta_time = GetFrameTime();
        const auto aim_direction = compute_aim_direction(player.position);
        const auto gun_position = compute_gun_position(player.position, aim_direction);
        const auto muzzle_position = compute_muzzle_position(gun_position, aim_direction);

        spawn_bullet(bullets,player,muzzle_position, aim_direction, delta_time);
        player_move(player, delta_time, player.speed);
        for (auto & monster : monsters) move_monster(monster, player, delta_time);
        player_dash(player, delta_time);
        update_bullets(bullets, delta_time);
        render(bullets, monsters, player, gun_position, MAX_BULLETS);
    }

    CloseWindow();
}