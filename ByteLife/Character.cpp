#include "Character.h"
#include <random>


Character::Character(const std::string& name, const std::string& surname)
    : _name(name)
    , _surname(surname)
    , _health(100)
    , _happiness(100)
    , _intelligence(100)
    , _age(1)
    , _looks(50),
    _money(0.0)
{
  _relationships.push_back("Father");
  _relationships.push_back("Mother");
  _skills.push_back(generateTalent());
}

Character::Skill Character::generateTalent()
{ 
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 3);
  return static_cast<Skill>(dis(gen));
}

//GETTERS
int Character::getHealth() const { return _health; }
int Character::getHealth() const { return _health; }
int Character::getAge() const { return _age; }
double Character::getMoney() const { return _money; }
int Character::getIntelligence() const { return _intelligence; }
int Character::getLooks() const { return _looks; }
std::string Character::getName() const { return _name; }
std::string Character::getSurname() const { return _surname; }
int Character::getHealth() const { return _health; }

//SETTERS
void setHealth(const int& hpValue);
void setAge(const int& ageValue);
void setMoney(const double& moneyValue);
void setIntelligence(const int& intelliValue);
void setLooks(const int& looksValue);
void setAssets(const std::string& name, const double& moneyValue);
void setRelationships(const std::string& name);
void setSkill(const Character::Skill& skillValue);
void setName(const std::string& name);
void setSurname(const std::string& surname);
Skill generateTalent();
void generateFather();
void generateMother();
void updateAge();
