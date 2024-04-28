#pragma once
#include "raylib.h"
#include <string>

struct TilesData
{
	Color TileColor;
	std::string Name;

	TilesData(Color TileColor, std::string Name);
};

