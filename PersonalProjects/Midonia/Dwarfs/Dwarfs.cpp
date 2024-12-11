// Dwarfs.cpp : This file contains the 'main' function. Program execution begins
// and ends there.
//

#include <iostream>
#include <iomanip>
// Dwarf
class Dwarf {
 private:
  std::string _name{};
  std::string _surname{};
  float _health{100.0};
  int _age{0};

 public:
	 Dwarf() {}
  void set_name(const std::string name) { this->_name = name; }
  void set_surname(const std::string surname) { this->_surname = surname; }
  void set_age(const int age) { this->_age = age; }
  const std::string get_name() const { return _name; }
  const std::string get_surname() const { return _surname; }
  const int get_age() const { return _age; }
  void increase_health(float value)
  {
	  if (value == 100)
	  {
		  std::cout << "Nope...can't go over 100" << std::endl;
	  }
	  else if (value == 0)
	  {
		  std::cout << "nooo....can't go under 0" << std::endl;
	  }
	  else {
		  this->_health = value;
	  }
  }
  void dead()
  {
	  int choice{0};
	  std::cout << _name << " is dead" << std::endl;
	  while (true)
	  {
		  std::cout << "Would you like to start from over? (1/2): ";
		  std::cin >> choice; 
		  switch (choice)
		  {
		      case 1:
			      set_age(0);
			      increase_health(100);
			      break;
		      case 2:
			      std::cout << "Ok bye..." << std::endl;
			      break;
		  }
	  }
  }

  void get_health_status()
  {
	  if (_health == 50) {
		  std::cout << _name << std::setw(20) << "Good enough" << std::endl;
	  }
	  else if (_health <= 20) {
		  std::cout << _name << std::setw(10) << " Health is pretty bad" << std::endl;
	  }
	  else if (_health == 0) {
		  std::cout << _health << std::setw(10) << " nah he dead..." << std::endl;
		  dead();
	  }
  }
};

int main() {
  Dwarf joseph = Dwarf();
  joseph.set_age(10);
  joseph.set_name("Jc");
  joseph.set_surname("droaj");
  std::cout << joseph.get_age() << std::endl;
  std::cout << joseph.get_name() << std::endl;
  std::cout << joseph.get_surname() << std::endl;
  std::cout << joseph.get_health_status() << std::endl;
  return 0;
}
