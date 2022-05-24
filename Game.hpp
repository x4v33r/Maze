#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "Room.hpp"
#include "RoomInfo.hpp"
#include "Tile.hpp"
#include "BasicTile.hpp"
#include "MagicTile.hpp"
#include "GameBoard.hpp"
#include <map>

using namespace Oop;

class Game
{
  public:
    Game();
    Game(const Game&);
    Game& operator=(const Game&);
      ~Game() = default;

    void startGame(GameBoard& game_board);

    void move_card();
    static Game& instance();
};
#endif //GAME_HPP
