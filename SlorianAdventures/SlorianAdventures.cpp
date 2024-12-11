// SlorianAdventures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "raylib.h"


typedef enum GameScreen {
    TITLE = 0,
    GAMEPLAY,
    ENDING
} GameScreen;

class InputBox {
private:
    std::string text;
    Rectangle bounds;
    bool isActive;
    int cursorPosition;
    const size_t maxLength;

public:
    InputBox(float x, float y, float width, float height, size_t maxLen = 100) 
        : bounds{x, y, width, height}, isActive(false), cursorPosition(0), maxLength(maxLen) {}

    void Update() {
        // Check if box is clicked
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            isActive = CheckCollisionPointRec(GetMousePosition(), bounds);
        }

        if (!isActive) return;

        // Handle regular text input
        int key = GetCharPressed();
        while (key > 0 && text.length() < maxLength) {
            text.insert(cursorPosition, 1, static_cast<char>(key));
            cursorPosition++;
            key = GetCharPressed();
        }

        // Handle special keys
        if (IsKeyPressed(KEY_BACKSPACE) && cursorPosition > 0) {
            text.erase(--cursorPosition, 1);
        }
        if (IsKeyPressed(KEY_LEFT) && cursorPosition > 0) {
            cursorPosition--;
        }
        if (IsKeyPressed(KEY_RIGHT) && cursorPosition < text.length()) {
            cursorPosition++;
        }
    }

    void Draw() {
        DrawRectangleRec(bounds, LIGHTGRAY);
        DrawText(text.c_str(), bounds.x + 5, bounds.y + 5, 20, BLACK);

        // Draw cursor if active
        if (isActive) {
            float cursorX = bounds.x + 5 + MeasureText(text.substr(0, cursorPosition).c_str(), 20);
            DrawLine(cursorX, bounds.y + 5, 
                    cursorX, bounds.y + bounds.height - 5, 
                    BLACK);
        }
    }

    const std::string& GetText() const { return text; }
    void SetText(const std::string& newText) { text = newText; }
};


int main(void) {
    // Initialize window
    InitWindow(800, 600, "Window Management Example");
    SetTargetFPS(60);
    
    // Initialize game state
    GameScreen currentScreen = TITLE;
    
    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        switch(currentScreen) {
            case TITLE:
                // Update TITLE screen
                if (IsKeyPressed(KEY_ENTER)) currentScreen = GAMEPLAY;
                break;
                
            case GAMEPLAY:
                // Update GAMEPLAY screen
                if (IsKeyPressed(KEY_E)) currentScreen = ENDING;
                break;
                
            case ENDING:
                // Update ENDING screen
                if (IsKeyPressed(KEY_ENTER)) currentScreen = TITLE;
                break;
                
            default: break;
        }
        
        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            switch(currentScreen) {
                case TITLE:
                    DrawText("WELCOME TO MIDONIA LIFE", 320, 250, 20, BLACK);
                    DrawText("PRESS ENTER to PLAY", 290, 280, 20, GRAY);
                    break;
                    
                case GAMEPLAY:
                    DrawText("", 320, 250, 20, BLACK);
                    
                    break; 
                    
                case ENDING:
                    DrawText("ENDING SCREEN", 320, 250, 20, BLACK);
                    DrawText("PRESS ENTER to RESTART", 290, 280, 20, GRAY);
                    break;
                
                default: break;
            }
            
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
