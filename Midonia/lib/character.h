//
// Created by jctheking753 on 2024/12/10.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <random>
#include <vector>
#include <iostream>

enum class Gender { MALE, FEMALE, OTHER };
enum class LifeStage { CHILD, TEENAGER, ADULT, SENIOR };
enum class Education { NONE, PRIMARY, SECONDARY, UNIVERSITY };
enum class Career { UNEMPLOYED, STUDENT, ENTRY_LEVEL, MID_CAREER, EXECUTIVE };

struct Personality {
    int intelligence;
    int happiness;
    int health;
    int wealth;
    int social_skills;
};

class Character {
private:
    std::string name;
    Gender gender;
    int age;
    LifeStage current_stage;
    Personality stats;
    Education education_level;
    Career career;

    std::mt19937 rng{std::random_device{}()};

public:
    Character(std::string characterName, Gender characterGender)
        : name(std::move(characterName)),
          gender(characterGender),
          age(0),
          current_stage(LifeStage::CHILD),
          stats{50, 50, 50, 0, 50},
          education_level(Education::NONE),
          career(Career::UNEMPLOYED) {}

    void AgeUp() {
        age++;
        UpdateLifeStage();
        RandomLifeEvent();
    }

    int GetAge() const
    {
      return age;
    }


    void UpdateLifeStage() {
        if (age < 13) current_stage = LifeStage::CHILD;
        else if (age <=17) current_stage = LifeStage::TEENAGER;
        else if (age >=18) current_stage = LifeStage::ADULT;
        else current_stage = LifeStage::SENIOR;
    }

    void RandomLifeEvent() {
        std::uniform_int_distribution<> event_chance(1, 100);

        if (const int event = event_chance(rng); event <= 10) {
            // Positive event
            stats.happiness += 10;
            // Add more specific events based on life stage
        } else if (event > 90) {
            // Negative event
            stats.happiness -= 10;
            // Add more specific events
        }
    }

    void DisplayStatus() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Intelligence: " << stats.intelligence << std::endl;
        std::cout << "Happiness: " << stats.happiness << std::endl;
        std::cout << "Health: " << stats.health << std::endl;
        std::cout << "Wealth: " << stats.wealth << std::endl;
    }
};

#endif //CHARACTER_H
