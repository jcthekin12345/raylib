#include <iostream>
#include "tableData.hpp"

enum TableOptions
{
    ONES,
    TWOS,
    THREES,
    FOURS,
    FIVES,
    SIXS,
    SEVENS,
    EIGHTS,
    NINES,
    TENS,
    ELEVENS,
    TWELVES,
};

int main()
{
    std::string userInput;
    while (true)
    {
        std::cout << "What table do you want?" << std::endl;
        std::getline(std::cin, userInput);

    }
    return 0;
}
