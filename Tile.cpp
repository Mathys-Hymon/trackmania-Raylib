#include "Tile.h"

Tile::Tile(Vector2 position, Vector2 size, TileType type , Texture sprite, Texture activatedSprite, float spriteRotation) : position(position), size(size), type(type), sprite(sprite), activatedSprite(activatedSprite), spriteRotation(spriteRotation)
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
		return 1.0f;
		break;
	}
}

void Tile::Draw(bool isActivated)
{
	Vector2 spriteSize = { sprite.height, sprite.width };

	if (isActivated) {
		DrawTexturePro(activatedSprite, { 0,0,spriteSize.x,spriteSize.y }, { position.x,position.y, size.x, size.y }, { 0,0 }, spriteRotation, WHITE);
	}
	else {
		DrawTexturePro(sprite, { 0,0,spriteSize.x,spriteSize.y }, { position.x,position.y, size.x, size.y }, { 0,0 }, spriteRotation, WHITE);
	}
}

bool Tile::CheckCollision()
{
	return false;
}

int Tile::CheckPointIndex()
{
	switch (type)
	{
	case FINISH:
		return 0;
		break;
	case CHECKPOINT1:
		return 1;
		break;
	case CHECKPOINT2:
		return 2;
		break;
	case CHECKPOINT3:
		return 3;
		break;
	default:
		return -1;
		break;
	}
}

float Tile::GetSize()
{
	return (float)sprite.height;
}

TileType Tile::GetType()
{
	return type;
}

void Tile::Unload()
{
	UnloadTexture(sprite);
}