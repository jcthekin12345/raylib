// SnakeGame.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//

#include <iostream>
#include "food.h"

int main() {
  InitWindow(cellCount * cellSize, cellCount * cellSize, "Retro Snake");
  SetTargetFPS(60);

  Food food = Food();

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(green);
    food.Draw();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}

