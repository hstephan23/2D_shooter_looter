#pragma once

struct Bullet
{
    Vector2 position;
    Vector2 velocity;
    float lifetime;
    bool active;
};

void startup();


