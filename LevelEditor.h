#pragma once
#include "raylib.h"
#include <string>

class LevelEditor
{
public:
    LevelEditor(int screenWidth, int screenHeight);
    ~LevelEditor();

    void Update();

private:
    void Export();
    void Draw();


    Color PixelColor[50][50];
    int screenWidth;
    int screenHeight;
    int gridSize = 20;
    Color brushColor;
    Color colors[7];
    std::
    std::string levelName;
    int mouseIndex = 0;
};

