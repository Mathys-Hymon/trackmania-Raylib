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
	Texture RoadTexture;
	Texture GrassTexture;
	Texture WaterTexture;
	Texture FinishTexture;

public:
	MapManager();
	~MapManager();

	void Initialize();
	void Update();
	void Draw();
	float FloorGrip(Vehicle& car);
	void Unload();
};

