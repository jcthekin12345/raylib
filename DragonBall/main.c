#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Character
{
    char name[50];
    double power_level;
    int age;

};

struct Character createCharacter(const char* name)
{
    struct Character player;
    strcpy(player.name, name);
    player.power_level = 1;
    player.age = 10;
    return player;
}

void ageUp(struct Character* player)
{
    player->age++;
}
void deathChance(struct Character* player)
{
    //TODO: CREATE DEATH CHANCE USING RANDOM NUMBERS
    //       FOR WHEN PLAYER REACHES 60
}
void train(struct Character* player)
{
    const double new_power_level = 1.0;
    const double bonus_power_level = 2.0 + new_power_level;

    if (player->age >= 20 && player->age % 5 == 0) {
        ageUp(player);
        player->power_level = bonus_power_level;
        printf("You've grown and trained, your new power level is: %.2f\n", player->power_level);
        printf("Congratulations! You've reached level %d!\n", player->age / 10);
    }
    else {
        ageUp(player);
        player->power_level += new_power_level;
        printf("Your power level has increased by: %.2f\n", new_power_level);
        printf("Your new power level is: %.2f\n", player->power_level);
    }
}

void displayPlayerInfo(struct Character* player)
{
    printf("Name: %s\n", player->name);
    printf("Power level: %f\n", player->power_level);
    printf("Age: %d\n", player->age);
    printf("Inventory: 'Coming soon'!\n");
    printf("Kills: 'Coming soon'!\n");
    printf("Money: 'Coming soon'!\n");
}

int main(void)
{
    char name[10];
    bool running = true;
    while (running) {
        printf("Enter your name: ");
        scanf("%s", name);
        running = false;
    }

    //============================================
    running = true;
    printf("Welcome, %s!\n", name);
    struct Character player = createCharacter(name);
    while (running) {
        char choice;
        printf("\nChoose an option:\n");
        printf("1. Train\n");
        printf("2. Display player info\n");
        printf("3. Exit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                train(&player);
                break;
            case '2':
                displayPlayerInfo(&player);
                break;
            case '3':
                running = false;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}