#include "MapManager.h"

MapManager::MapManager(Vehicle& car, hudManager& HUD) : car(car), HUD(HUD)
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
				Map[y][x] = new Tile({ x * tileSize ,100 + y * tileSize }, { tileSize, tileSize }, FINISH, FinishTexture);
			}
			else if (colors[y * mapImage.width + x].r > 0 && colors[y * mapImage.width + x].r < 255) {
				int color = colors[y * mapImage.width + x].r;

				if (color == 1) {
					Map[y][x] = new Tile({ x * tileSize ,100 + y * tileSize }, { tileSize, tileSize }, CHECKPOINT1, RoadTexture);
				}
				else if (color == 2) {
					Map[y][x] = new Tile({ x * tileSize ,100 + y * tileSize }, { tileSize, tileSize }, CHECKPOINT2, RoadTexture);
				}
				else if (color == 3) {
					Map[y][x] = new Tile({ x * tileSize ,100 + y * tileSize }, { tileSize, tileSize }, CHECKPOINT3, RoadTexture);
				}
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

void MapManager::Update()
{
	DrawCircle(car.collisionPos().x, car.collisionPos().y, 4, RED);

	int GridPositionX = (car.collisionPos().x / (GetScreenWidth() / (sizeof(Map) / sizeof(Map[0]))));
	int GridPositionY = (car.collisionPos().y / (GetScreenHeight() / (sizeof(Map) / sizeof(Map[0]))));

	TileType tile = Map[GridPositionX][GridPositionY]->GetType();
	switch (tile)
	{
	case FINISH:
		break;
	case CHECKPOINT1:
		break;
	case CHECKPOINT2:
		break;
	case CHECKPOINT3:
		break;
	default:
		break;
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

float MapManager::FloorGrip()
{
	int GridPositionX = (car.collisionPos().x / (GetScreenWidth() / (sizeof(Map) / sizeof(Map[0]))));
	int GridPositionY = (car.collisionPos().y / (GetScreenHeight() / (sizeof(Map) / sizeof(Map[0]))));

	return Map[GridPositionY - 1][GridPositionX]->FloorGrip();
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
