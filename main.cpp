//---------------------------------------------------------------------------------------------------------------------
// main.cpp
//
// <Explanation of the program ...>
// <... May have multiple lines.>
//
// Author: 12110622
//---------------------------------------------------------------------------------------------------------------------
//
#include <iostream>
#include <vector>
#include <string>

#include "GameLoop.hpp"
#include "RoomInfo.hpp"
#include "Room.hpp"
#include "BasicTile.hpp"
#include "MagicTile.hpp"
#include "ParseException.hpp"
#include "Character.hpp"
#include "GameBoard.hpp"

#include "Utils.hpp"

//---------------------------------------------------------------------------------------------------------------------
///
/// This is the main funktion. That's it.
///
/// @param argc number of parameters
/// @param argv array containing the parameters
///
/// @return (hopefully) 0
///         2 if the configuration is invalid
//
int main(int argc, char *argv[])
{
  std::vector<std::string> room_layout;
  GameBoard game_board;

  try
  {
    if (argc < 2 || argc > 6)
    {
      throw ParseException("Error: Invalid configuration!");
    }

    for (int i = 1; i < argc; ++i)
    {
      room_layout.push_back(std::string(argv[i]));
    }

    Utils::parseFile(room_layout);
    game_board.create_game_board(room_layout);
  }
  catch(ParseException& exception)
  {
    std::cout << exception.what() << std::endl;
    return 2;
  }

  GameLoop &game = GameLoop::instance();

  game.printGameBoard(game_board);

  return 0;
}
