#include "Utils.hpp"

void Utils::check_game_board_length(std::vector<std::string> &room_layout)
{
  int row_length = int((room_layout)[0].length());

  if (row_length > 5)
  {
    throw ParseException("Error: Invalid configuration!");
  }
}

void Utils::check_capital_letters(std::vector<std::string> &room_layout)
{
  for (std::string &row : (room_layout))
  {
    for (char &room : row)
    {
      if (room < 'A' || room > 'Z')
      {
        throw ParseException("Error: Invalid configuration!");
      }
    }
  }
}

void Utils::check_starting_room(std::vector<std::string> &room_layout)
{
  for (std::string &row : (room_layout))
  {
    for (char &room : row)
    {
      if (room == 'S')
      {
        return;
      }
    }
  }

  throw ParseException("Error: Invalid configuration!");
}

void Utils::check_double_rooms(std::vector<std::string> &room_layout)
{
  std::vector<char> rooms;

  for (std::string &row : (room_layout))
  {
    for (char &room : row)
    {
      for (char &existing : rooms)
      {
        if (room == existing)
        {
          throw ParseException("Error: Invalid configuration!");
        }
      }

      rooms.push_back(room);
    }
  }
}

void Utils::check_rectangularity(std::vector<std::string> &room_layout)
{
  int first_row_length = int((room_layout)[0].length());

  for (const std::string &row : (room_layout))
  {
    int row_length = row.length();
    if (row_length != first_row_length)
    {
      throw ParseException("Error: Invalid configuration!");
    }
  }
}

void Utils::parseFile(std::vector<std::string> &room_layout)
{
  check_game_board_length(room_layout);
  check_capital_letters(room_layout);
  check_starting_room(room_layout);
  check_double_rooms(room_layout);
  check_rectangularity(room_layout);
}
