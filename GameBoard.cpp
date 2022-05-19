#include "GameBoard.hpp"

const std::string GameBoard::get_room_information()
{
  return room_information_;
}

const std::vector<std::vector<Room *> > GameBoard::get_rooms()
{
  return rooms_;
}

void GameBoard::create_game_board(std::vector<std::string> room_layout)
{
  room_layout_ = room_layout;

  generate_rooms();
  generate_room_information();
  generate_coordinates();
  generate_characters();

  place_characters();
}

void GameBoard::generate_rooms()
{
  int global_x = 1;
  int global_y = 1;
  for (std::string &row: room_layout_)
  {
    std::vector<Room *> room_row;
    for (char &room: row)
    {
      room_row.push_back(new Room(room, std::pair<int, int>(global_x, global_y)));
      global_x += 5;
    }

    rooms_.push_back(room_row);
    global_x = 1;
    global_y += 5;
  }
}

void GameBoard::generate_room_information()
{
  for (std::string &row: room_layout_)
  {
    room_information_ += row;
  }
}

void GameBoard::generate_coordinates()
{
  coordinates_.first = room_layout_.at(0).size() * 5;
  coordinates_.second = room_layout_.size() * 5;
}

void GameBoard::generate_characters()
{
  fighter_ = std::make_shared<Character>('F');
  thief_ = std::make_shared<Character>('T');
  seer_ = std::make_shared<Character>('S');
}

void GameBoard::place_characters()
{
  Room *start_room = find_start_room();
  start_room->setPlayerToTile(fighter_, std::pair<int, int> (1, 1));
  start_room->setPlayerToTile(thief_, std::pair<int, int> (3, 1));
  start_room->setPlayerToTile(seer_, std::pair<int, int> (1, 3));

  fighter_->set_coordinates(start_room->getGlobalCoordinates(std::pair<int, int>(1, 1)));
  thief_->set_coordinates(start_room->getGlobalCoordinates(std::pair<int, int>(3, 1)));
  seer_->set_coordinates(start_room->getGlobalCoordinates(std::pair<int, int>(1, 3)));
}

Room *GameBoard::find_start_room()
{
  for (auto &row: rooms_)
  {
    for (auto &room: row)
    {
      if (room->GetRoomID() == 'S')
      {
        return room;
      }
    }
  }
  //hier fehlt ein else return, ich hab nullptr hinzugefügt wegen warning
  return nullptr;
}
