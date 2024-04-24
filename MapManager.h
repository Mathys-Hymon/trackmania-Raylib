#pragma once
#include "Tile.h"
#include <iostream>
#include "raylib.h"
#include <string>

class MapManager
{
private:
	Tile* Map[20][20];

public:
	MapManager();
	~MapManager();

	void Initialize();
	void Update();
	void Draw();
	float FloorGrip(Vector2 position);
	void Unload();
};

