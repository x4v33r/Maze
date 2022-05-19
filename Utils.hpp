#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

#include "ParseException.hpp"

class Utils
{
private:
  Utils() = delete;
  Utils(const Utils &) = delete;
  ~Utils() = default;

  static void check_game_board_length(std::vector<std::string> &room_layout);
  static void check_capital_letters(std::vector<std::string> &room_layout);
  static void check_starting_room(std::vector<std::string> &room_layout);
  static void check_double_rooms(std::vector<std::string> &room_layout);
  static void check_rectangularity(std::vector<std::string> &room_layout);

public:
  static void parseFile(std::vector<std::string> &room_layout);

};

#endif //UTILS_HPP
