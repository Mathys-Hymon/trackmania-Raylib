#include "MapManager.h"

MapManager::MapManager(Vehicle& car, hudManager& HUD) : car(car), HUD(HUD), checkPointIndex(0)
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
	CheckpointTexture = LoadTexture("resources/texture/checkpoint.png");
	WaterTexture = LoadTexture("resources/texture/Water.png");

	float tileSize = GetScreenWidth() / (float)mapImage.height;

	for (int y = 0; y < mapImage.height; y++) {
		for (int x = 0; x < mapImage.width; x++) {

			if (colors[y * mapImage.width + x].r == 255 && colors[y * mapImage.width + x].g == 255 && colors[y * mapImage.width + x].b == 255) {
				Map[y][x] = new Tile({ x * tileSize , y * tileSize }, { tileSize, tileSize }, FINISH, FinishTexture);
			}
			else if (colors[y * mapImage.width + x].r > 0 && colors[y * mapImage.width + x].r < 255) {
				int color = colors[y * mapImage.width + x].r;

				if (color == 1) {
					Map[y][x] = new Tile({ x * tileSize , y * tileSize }, { tileSize, tileSize }, CHECKPOINT1, CheckpointTexture);
				}
				else if (color == 2) {
					Map[y][x] = new Tile({ x * tileSize , y * tileSize }, { tileSize, tileSize }, CHECKPOINT2, CheckpointTexture);
				}
				else if (color == 3) {
					Map[y][x] = new Tile({ x * tileSize , y * tileSize }, { tileSize, tileSize }, CHECKPOINT3, CheckpointTexture);
				}
			}

			else if (colors[y * mapImage.width + x].r == 255) {
				Map[y][x] = new Tile({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, ROAD, RoadTexture);
			}
			else if (colors[y * mapImage.width + x].g == 255) {
				Map[y][x] = new Tile({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, GRASS, GrassTexture);
			}
			else {
				Map[y][x] = new Tile({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, OBSTACLE, WaterTexture);
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

	TileType tile = Map[GridPositionY - 1][GridPositionX]->GetType();

	//std::cout << tile << std::endl;
	switch (tile)
	{
	case FINISH:
		if (checkPointIndex == 3) {
			HUD.AddLap();
			checkPointIndex = 0;
		}
		break;
	case CHECKPOINT1:
		if (checkPointIndex == 0) {
			std::cout << "checkpoint 1 passed" << std::endl;
			checkPointIndex = 1;
		}
		break;
	case CHECKPOINT2:
		if (checkPointIndex == 1) {
			std::cout << "checkpoint 2 passed" << std::endl;
			checkPointIndex = 2;
		}
		break;
	case CHECKPOINT3:
		if (checkPointIndex == 2) {
			std::cout << "checkpoint 3 passed" << std::endl;
			checkPointIndex = 3;
		}
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

	std::cout << Map[GridPositionY][GridPositionX]->FloorGrip() << std::endl;
	return Map[GridPositionY][GridPositionX]->FloorGrip();
}

void MapManager::Unload()
{
	UnloadTexture(RoadTexture);
	UnloadTexture(GrassTexture);
	UnloadTexture(WaterTexture);
	UnloadTexture(FinishTexture);
	UnloadTexture(CheckpointTexture);

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			Map[i][j]->Unload();
		}
	}
}
