#include "Tile.hpp"

//------------------------------------------------------------------------------
// This method sets the player to the attribute character_ by a shared pointer 
//
// @ return - no returnvalue

void Tile::setCharacter(std::shared_ptr<Character> character)
{
  character_ = character;
}


//------------------------------------------------------------------------------
// This checks, if a character is on the respective Tile or not
//
// @ return true/false - true, if a character is on the Tile, false if not

bool Tile::checkIfPlayerOnTile()
{
  if(character_)
  {
    return true;
  }
  return false;
}





//------------------------------------------------------------------------------
// This method returns the shared pointer to the respective character player.
//
// @ return character_ - the pointer to the respective player on the tile

std::shared_ptr<Character> Tile::getCharacterPtr()
{
  return character_;
}

//------------------------------------------------------------------------------
// This Method develops a Tile depending on the character who is on it 
//
// @ param character - the character that represents the player on the field
// @ return tile - the representation of the tile with the player standing on it

std::vector<std::string> Tile::makeCharacterTile(char character)
{
  std::string path{"       "};
  std::string half_path{"   "};
  std::vector<std::string> tile;

  std::string player_tile = half_path + character + half_path;

  tile.push_back(path);
  tile.push_back(player_tile);
  tile.push_back(path);

return tile;
}