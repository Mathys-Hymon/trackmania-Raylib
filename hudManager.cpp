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
		if (buttonClicked({ 500,300 }, "START 1P", { 70,70 })) {
			screenIndex = 4;
		}
		if (buttonClicked({ 500,450 }, "START 2P", { 70,70 })) {
			screenIndex = 4;
		}

		if (buttonClicked({ 500,600 }, "LEVEL EDITOR", { 70,70 })) {
			screenIndex = 5;
		}
		if (buttonClicked({ 500,750 }, "EXIT", { 70,70 })) {
			exitApp = true;
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

		if (IsKeyDown(KEY_TAB)) {
			screenIndex = 1;
		}

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
	DrawRectangle(position.x - (MeasureText(text.c_str(), 20) + size.x) /2, position.y, size.x + static_cast<float>(MeasureText(text.c_str(), 20)), size.y, BLUE);
	DrawText(text.c_str(), position.x - (MeasureText(text.c_str(), 20)) / 2, position.y + size.y / 3, 20, WHITE);

	if (CheckCollisionPointRec(static_cast<Vector2>(GetMousePosition()), { position.x - (MeasureText(text.c_str(), 20) + size.x) /2, position.y,size.x + static_cast<float>(MeasureText(text.c_str(), 20)), size.y})) {

		DrawRectangle(position.x - (MeasureText(text.c_str(), 20) + size.x) /2, position.y,size.x + static_cast<float>(MeasureText(text.c_str(), 20)), size.y, DARKBLUE);
		DrawText(text.c_str(),position.x - (MeasureText(text.c_str(), 20)) / 2, position.y + size.y / 3, 20, GRAY);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			return true;
		}
		else {
			return false;
		}
	}

	return false;
}

bool hudManager::CloseGame()
{
	return exitApp;
}

void hudManager::ChangeTileData(TilesData newTile)
{
	tileDATA = newTile;
}

void hudManager::ShowMaps(Vector2 position, float textSize, Texture& image, std::string name)
{
	DrawTexturePro(image, { 0,0, (float)image.width, (float)image.height }, { position.x,position.y, 200,200 }, { 100,100 }, 0, WHITE);
	DrawText(name.c_str(),( position.x - MeasureText(name.c_str(), textSize) /2) + image.width / 2, position.y + 115, textSize, BLACK);
}
