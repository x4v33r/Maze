#ifndef GAMELOOP_HPP
#define GAMELOOP_HPP

#include <vector>

#include "Room.hpp"
#include "RoomInfo.hpp"
#include "Tile.hpp"
#include "BasicTile.hpp"
#include "MagicTile.hpp"
#include "GameBoard.hpp"
#include <map>

using namespace Oop;

class GameLoop
{
  public:
    GameLoop();
    GameLoop(const GameLoop&);
    GameLoop& operator=(const GameLoop&);
      ~GameLoop() = default;

    void printTilesNextToEachOther(std::vector<std::vector<std::string>> tiles, int rooms, std::string roominformation);
    void printBottomFrame(int roomcounter, int rooms);
    void printAllRooms(std::vector<std::vector<std::string>> tiles, int rooms, int lines, std::string roominformation);
    void printGameBoard(GameBoard game_board);

    void move_card();
    static GameLoop& instance();
};
#endif //GAMELOOP_HPP
