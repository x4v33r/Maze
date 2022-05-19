#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <vector>
#include <map>
#include <memory>

#include "Tile.hpp"
#include "Character.hpp"

class Room
{
public:
  Room(char room_id, std::pair<int, int> global_coordinates);

  char GetRoomID();
  bool GetRoomRevealed();
  std::map<std::pair<int, int>, Tile*>& GetRoomMap();
  std::pair<int, int> getGlobalCoordinates();
  std::pair<int, int> getGlobalCoordinates(std::pair<int, int> lokal_coordinates);

  void SetRoom(bool revealed);
  void setPlayerToTile(std::shared_ptr<Character> character, std::pair<int, int> lokal_coordinates);

private:
  char room_id_;
  bool revealed_;
  std::string room_info_;
  std::map<std::pair<int, int>, Tile*> room_map_;
  std::pair<int, int> global_coordinates_;

};

#endif
