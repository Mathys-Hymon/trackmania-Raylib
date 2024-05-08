#include "LevelEditor.h"

std::vector<TilesData> tiles = {
    {{0,255,0,255}, "GRASS"},
    {{255,0,0,255}, "ROAD"},
    {{0,0,255,255}, "OBSTACLE"},
    {{1,0,0,255}, "CHECKPOINT 1"},
    {{2,0,0,255}, "CHECKPOINT 2"},
    {{3,0,0,255}, "CHECKPOINT 3"},
    {{255,255,255,255}, "FINISH"},
};

LevelEditor::LevelEditor(int screenWidth, int screenHeight, hudManager& HUD) : screenWidth(screenWidth - 200), screenHeight(screenHeight - 200), brushColor(RED), gridSize(20), HUD(HUD)
{
    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            PixelColor[x][y] = tiles[0].TileColor;
        }
    }
}

LevelEditor::~LevelEditor()
{
}

float delay = 0;

void LevelEditor::Update()
{
    Draw();

    if (delay < 0.1f) {
        delay += GetFrameTime();
        return;
    }
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {

        Vector2 mousePosition = GetMousePosition();

        int gridX = (int)mousePosition.x / (screenWidth / gridSize);
        int gridY = (int)mousePosition.y / (screenHeight / gridSize);

        PixelColor[gridX][gridY] = brushColor;
    }

    if (GetMouseWheelMove() != 0) {
        if (GetMouseWheelMove() > 0) {

            if (mouseIndex + 1 < tiles.size()) {
                mouseIndex++;
            }
            else {
                mouseIndex = 0;
            }
        }
        else {
            if (mouseIndex - 1 >= 0) {
                mouseIndex--;
            }
            else {
                mouseIndex = (int)tiles.size() - 1;
            }
        }
        brushColor = tiles[mouseIndex].TileColor;
    }
    HUD.ChangeTileData(tiles[mouseIndex]);


    std::string name = "level Name : " + levelName;
    DrawText(name.c_str(), 350, 720, 20, WHITE);
    setName();
}

void LevelEditor::Export()
{
    Image image = GenImageColor(gridSize, gridSize, BLANK);

    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            ImageDrawPixelV(&image, {(float)x,(float)y}, PixelColor[x][y]);
        }
    }

    ExportImage(image, "resources/maps/level.png");

    UnloadImage(image);
}

void LevelEditor::Draw()
{
    int tileSize = screenWidth / gridSize;

    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            DrawRectangle(x * tileSize, y * tileSize, tileSize, tileSize, PixelColor[x][y]);
            if (PixelColor[x][y].r == tiles[3].TileColor.r) {
                DrawText("1", x * tileSize + (tileSize / 2), y * tileSize + (tileSize / 2), 20, WHITE);
            }
            else if (PixelColor[x][y].r == tiles[4].TileColor.r) {
                DrawText("2", x * tileSize + (tileSize / 2), y * tileSize + (tileSize / 2), 20, WHITE);
            }
            else if (PixelColor[x][y].r == tiles[5].TileColor.r) {
                DrawText("3", x * tileSize + (tileSize / 2), y * tileSize + (tileSize / 2), 20, WHITE);
            }


            DrawRectangleLines(x * tileSize, y * tileSize, tileSize, tileSize, GRAY);
        }
    }
}

void LevelEditor::setName()
{
    int key = GetKeyPressed();

    if (key != 0 || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        size_t len = levelName.length();

        if (key == KEY_BACKSPACE) {
            if (len > 0) {
                levelName.pop_back();
            }
        }
        else if (len < 8 && (key != KEY_ENTER && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {
            levelName.push_back(static_cast<char>(key));
        }

        else if (HUD.buttonClicked({ 350, 850 }, "EXPORT", { 150,50 })) {
                Export();
        }
    }
}
