#include "Tile.hpp"

void Tile::set_character(std::shared_ptr<Character> character)
{
  character_ = character;
}

bool Tile::get_character_pointer()
{
  if (character_ != nullptr)
  {
    return true;
  }
  return false;
}
