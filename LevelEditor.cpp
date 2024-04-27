#include "LevelEditor.h"

LevelEditor::LevelEditor(int screenWidth, int screenHeight) : screenWidth(screenWidth- 200), screenHeight(screenHeight- 200), brushColor(RED), gridSize(20)
{
    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            PixelColor[x][y] = GREEN;
        }
    };
}

LevelEditor::~LevelEditor()
{
}

void LevelEditor::Update()
{
    Draw();

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {

        Vector2 mousePosition = GetMousePosition();

        int gridX = (int)mousePosition.x / (screenWidth / gridSize);
        int gridY = (int)mousePosition.y / (screenHeight / gridSize);

        // Colorier la case de la grille
        PixelColor[gridX][gridY] = brushColor;
    }

    if (GetMouseWheelMove() != 0) {
        if (GetMouseWheelMove > 0) {
            mouseIndex++;
        }
        else {
            mouseIndex--;
        }


    }
}

void LevelEditor::Export()
{
    Image image = GenImageColor(gridSize, gridSize, BLANK);

    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            //Color pixelColor = GetPixelColor(x * gridSize, y * gridSize);
            //ImageDrawPixel(&image, x, y, pixelColor);
        }
    }

    ExportImage(image, "grid.png");
    UnloadImage(image);
}

void LevelEditor::Draw()
{
    float tileSize = screenWidth / gridSize;

    for (int x = 0; x < gridSize; x++ ) {
        for (int y = 0; y < gridSize; y++) {
            DrawRectangle(x * tileSize, y * tileSize, tileSize, tileSize, PixelColor[x][y]);
            DrawRectangleLines(x * tileSize, y * tileSize, tileSize, tileSize, GRAY);   
        }
    }
}
