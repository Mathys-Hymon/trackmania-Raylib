#pragma once
class hudManager
{
private:
	float timer;

public:
	hudManager();
	~hudManager();

	void AddLap();
	void DisplayScreen(int index);
	void Update();
};

