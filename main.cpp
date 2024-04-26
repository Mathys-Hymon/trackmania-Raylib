#include "raylib.h"
#include <iostream>
#include "MapManager.h"

int main() {

    InitWindow(1000, 1000, "Trackmania Raylib");
    SetTargetFPS(60);

    hudManager HUD(3);
    Vehicle car(Vector2{200,700}, Vector2{28,50}, 90);
    MapManager mapManager(car, HUD);


    mapManager.Initialize();

    while (!WindowShouldClose()) {

        ClearBackground(DARKGRAY);

        BeginDrawing();
        mapManager.Draw();
        car.Update(GetFrameTime(), mapManager.FloorGrip());
        HUD.Update();

        car.Draw();

        mapManager.Update();
        EndDrawing();

    }

    mapManager.Unload();
    car.Unload();

    CloseWindow();
    return 0;
}