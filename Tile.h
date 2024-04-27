#pragma once
#include "raylib.h"
#include "TileType.h"

class Tile
{
private:
	Vector2 position;
	Vector2 size;

	float spriteRotation;

	TileType type;
	Texture sprite;
	Texture activatedSprite;

public:
	Tile(Vector2 position, Vector2 size, TileType type, Texture sprite, Texture activatedSprite, float spriteRotation);
	~Tile();

	float FloorGrip();
	void Draw(bool isActivated);
	bool CheckCollision();
	int CheckPointIndex();
	float GetSize();
	TileType GetType();
	void Unload();
};

