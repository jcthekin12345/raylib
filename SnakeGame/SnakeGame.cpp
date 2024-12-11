// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <raylib.h>

Color green {173,204,96,255};
Color darkgreen {43, 51, 24, 255};

int cellSize {30};
int cellCount{25};

class Food
{
	 
 public:
  Vector2 position{5, 6};
  Texture2D texture;

  Food() 
  { 
	Image image = LoadImage("food.png");
    texture  =  LoadTextureFromImage(image); 
	UnloadImage(image);
  }
  ~Food()
  { 
	UnloadTexture(texture);
  }
  void Draw() 
  { 
	DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);

  }
};

int main() { 
	InitWindow(cellCount * cellSize, cellCount * cellSize, "Retro Snake");  
	SetTargetFPS(60);
    
	Food food = Food();  

	while (!WindowShouldClose())
	{
          BeginDrawing();
		  
		  ClearBackground(green);
          food.Draw();
          EndDrawing();
	}

	CloseWindow();
    return 0;
}

