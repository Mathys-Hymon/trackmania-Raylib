#include "hudManager.h"

hudManager::hudManager(int maxLap) : lap(0), maxLap(maxLap), screenIndex(5), timer(0), tileDATA(RED, "")
{
}

hudManager::~hudManager()
{
}

void hudManager::AddLap()
{
	lap += 1;
	if (lap >= maxLap) {
		DisplayedScreen(3);
	}
}

void hudManager::DisplayedScreen(int index)
{
	screenIndex = index;
}

void hudManager::Update()
{
	switch (screenIndex)
	{
	case 1:    // MENU

		break;

	case 2:   // IN GAME

		break;

	case 3:   // VICTORY / DEFEATE

		break;

	case 4:  //  LEVEL SELECTION

		break;

	case 5:  //  LEVEL EDITOR

		DrawRectangle(880, 300, 50, 50, tileDATA.TileColor);
		DrawText(tileDATA.Name.c_str(), 910 - (MeasureText(tileDATA.Name.c_str(), 20) /2), 360, 20, WHITE);

		break;

	default:
		break;
	}
}

int hudManager::getSreenIndex()
{
	return screenIndex;
}

bool hudManager::buttonClicked(Vector2 position, std::string text, Vector2 size)
{
	DrawRectangle(position.x, position.y, size.x + static_cast<float>(MeasureText(text.c_str(), 20)), size.y, BLUE);
	DrawText(text.c_str(), position.x + size.x / 2, position.y + size.y / 3, 20, WHITE);

	if (CheckCollisionPointRec(static_cast<Vector2>(GetMousePosition()), { position.x, position.y,size.x + static_cast<float>(MeasureText(text.c_str(), 20)), size.y})) {

		DrawRectangle(position.x, position.y,size.x + static_cast<float>(MeasureText(text.c_str(), 20)), size.y, DARKBLUE);
		DrawText(text.c_str(), position.x + size.x / 2, position.y + size.y / 3, 20, GRAY);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			return true;
		}
		else {
			return false;
		}
	}

	return false;
}

void hudManager::ChangeTileData(TilesData newTile)
{
	tileDATA = newTile;
}
