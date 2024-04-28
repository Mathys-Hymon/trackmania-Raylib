#include "raylib.h"
#include <iostream>
#include "MapManager.h"
#include "LevelEditor.h"

int main() {

    InitWindow(1000, 1000, "Trackmania Raylib");
    SetTargetFPS(60);

    hudManager HUD(3);
    Vehicle car(Vector2{200,700}, Vector2{28,50}, 90);
    MapManager mapManager(car, HUD);
    LevelEditor levelEditor(GetScreenWidth(), GetScreenHeight(), HUD);


    mapManager.Initialize();

    while (!WindowShouldClose()) {

        ClearBackground(DARKGRAY);

        BeginDrawing();


        switch (HUD.getSreenIndex())
        {
        case 1:    // MENU

            break;

        case 2:   // IN GAME
            mapManager.Draw();
            car.Update(GetFrameTime(), mapManager.FloorGrip());
            mapManager.Update();

            car.Draw();
            break;

        case 3:   // VICTORY / DEFEATE

            break;

        case 4:  //  LEVEL SELECTION

            break;

        case 5:  //  LEVEL EDITOR
            levelEditor.Update();
            break;
        default:
            break;
        }

        HUD.Update();
        EndDrawing();

    }

    mapManager.Unload();
    car.Unload();

    CloseWindow();
    return 0;
}