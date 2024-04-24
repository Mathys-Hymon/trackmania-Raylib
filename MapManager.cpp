#include "MapManager.h"

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
}

void MapManager::Initialize()
{
	float tileSize = GetScreenWidth() / 20.0f;
	bool flipflop = false;

	for (int i = 0; i < 20; i++) {
		flipflop = !flipflop;
		for (int j = 0; j < 20; j++) {
			if (flipflop) {
				flipflop = false;
				Map[i][j] = new Tile({ j * tileSize , i * tileSize }, { tileSize, tileSize }, GRASS);
			}
			else {
				flipflop = true;
				Map[i][j] = new Tile({ j * tileSize , i * tileSize }, { tileSize, tileSize }, ROAD);
			}
			
		}
	}
}

void MapManager::Draw()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			Map[i][j]->Draw();
		}
	}
}

void MapManager::Unload()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			Map[i][j]->Unload();
		}
	}
}
