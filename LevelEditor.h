#pragma once
#include "raylib.h"
#include <string>
#include <vector>
#include "hudManager.h"

class LevelEditor
{
public:
    LevelEditor(int screenWidth, int screenHeight, hudManager& HUD);
    ~LevelEditor();

    void Update();
    void Export();

private:
    void Draw();

    const int screenWidth;
    const int screenHeight;

    hudManager& HUD;
    Color PixelColor[50][50];
    int gridSize = 20;
    Color brushColor;
    std::string levelName;
    int mouseIndex = 0;
};

