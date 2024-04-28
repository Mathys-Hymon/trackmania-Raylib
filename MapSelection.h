#pragma once
#include"MapManager.h"
#include "filesystem"

class MapSelection
{
private:
	MapManager mapManager;
	hudManager HUD;

	int mapIndex = -2;
	float delay = 0;
	std::vector<Texture2D> mapTextures;
	std::vector<std::string> mapNames;

public:
	MapSelection(hudManager& HUD, MapManager mapManager);
	~MapSelection();

	void Draw();
	void Update();
	void SelectMap();
};

