
#include <iostream>
#include "templates.cpp"

int main()
{
	int theWinner{ max<int>(5,10) };
	std::cout << "The winner is:  " << theWinner << std::endl;
	return 0;
}

