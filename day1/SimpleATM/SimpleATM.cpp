// SimpleATM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>



class JATM
{
public:
    void cardReader()
    {
        std::cout << "Please enter your card number: ";
        std::string cardNumber;
        std::cin >> cardNumber;
        if (checkCard(cardNumber)) {
            pinInput();
   }    else {
        std::cout << "Invalid card number.\n";
   }
 }
};
int main()
{
    std::cout << "Hello World!\n";
}

