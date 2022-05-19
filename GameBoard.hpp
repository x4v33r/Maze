#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <string>
#include <vector>
#include <memory>

#include "Room.hpp"
#include "Character.hpp"

class GameBoard
{
public:
  GameBoard() = default;

  void create_game_board(std::vector<std::string> room_layout);
  const std::string get_room_information();
  const std::vector<std::vector<Room*> > get_rooms();

private:
  std::vector<std::string> room_layout_;
  std::vector<std::vector<Room*> > rooms_;
  std::pair<int, int> coordinates_;
  std::string room_information_;
  std::shared_ptr<Character> fighter_;
  std::shared_ptr<Character> thief_;
  std::shared_ptr<Character> seer_;

  void generate_rooms();
  void generate_room_information();
  void generate_coordinates();
  void generate_characters();
  void place_characters();

  Room *find_start_room();
};

#endif //GAMEBOARD_HPP
