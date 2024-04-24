#include "raylib.h"
#include <iostream>
#include "Vehicle.h"
#include "MapManager.h"

int main() {

    InitWindow(800, 800, "Trackmania Raylib");
    SetTargetFPS(60);

    Vehicle car(Vector2{200,200}, Vector2{15,30}, 45);
    MapManager mapManager;

    mapManager.Initialize();

    while (!WindowShouldClose()) {
        BeginDrawing();

        car.Update(GetFrameTime(), 1);
        ClearBackground(GRAY);
        mapManager.Draw();
        car.Draw();
        EndDrawing();

    }

    CloseWindow();
    return 0;
}