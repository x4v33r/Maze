#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <string>
#include <vector>
#include <memory>

#include "Room.hpp"
#include "Character.hpp"

class GameBoard
{
  private:
    std::vector<std::string> room_layout_;
    std::vector<std::vector<Room*> > rooms_;
    std::pair<int, int> coordinates_;
    std::string room_information_;
    std::shared_ptr<Character> fighter_;
    std::shared_ptr<Character> thief_;
    std::shared_ptr<Character> seer_;

    void generateRooms();
    void generateRoomInformation();
    void generateCoordinates();
    void generateCharacters();
    void placeCharacters();

    Room *findStartRoom();

  public:
    GameBoard() = default;

    void createGameBoard(std::vector<std::string> room_layout);
    const std::string getRoomInformation();
    const std::vector<std::vector<Room*> > getRooms();

    void prepareGameBoard(GameBoard& game_board, std::vector<std::vector<std::string> >& all_tiles, 
                          int& rooms, int& rows);

    void printLineByLine(std::vector<std::vector<std::string> >& all_tiles, int rooms_per_row, int startvalue,
                      int& roominfo_index, int& position_counter);

    void printGameBoard(GameBoard& game_board);
};

#endif //GAMEBOARD_HPP
