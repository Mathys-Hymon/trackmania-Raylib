#pragma once
#include "Tile.h"

class MapManager
{
private:
	Tile* Map[20][20];

public:
	MapManager();
	~MapManager();

	void Initialize();
	void Update();
	void Draw();
	void Unload();
};

