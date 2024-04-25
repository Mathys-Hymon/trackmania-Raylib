#include "MapManager.h"

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
}

void MapManager::Initialize()
{
	Image mapImage = LoadImage("resources/maps/Map1.png");
	Color* colors = LoadImageColors(mapImage);
	
	RoadTexture = LoadTexture("resources/texture/road.png");
	FinishTexture = LoadTexture("resources/texture/finish.png");
	GrassTexture = LoadTexture("resources/texture/grass.png");
	WaterTexture = LoadTexture("resources/texture/Water.png");

	float tileSize = GetScreenWidth() / (float)mapImage.height;

	for (int y = 0; y < mapImage.height; y++) {
		for (int x = 0; x < mapImage.width; x++) {

			if (colors[y * mapImage.width + x].r == 255 && colors[y * mapImage.width + x].g == 255 && colors[y * mapImage.width + x].b == 255) {
				Map[y][x] = new Tile({ x * tileSize ,100 + y * tileSize }, { tileSize, tileSize }, ROAD, FinishTexture);
			}
			else if (colors[y * mapImage.width + x].r == 255) {
				Map[y][x] = new Tile({ x * tileSize ,100 + y * tileSize }, { tileSize, tileSize }, ROAD, RoadTexture);
			}
			else if (colors[y * mapImage.width + x].g == 255) {
				Map[y][x] = new Tile({ x * tileSize ,100 + y * tileSize }, { tileSize, tileSize }, GRASS, GrassTexture);
			}
			else {
				Map[y][x] = new Tile({ x * tileSize ,100 + y * tileSize }, { tileSize, tileSize }, OBSTACLE, WaterTexture);
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

	int GridPositionX = (car.GetPosition().x / (GetScreenWidth() / (sizeof(Map) / sizeof(Map[0]))));
	int GridPositionY = (car.GetPosition().y / (GetScreenHeight() / (sizeof(Map) / sizeof(Map[0]))));

	std::cout << GridPositionX << std::endl;

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
	UnloadTexture(RoadTexture);
	UnloadTexture(GrassTexture);
	UnloadTexture(WaterTexture);
	UnloadTexture(FinishTexture);

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			Map[i][j]->Unload();
		}
	}
}
