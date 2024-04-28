#include "raylib.h"
#include <iostream>
#include "LevelEditor.h"
#include "MapSelection.h"

int main() {

    InitWindow(1000, 1000, "Trackmania Raylib");
    SetTargetFPS(60);

    hudManager HUD(3);
    Vehicle car(Vector2{200,700}, Vector2{28,50}, 90);
    MapManager mapManager(car, HUD);
    MapSelection mapSelection(HUD, mapManager);
    LevelEditor levelEditor(GetScreenWidth(), GetScreenHeight(), HUD);

    mapManager.Initialize();

    while (!WindowShouldClose()) {

        ClearBackground(RAYWHITE);

        BeginDrawing();


        switch (HUD.getSreenIndex())
        {
        case 2:   // IN GAME
            mapManager.Draw();
            car.Update(GetFrameTime(), mapManager.FloorGrip());
            mapManager.Update();

            car.Draw();
            break;

        case 4:  //  LEVEL SELECTION
            mapSelection.SelectMap();
            mapSelection.Update();
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