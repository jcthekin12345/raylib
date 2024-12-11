#include <iostream>

class Character
{
private:
    double _weight{};
public:
    Character(double weight);
};

Character::Character(double weight)
{
    this->_weight = {weight};
}

int main()
{
    Character Jctheking(34.5);
    return 0;
}