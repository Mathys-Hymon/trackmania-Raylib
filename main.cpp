#include "raylib.h"
#include <iostream>



int main() {

    std::cout << "Hello World" << std::endl;

    InitWindow(1000, 600, "Trackmania Raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}