#include "hudManager.h"

hudManager::hudManager(int maxLap) : lap(0), maxLap(maxLap), screenIndex(1), timer(0), tileDATA(RED, "")
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
	std::string lapText = "Laps : " + std::to_string(lap) + "/" + std::to_string(maxLap);

	switch (screenIndex)
	{
	case 1:    // MENU
		if (buttonClicked({ 500,500 }, "START", { 30,10 })) {
			screenIndex = 2;
		}
		break;

	case 2:   // IN GAME

		DrawText(lapText.c_str(), 50, 50, 30, WHITE);

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

bool hudManager::ShowMaps(Vector2 position, float textSize, Texture image, std::string name)
{
	DrawTexturePro(image, { position.x,position.y, (float)image.width, (float)image.height }, { position.x,position.y, 200,200 }, { 100,100 }, 0, WHITE);
	//DrawTexture(image, position.x - image.width/2, position.y - image.height/2, WHITE);
	DrawText(name.c_str(), position.x - MeasureText(name.c_str(), textSize), position.y - 70, textSize, BLACK);

	if (CheckCollisionPointRec(GetMousePosition(),{ position.x, position.y, (float)image.width, (float)image.height }) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		return true;
	}
	else {
		return false;
	}
}
