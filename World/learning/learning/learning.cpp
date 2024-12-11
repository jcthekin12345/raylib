#include <iostream>

#include "raylib.h"
#include <cstdlib>
#include <ctime>
#include <string>
int main() {
  // Create our game window
  InitWindow(1500, 700, "My First Game");
  SetTargetFPS(60);  // Try to run at 60 frames per second

  srand(time(0));

  float x = 400.0f;
  float y = 300.0f;

  float targetX = 600.0f;
  float targetY = 500.0f;

  float speed = 30.5f;

  float hungryBar = 100.0f;

  float FoodShopX = 150.0f;
  float FoodShopY = 200.0f;

  while (!WindowShouldClose()) 
  {
    float Delta = GetFrameTime();
    hungryBar -= 20.5f * Delta;

    if (hungryBar <= 0 && x < FoodShopX) x += speed * Delta;
    if (hungryBar <= 0 && x > FoodShopX) x -= speed * Delta;
    if (hungryBar <= 0 && y < FoodShopY) y += speed * Delta;
    if (hungryBar <= 0 && y > FoodShopY) y -= speed * Delta;

    std::string hungryBarText = std::to_string(hungryBar);
    const char* result = hungryBarText.c_str();
    if (x == FoodShopX && y == FoodShopY) hungryBar -= 100.0f;
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(result, 10, 10, 20, BLACK);
        DrawCircle(x, y, 50, RED);
        DrawCircle(targetX, targetY, 50, BLUE);
        DrawRectangle(FoodShopX, FoodShopY, 50, 50, YELLOW);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}