// WeaponCreator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int calculateGrade(int *score)
{
	if (*score < 0 || *score > 100) {
		throw std::invalid_argument("Score must be between 0 and 100");
		return -1;
	}

	switch (*score / 10) {
	case 10:
	case 9:
		return 'A';
	case 8:
		return 'B';
	case 7:
		return 'C';
	default:
		return 'F';
	}
}
int main()
{
	int number = 43;
	double pi = 3.14159;
	int stackNumber = 42;
	int* heapNumber = new int(42);
	delete heapNumber;
	heapNumber = nullptr;

	//================================
	std::cout << "Grade is: " << calculateGrade(&number) << std::endl;
}

