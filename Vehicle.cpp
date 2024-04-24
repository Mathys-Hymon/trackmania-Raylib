#include "Vehicle.h"
#include <math.h>

Vehicle::Vehicle(Vector2 position, Vector2 size, float initialRot) : position(position), size(size), rotation(initialRot), rotationSpeed(10), acceleration(150), maxSpeed(350), speed(0)
{
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
        speed -= acceleration * dt;
        if (speed > 0) speed -= (acceleration)* dt * floorGrip;
        if (speed < -maxSpeed / 2) speed = (-maxSpeed * floorGrip) / 2 ;
    }
    else {
        if (speed > 0) speed -= acceleration * dt;
        else if (speed < 0) speed += acceleration * dt;
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

    else if (position.y + size.y / 2 > GetScreenHeight()) {

        speed = 0;
        position.y = GetScreenWidth() - size.y / 2;
    }
    else {

        position.x += forwardX * speed * dt;
        position.y += forwardY * speed * dt;

    }
}

void Vehicle::Draw()
{
	DrawRectanglePro({ position.x,position.y,size.x,size.y }, {size.x/2,size.y/3}, rotation + 90, WHITE);
	DrawCircle(position.x, position.y, 5, RED);
}

Rectangle Vehicle::GetPosition()
{
    return {position.x, position.y, size.x, size.y };
}

void Vehicle::setVehiclePosition(Vector2 newPos)
{
    position = newPos;
}
