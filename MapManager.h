#pragma once
#include "Tile.h"
#include "raylib.h"
#include "Vehicle.h"
#include "hudManager.h"

class MapManager
{
private:
	Tile* Map[20][20];
	float floorGrip;
	int checkPointIndex;
	int mapIndex = -2;
	Texture RoadTexture;
	Texture GrassTexture;
	Texture WaterTexture;
	Texture FinishTexture;
	Texture CheckpointTexture;
	Texture CheckPointTextureA;
	Vehicle& car;
	hudManager& HUD;

public:
	MapManager(Vehicle& car, hudManager& HUD);
	~MapManager();

	void Initialize();
	void ChooseMap(Image mapImage);
	void Update();
	void Draw();
	float FloorGrip();
	void Unload();
};

