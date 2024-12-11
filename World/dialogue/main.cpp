#include <iostream>
#include "Dialogue.h"
int main()
{
    auto dialogue = DialogueManager();
    dialogue.addDialogue("Drago", "Welcome to Midonia. What can I get you?", "Happy");
    dialogue.findDialogueLinear("Welcome to Midonia");



    return 0;
}