// basic_calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class BasicCalculator
{
public:
	int add(int a, int b) { return a + b; }
	int subtract(int a, int b) { return a - b; }
	int multiply(int a, int b) { return a * b; }
	double divide(int a, int b) { if (b == 0) throw std::runtime_error("Division by zero"); return (double)a / b; }
};

int main()
{
	std::cout << "Basic Calculator\n";
	while (true)
	{
		BasicCalculator calc;
		int choice;
		std::cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Quit\n";
		std::cin >> choice;
		if (choice == 5) break;
		int a, b;
		std::cout << "Enter two numbers: ";
		std::getline(std::cin, std::string()); // clear input buffer for the next cin
	}
}
