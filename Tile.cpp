#include "Tile.h"

float Tile::FloorGrip()
{
	switch (type)
	{
	case ROAD:
		return 1;
		break;
	case GRASS:
		return 0.5f;
		break;
	case OBSTACLE:
		return 0;
		break;
	default:
		break;
	}
}
