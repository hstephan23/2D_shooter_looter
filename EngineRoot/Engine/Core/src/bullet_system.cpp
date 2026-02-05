#include <span>
#include "raylib.h"
#include "raymath.h"

#include "player.h"
#include "bullet_system.h"

void spawn_bullet(
    std::span<Bullet> bullets,
    Player & player,
    const Vector2 muzzle_position,
    const Vector2 aim_direction,
    const float delta_time
    )
{
    player.fire_cooldown -= delta_time;
    if (player.fire_cooldown <= 0.0f)
    {
        for (auto & [position, velocity, lifetime, active] : bullets)
        {
            if (!active)
            {
                position = muzzle_position;
                velocity = Vector2Scale(aim_direction, player.bullet_speed);
                active = true;
                lifetime = 4.0f;
                player.fire_cooldown = 1.0f / player.fire_rate;
                break;
            }
        }
    }
}
void update_bullets(std::span<Bullet> bullets, const float delta_time){
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

}
int count_active_bullets(const std::span<Bullet> bullets, const int MAX_BULLETS){
    int active_num_bullets = MAX_BULLETS;
    for (const auto & bullet : bullets) active_num_bullets -= bullet.active ? 1 : 0;
    return active_num_bullets;
}
