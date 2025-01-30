#include "body.h"

void Body::update(std::vector<Body> &bodies, double deltaTime)
{
    Vector2 acceleration = {0.0f, 0.0f};

    for (auto &other : bodies)
    {
        if (&other == this)
            continue;

        Vector2 direction = {other.position.x - position.x, other.position.y - position.y};
        float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

        if (distance < mass / 2 + other.mass / 2)
        { // Collision handling
            resolveCollision(other);
            continue;
        }

        float force = (G * mass * other.mass) / (distance * distance);
        Vector2 unitDir = {direction.x / distance, direction.y / distance};

        acceleration.x += (force / mass) * unitDir.x;
        acceleration.y += (force / mass) * unitDir.y;
    }

    velocity.x += acceleration.x * deltaTime;
    velocity.y += acceleration.y * deltaTime;
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
}

void Body::resolveCollision(Body &other)
{
    float restitution = 0.5f; // Coefficient of restitution (0 = inelastic, 1 = elastic)

    Vector2 relativeVelocity = {other.velocity.x - velocity.x, other.velocity.y - velocity.y};
    Vector2 collisionNormal = {other.position.x - position.x, other.position.y - position.y};
    float distance = sqrt(collisionNormal.x * collisionNormal.x + collisionNormal.y * collisionNormal.y);

    if (distance == 0)
        return; // Avoid division by zero

    collisionNormal.x /= distance;
    collisionNormal.y /= distance;

    float velocityAlongNormal = relativeVelocity.x * collisionNormal.x + relativeVelocity.y * collisionNormal.y;
    if (velocityAlongNormal > 0)
        return; // Bodies are separating

    float impulseMagnitude = -(1 + restitution) * velocityAlongNormal;
    impulseMagnitude /= (1 / mass + 1 / other.mass);

    Vector2 impulse = {impulseMagnitude * collisionNormal.x, impulseMagnitude * collisionNormal.y};

    velocity.x -= 0.9 * impulse.x / mass;
    velocity.y -= 0.9 * impulse.y / mass;
    other.velocity.x += 0.9 * impulse.x / other.mass;
    other.velocity.y += 0.9 * impulse.y / other.mass;
}

void Body::draw() const
{
    DrawCircleV(position, mass / 2, color);
}
