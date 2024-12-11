#pragma once
#include <unordered_map>
#include <vector>
#include <string>

class Dragon {
 public:
  Dragon(const std::string& dragonName, const std::string clanName);

 private:
	 enum class PowerType
	 {
		 FIRE,
		 ICE,
		 WATER,
		 EARTH,
		 COSMIC,
		 BLACKHOLE, 
	 };

  int _health;
  bool _isAlive;
  std::unordered_map<std::string, Dragon> _clanMembers;
  std::string _clanName;
  std::string _dragonName;
  PowerType _dragonType;
};
