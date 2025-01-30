#ifndef BODY_H
#define BODY_H

#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <cmath>

const float G = 50000.0f; // Gravitational constant (adjusted for simulation)

struct Body
{
    Vector2 position;
    Vector2 velocity;
    float mass;
    Color color;

    void update(std::vector<Body> &bodies, double deltaTime);

    void resolveCollision(Body &other);

    void draw() const;
};

#endif
