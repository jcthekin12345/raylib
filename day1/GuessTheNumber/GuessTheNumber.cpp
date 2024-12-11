// GuessTheNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class GuessTheNumber {
  int secretNumber;
  int attempts;

private:

 public:
  int guess;
  GuessTheNumber() : secretNumber(0), attempts(0), guess(0) {}
  void generateSecretNumber(int new_number = 0) { 
      secretNumber = rand() % 100 + 1; 
  }
  void update()
  { 
      while (true) {
        int guess;
        std::cout << "Guess the number (between 1 and 100): ";
        std::cin >> guess;
        attempts++;
      }
  }
  void displayResult() {
    if (attempts == 1) {
      std::cout << "You've made " << attempts << " attempt.\n";
    } else {
      std::cout << "You've made " << attempts << " attempts.\n";
    }
    if (guess == secretNumber) {
      std::cout << "Congratulations! You guessed the number in " << attempts
                << " attempts.\n";
    } else {
      std::cout << "Sorry, the number was " << secretNumber
                << ". You guessed it in " << attempts << " attempts.\n";
    }
  }
  int getAttempts() { return attempts; }
  void resetAttempts() { attempts = 0; }
  bool isGameOver() { return attempts >= 7; }
  bool isNumberGuessed() { return guess == secretNumber; }
  int getSecretNumber() { return secretNumber; }
  void setGuess(int new_guess) { guess = new_guess; }
  GuessTheNumber(int new_number)
      : secretNumber(new_number), attempts(0), guess(0) {}
  ~GuessTheNumber() { std::cout << "Game over.\n"; }
};
int main()
{
  GuessTheNumber game(0);
  game.generateSecretNumber();
  game.update();
  game.displayResult();
  return 0;
}

