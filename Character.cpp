#include "Character.hpp"

char Character::getSymbol() const
{
  return type_;
}

std::pair<int, int> Character::getCoordinates()
{
  return coordinates_;
}

void Character::set_coordinates(std::pair<int, int> global_coordinates)
{
  coordinates_.first = global_coordinates.first;
  coordinates_.second = global_coordinates.second;
}

Character::Character(char type)
{
  if (type == 'F')
  {
    type_ = fighter_;
  }
  else if (type == 'T')
  {
    type_ = thief_;
  }
  else if (type == 'S')
  {
    type_ = seer_;
  }
}
