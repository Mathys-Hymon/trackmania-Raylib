#include "hudManager.h"

hudManager::hudManager(int maxLap) : lap(0), maxLap(maxLap), screenIndex(0)
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

	default:
		break;
	}
}

int hudManager::getSreenIndex()
{
	return 5;
}
