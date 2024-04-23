#include "Vehicle.h"

Vehicle::Vehicle(Vector2 position, Vector2 size, float initialRot) : position(position), size(size), rotation(initialRot)
{
}

Vehicle::~Vehicle()
{
}

void Vehicle::Update(float dt)
{
	if (IsKeyDown(KEY_RIGHT)) {

	}
	else if (IsKeyDown(KEY_LEFT)) {

	}


	if (IsKeyDown(KEY_UP)) {
	}
	else if (IsKeyDown(KEY_DOWN)) {

	}
}

void Vehicle::Draw()
{
	DrawRectanglePro({ position.x,position.y,size.x,size.y }, {size.x/2,size.y/3}, rotation, WHITE);
	DrawCircle(position.x, position.y, 5, RED);
}
