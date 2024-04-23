#include "Vehicle.h"
#include <math.h>

Vehicle::Vehicle(Vector2 position, Vector2 size, float initialRot) : position(position), size(size), rotation(initialRot), rotationSpeed(10), acceleration(20), maxSpeed(150)
{
}

Vehicle::~Vehicle()
{
}

void Vehicle::Update(float dt)
{
    // Calcul du vecteur de déplacement en fonction de l'angle de rotation
    float forwardX = cos(rotation * (PI / 180.0f));
    float forwardY = sin(rotation * (PI / 180.0f));

    // Gestion de la rotation
    if (IsKeyDown(KEY_RIGHT)) {
        rotation += rotationSpeed * dt;
    }
    else if (IsKeyDown(KEY_LEFT)) {
        rotation -= rotationSpeed * dt;
    }

    // Gestion de l'accélération
    if (IsKeyDown(KEY_UP)) {
        speed += acceleration * dt;
        if (speed > maxSpeed) {
            speed = maxSpeed;
        }
    }
    else if (IsKeyDown(KEY_DOWN)) {
        if (speed > 0) speed -= acceleration * dt;
        if (speed < -maxSpeed / 2) speed = -maxSpeed / 2;
    }
    else {
        speed = 0;
    }

    // Mise à jour de la position en fonction de la vitesse et de l'angle de rotation
    position.x += forwardX * speed * dt;
    position.y += forwardY * speed * dt;
}

void Vehicle::Draw()
{
	DrawRectanglePro({ position.x,position.y,size.x,size.y }, {size.x/2,size.y/3}, rotation, WHITE);
	DrawCircle(position.x, position.y, 5, RED);
}

Vector2 Vehicle::GetPosition()
{
	return position;
}
