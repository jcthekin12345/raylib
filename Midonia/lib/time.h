//
// Created by jctheking753 on 2024/12/10.
//

#ifndef TIME_H
#define TIME_H
#include <stdexcept>

//GAME DATE STRUCT
struct GameDate
{
  int current_year{};

  explicit GameDate(const int &year) : current_year(year)
  {
  }

  void UpdateYear()
  {
    ++current_year;
  }
  std::string GetYear() const
  {
    std::string current_year_str{std::to_string(current_year)};
    return current_year_str;
  }
};

//TIME MANAGER
class TimeManager
{
private:
  GameDate game_time{0};

public:
  TimeManager()=default;

  explicit TimeManager(const int& new_time) : game_time{new_time} {}
  void UpdateTime()
  {
    game_time.UpdateYear();
  }
};

#endif //TIME_H
