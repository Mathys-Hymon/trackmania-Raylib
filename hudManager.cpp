#include "hudManager.h"

hudManager::hudManager(int maxLap) : lap(0), maxLap(maxLap)
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
	switch (index)
	{
	case 1:    // MENU

		break;

	case 2:   // IN GAME

		break;

	case 3:   // VICTORY / DEFEATE

		break;

	default:
		break;
	}
}

void hudManager::Update()
{
	std::string lapText = "lap : " + std::to_string(lap);
	DrawText(lapText.c_str(), 50, 50, 20, WHITE);
}
