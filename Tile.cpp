#include "Tile.h"

Tile::Tile(Vector2 position, Vector2 size, TileType type , Texture sprite) : position(position), size(size), type(type), sprite(sprite)
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
	//DrawRectangleRec({position.x, position.y, size.x, size.y}, sprite);
	//DrawTextureEx(sprite, position, 0, 0.31f, WHITE);
	Vector2 spriteSize = { sprite.height, sprite.width };
	DrawTexturePro(sprite, { 0,0,spriteSize.x,spriteSize.y }, {position.x,position.y, size.x, size.y }, {0,0}, 0, WHITE);
}

float Tile::GetSize()
{
	return (float)sprite.height;
}

void Tile::Unload()
{
	UnloadTexture(sprite);
}