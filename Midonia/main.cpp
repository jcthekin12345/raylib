#include "lib/character.h"
#include "lib/lifeEngine.h"
#include "lib/time.h"

void ui(GameDate &game_date)
{
    std::cout << "-------------------" << std::endl;
    std::cout << "Year: " << game_date.GetYear() << std::endl;
    std::cout << "Username:" << std::endl;
    std::cout << "Occupation:" << std::endl;
}
int main()
{
    GameDate game_date(2000);
    ui(game_date);
    return 0;
}