//
// Created by jctheking753 on 2024/12/10.
//

#ifndef LIFEENGINE_H
#define LIFEENGINE_H
#include "character.h"
#include <iostream>
#include <string>

struct Date
{
    int current_year{};
    Date(const int& year) : current_year(year){}
};

class LifeSimulatorGame {
private:
    Character* current_character;
    bool game_active;

public:
    LifeSimulatorGame() : current_character(nullptr), game_active(false) {}

    void CreateCharacter(std::string name, Gender gender) {
        current_character = new Character(name, gender);
        game_active = true;
    }

    void RunGameLoop() {
        // Game loop logic
        while (game_active) {
            current_character->AgeUp();
            current_character->DisplayStatus();

            // Simulated pause and choice mechanism
            // In a full game, this would be more interactive
            if (current_character->GetAge() >= 80) {
                game_active = false;
            }
        }
    }

    ~LifeSimulatorGame() {
        if (current_character) delete current_character;
    }
};
#endif //LIFEENGINE_H
