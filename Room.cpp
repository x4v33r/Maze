#include <iostream>

#include "Room.hpp"
#include "RoomInfo.hpp"
#include "MagicTile.hpp"
#include "BasicTile.hpp"
#include "ParseException.hpp"


//------------------------------------------------------------------------------
// This is the constructor of the class Room. Depending on the information 
// from the RoomInfo class, the Room is initialized and the map of the 
// room is filled with pointers to the actual tiles.
//
// @ param char room_id - this char tells the constructor, which kind of
//   Room it is.

Room::Room(char room_id, std::pair<int, int> global_coordinates)
{
  room_id_ = room_id;
  global_coordinates_ = global_coordinates;
  room_info_ = Oop::RoomInfo::getInstance().getRoomInfoString(room_id);

  if (room_info_.empty())
  {
    throw ParseException("Error: Invalid configuration!");
  }

  for (int lokal_y = 0; lokal_y < 5; ++lokal_y)
  {
    for (int lokal_x = 0; lokal_x < 5; ++lokal_x)
    {
      if (room_info_.at((lokal_y * 5) + lokal_x) == 'W' || room_info_.at((lokal_y * 5) + lokal_x) == 'P')
      {
        room_map_[std::pair<int, int>(lokal_x, lokal_y)] = new BasicTile(room_info_.at((lokal_y * 5) + lokal_x));
      }
      else
      {
        room_map_[std::pair<int, int>(lokal_x, lokal_y)] = new MagicTile(room_info_.at((lokal_y * 5) + lokal_x));
      }
    }
  }
}

//------------------------------------------------------------------------------
// This method sets the attribute of the Room to true, if one room is revealed
//
// @ param bool revealed - if already revealed, the bool is True

void Room::SetRoom(bool revealed)
{
  revealed_ = revealed;
}

//------------------------------------------------------------------------------
// This method returns the room ID which was inserted into the command line when
// starting the game
//
// @ return room_id_ - The inserted room ID from the command line argument

char Room::GetRoomID()
{
  return room_id_;
}

//------------------------------------------------------------------------------
// This method returns the previous filled map of the Room with the information
// about each tile.
//
// @ return room_map_ - The map of the Room

std::map<std::pair<int, int>, Tile*>& Room::GetRoomMap()
{
  return room_map_;
}


//------------------------------------------------------------------------------
// This method returns, whether one room is already revealed or not.
//
// @ return revealed - if already revealed, the bool is True

bool Room::GetRoomRevealed()
{
  return revealed_;
}


//------------------------------------------------------------------------------
// This method returns the attribute of the global coordinates without any
// parameters passed
//
// @ return global_coordinates_ - the global coorditates of one room

std::pair<int, int> Room::getGlobalCoordinates()
{
  return global_coordinates_;
}


//------------------------------------------------------------------------------
// This method returns the attribute of the global coordinates with passed
// parameters to set the coordinates
//
// @ param lokal_coordinates - the local coordinates of one room
// @ return the std::pair of integers of local coordinates of one room

std::pair<int, int> Room::getGlobalCoordinates(std::pair<int, int> lokal_coordinates)
{
  return std::pair<int, int>((global_coordinates_.first + lokal_coordinates.first),
                             (global_coordinates_.second + lokal_coordinates.second));
}


//------------------------------------------------------------------------------
// This method sets a player to the respective Tile by coordinates
//
// @ param character - a pointer to the respective character
// @ param lokal_coordinates - the local coordinates which define the game map
// @ return - no returnvalue

void Room::setPlayerToTile(std::shared_ptr<Character> character, std::pair<int, int> lokal_coordinates)
{
  room_map_.at(lokal_coordinates)->setCharacter(character);
}

// Geht das??

char Room::getPlayer(std::pair<int, int> lokal_coordinates)
{
  return room_map_.at(lokal_coordinates)->getCharacterPtr()->getSymbol();
}







