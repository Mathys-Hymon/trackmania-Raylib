#include "MapManager.h"

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
}

void MapManager::Initialize()
{
	std::string mapText = "resources/maps/Map1.png";
	Image mapImage = LoadImage(mapText.c_str());
	Color* colors = LoadImageColors(mapImage);

	float tileSize = GetScreenWidth() / (float)mapImage.height;

	for (int y = 0; y < mapImage.height; y++) {
		for (int x = 0; x < mapImage.width; x++) {

			if (colors[y * mapImage.width + x].r == 255) {
				Map[y][x] = new Tile({ x * tileSize , y * tileSize }, { tileSize, tileSize }, ROAD);
			}
			else if (colors[y * mapImage.width + x].g == 255) {
				Map[y][x] = new Tile({ x * tileSize , y * tileSize }, { tileSize, tileSize }, GRASS);
			}
			else {
				Map[y][x] = new Tile({ x * tileSize , y * tileSize }, { tileSize, tileSize }, OBSTACLE);
			}
		}
	}

	UnloadImage(mapImage);
}

void MapManager::Draw()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			Map[i][j]->Draw();
		}
	}
}

float MapManager::FloorGrip(Vector2 position)
{
	int GridPositionX = (position.x / (sizeof(Map) / sizeof(Map[0]))) / 2;
	int GridPositionY = (position.y / (sizeof(Map) / sizeof(Map[0]))) / 2;

	return Map[GridPositionY][GridPositionX]->FloorGrip();
}

void MapManager::Unload()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			Map[i][j]->Unload();
		}
	}
}
