#ifndef INPUTBOX_H
#define INPUTBOX_H

#include <iostream>
#include "raylib.h"
class InputBox
{
private:
    std::string text;
    Rectangle bounds;
    bool isActive;
    int cursorPosition;
    const size_t maxLength;
public:
    InputBox(float x, float y, float width, float height, size_t maxLen = 100);
    void Update();
    void Draw();
    const std::string& GetText() const { return text;}
    void SetText(const std::string& newText) { text = newText;}
};
#endif
