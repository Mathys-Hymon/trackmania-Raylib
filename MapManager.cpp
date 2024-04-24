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

float MapManager::FloorGrip(Vehicle& car)
{

	int GridPositionX = (car.GetPosition().x / (sizeof(Map) / sizeof(Map[0]))) / 2;
	int GridPositionY = (car.GetPosition().y / (sizeof(Map) / sizeof(Map[0]))) / 2;

	float grip = Map[GridPositionY][GridPositionX]->FloorGrip();

	if (grip == 0.0f)
	{
		// Calcule la position de la voiture après la collision
		float tile_size = (float)sizeof(Map) / sizeof(Map[0]);

		Vector2 new_position = { car.GetPosition().x - (car.GetPosition().width / 2) + (tile_size / 2), car.GetPosition().y - (car.GetPosition().height / 2) + (tile_size / 2) };

		// Déplace la voiture à la nouvelle position
		car.setVehiclePosition(new_position);
	}

	return grip;
}

void MapManager::Unload()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			Map[i][j]->Unload();
		}
	}
}
