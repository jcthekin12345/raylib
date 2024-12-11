#ifndef CHARACTER_H
#define CHARACTER_H
#include <unordered_map>
#include <string>






class Character {
 private:
  enum class Skill {
    MUSICAL,
    ATHLETIC,
    ARTISTIC,
    INTELLIGENT,
  };

  int _health;
  int _happiness;
  int _intelligence;
  int _looks;
  int _age;
  std::string _name;
  std::string _surname;
  double _money;

  std::unordered_map<std::string, double> _assets;
  std::vector<std::string> _relationships;
  std::vector<Skill> _skills;

 public:
  Character(const std::string& name, const std::string& surname);
  int getHealth() const;
  int getAge() const;
  double getMoney() const;
  int getIntelligence() const;
  int getLooks() const;
  std::string getName() const;
  std::string getSurname() const;
  std::unordered_map<std::string, double> getAssets() const;
  std::vector<std::string> getRelationships() const;
  std::vector<Skill> getSkills() const;

  void setHealth(const int& hpValue);
  void setAge(const int& ageValue);
  void setMoney(const double& moneyValue);
  void setIntelligence(const int& intelliValue);
  void setLooks(const int& looksValue);
  void setAssets(const std::string& name, const double& moneyValue);
  void setRelationships(const std::string& name);
  void setSkill(const Skill& skillValue);
  void setName(const std::string& name);
  void setSurname(const std::string& surname);
  Skill generateTalent();
  void generateFather();
  void generateMother();
  void updateAge();
};

#endif