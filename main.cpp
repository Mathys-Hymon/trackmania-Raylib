#include "raylib.h"
#include <iostream>
#include "Vehicle.h"

int main() {

    InitWindow(800, 800, "Trackmania Raylib");
    SetTargetFPS(60);

    Vehicle car(Vector2{200,200}, Vector2{30,60}, 45);


    while (!WindowShouldClose()) {
        std::cout << car.GetPosition().x;
        BeginDrawing();
        car.Draw();
        car.Update(GetFrameTime());
        ClearBackground(GRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}