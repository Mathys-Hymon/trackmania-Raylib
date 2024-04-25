#include "raylib.h"
#include <iostream>
#include "MapManager.h"

int main() {

    InitWindow(1000, 1100, "Trackmania Raylib");
    SetTargetFPS(60);

    Vehicle car(Vector2{200,200}, Vector2{28,50}, 45);
    MapManager mapManager;

    mapManager.Initialize();

    while (!WindowShouldClose()) {
        BeginDrawing();
        mapManager.Draw();
        car.Update(GetFrameTime(), mapManager.FloorGrip(car));

        ClearBackground(DARKGRAY);

        car.Draw();
        EndDrawing();

    }

    mapManager.Unload();
    car.Unload();

    CloseWindow();
    return 0;
}