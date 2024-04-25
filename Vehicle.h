#pragma once
#include "raylib.h"

class Vehicle
{
private:
	Vector2 position;
	Vector2 size;
	float rotation;
	float speed;
	float acceleration;
	float maxSpeed;
	float rotationSpeed;
	Texture sprite;

public:
	Vehicle(Vector2 position, Vector2 size, float initialRot);
	~Vehicle();
	void Update(float dt, float floorGrip);
	void Draw();
	Rectangle GetPosition();
	void setVehiclePosition(Vector2 newPos);
	void Unload();

};

