#pragma once
#include "Tile.h"
#include <iostream>
#include "raylib.h"
#include <string>
#include "Vehicle.h"

class MapManager
{
private:
	Tile* Map[20][20];
	Texture2D RoadTexture;
	Texture2D GrassTexture;
	Texture2D ObstacleTexture;

public:
	MapManager();
	~MapManager();

	void Initialize();
	void Update();
	void Draw();
	float FloorGrip(Vehicle& car);
	void Unload();
};

