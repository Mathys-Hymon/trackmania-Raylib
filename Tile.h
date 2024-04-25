#pragma once
#include "raylib.h"
#include "TileType.h"

class Tile
{
private:
	Vector2 position;
	Vector2 size;

	TileType type;
	Texture sprite;

public:
	Tile(Vector2 position, Vector2 size, TileType type, Texture sprite);
	~Tile();

	float FloorGrip();
	void Draw();
	float GetSize();
	void Unload();
};

