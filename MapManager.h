#pragma once
#include "Tile.h"
#include <iostream>
#include "raylib.h"
#include <string>
#include "Vehicle.h"
#include "hudManager.h"

class MapManager
{
private:
	Tile* Map[20][20];
	float floorGrip;
	int checkPointIndex;
	Texture RoadTexture;
	Texture GrassTexture;
	Texture WaterTexture;
	Texture FinishTexture;
	Vehicle& car;
	hudManager& HUD;

public:
	MapManager(Vehicle& car, hudManager& HUD);
	~MapManager();

	void Initialize();
	void Update();
	void Draw();
	float FloorGrip();
	void Unload();
};

