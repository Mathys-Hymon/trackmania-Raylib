#pragma once
#include"MapManager.h"
#include "filesystem"

class MapSelection
{
private:
	MapManager& mapManager;
	hudManager& HUD;

	int mapIndex = -2;
	int displayIndex = 0;
	float delay = 0;
	std::vector<Texture> mapTextures;
	std::vector<std::string> mapNames;

	void Draw();
public:
	MapSelection(hudManager& HUD, MapManager& mapManager);
	~MapSelection();


	void Update();
	void SelectMap();
	void Unload();
};

