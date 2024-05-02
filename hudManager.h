#pragma once
#include "raylib.h"
#include <iostream>
#include <vector>
#include <string>
#include "TilesData.h"

class hudManager
{
private:
	int screenIndex;
	int lap;
	int maxLap;
	float timer;
	bool exitApp = false;
	TilesData tileDATA;

public:
	hudManager(int maxLap);
	~hudManager();

	void AddLap();
	void DisplayedScreen(int index);
	void Update();
	int getSreenIndex();
	bool buttonClicked(Vector2 position, std::string text, Vector2 size);
	bool CloseGame();


	//level EditorFunctions

	void ChangeTileData(TilesData newTile);

	//show maps

	void ShowMaps(Vector2 position, float textSize, Texture& image, std::string name);
};

