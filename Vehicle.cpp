#include "Vehicle.h"
#include <math.h>

Vehicle::Vehicle(Vector2 position, Vector2 size, float initialRot) : position(position), size(size), rotation(initialRot), rotationSpeed(10), acceleration(150), maxSpeed(350), speed(0)
{
    sprite = LoadTexture("resources/texture/car_2.png");
}

Vehicle::~Vehicle()
{
}

void Vehicle::Update(float dt, float floorGrip)
{
    float forwardX = cos(rotation * (PI / 180.0f));
    float forwardY = sin(rotation * (PI / 180.0f));

    if (IsKeyDown(KEY_RIGHT)) {
        rotation += rotationSpeed * (speed/20) * dt;
        speed *= 0.99f;
    }
    else if (IsKeyDown(KEY_LEFT)) {
        rotation -= rotationSpeed * (speed/20) * dt;
        speed *= 0.99f;
    }

    if (IsKeyDown(KEY_UP) && IsKeyUp(KEY_SPACE)) {
        speed += acceleration * dt;
        if (speed > maxSpeed * floorGrip) {
            speed = maxSpeed * floorGrip;
        }
    }
    else if (IsKeyDown(KEY_DOWN) && IsKeyUp(KEY_SPACE)) {

        if (floorGrip == 0) {
            speed = 0;
        }
        else {
            speed -= acceleration * dt;
            if (speed > 0) speed -= (acceleration)*dt * floorGrip + 0.1f;
            if (speed < (-maxSpeed / 2) * floorGrip) speed = (-maxSpeed * floorGrip) / 2;
        }

    }
    else {
        if (floorGrip == 0) {
            speed = 0;
        }
        else {
            if (speed > 0) speed -= acceleration * dt;
            else if (speed < 0) speed += acceleration * dt;
        }
        
    }

    if (IsKeyDown(KEY_SPACE)) {
        speed *= 0.95;
    }

    // CHECK SCREEN COLLISIONS

    if (position.x - size.x / 2 < 0) {

        speed = 0;
        position.x = size.x / 2;
    }

    else if (position.x + size.x / 2 > GetScreenWidth()) {

        speed = 0;
        position.x = GetScreenWidth() - size.x / 2;
    }

    else if (position.y - size.y / 2 < 0) {

        speed = 0;
        position.y = size.y / 2;
    }

    else if (position.y + size.y / 2 > GetScreenHeight() ) {

        speed = 0;
        position.y = (GetScreenHeight()) - size.y / 2;
    }
    else {

        position.x += forwardX * speed * dt;
        position.y += forwardY * speed * dt;

    }
}

void Vehicle::Draw()
{
    Vector2 spriteSize = { sprite.height, sprite.width };
    DrawTexturePro(sprite, {0,0, spriteSize.y, spriteSize.x}, { position.x,position.y,size.x,size.y }, { size.x / 2,size.y / 3 }, rotation + 90, WHITE);
}

Vector2 Vehicle::collisionPos()
{
    float forwardX = cos(rotation * (PI / 180.0f));
    float forwardY = sin(rotation * (PI / 180.0f));

    if ((int)speed != 0) {
        if (speed < 0) {
            return { position.x - forwardX * size.y / 2,position.y - forwardY * size.y / 2 };
        }
        else {
            return { position.x + forwardX * size.y / 3,position.y + forwardY * size.y / 3 };
        }
    }
    else {
        if (IsKeyDown(KEY_DOWN)) {
            return { position.x - forwardX * size.y / 2,position.y - forwardY * size.y / 2 };
        }
        else {
            return { position.x + forwardX * size.y / 3,position.y + forwardY * size.y / 3 };
        }
    }
    
}

void Vehicle::Unload()
{
    UnloadTexture(sprite);
}
