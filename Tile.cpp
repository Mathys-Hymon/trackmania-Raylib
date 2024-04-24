#include "Tile.h"

Tile::Tile(Vector2 position, Vector2 size, TileType type , Texture& sprite) : position(position), size(size), type(type), sprite(sprite)
{
}

Tile::~Tile()
{
}

float Tile::FloorGrip()
{
	switch (type)
	{
	case ROAD:
		return 1.0f;
		break;
	case GRASS:
		return 0.3f;
		break;
	case OBSTACLE:
		return 0.0f;
		break;
	default:
		break;
	}
}

void Tile::Draw()
{
	Color tempColor = WHITE;
	switch (type)
	{
	case ROAD:
		tempColor = GRAY;
		break;
	case GRASS:
		tempColor = GREEN;
		break;
	case OBSTACLE:
		tempColor = BLUE;
		break;
	default:
		break;
	}

	DrawRectangleRec({position.x, position.y, size.x, size.y}, tempColor);
}

void Tile::Unload()
{
}