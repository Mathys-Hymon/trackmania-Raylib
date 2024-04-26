#pragma once
#include "raylib.h"
#include <iostream>
#include <string>

class hudManager
{
private:
	int lap;
	int maxLap;
	float timer;

public:
	hudManager(int maxLap);
	~hudManager();

	void AddLap();
	void DisplayedScreen(int index);
	void Update();
};

