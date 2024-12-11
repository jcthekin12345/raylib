#include <iostream>
#include <random>

int main()
{
    std::mt19937 mt{};

    for (int count{1}; count <= 40; ++count)
    {
        std::cout << mt()
    }
}