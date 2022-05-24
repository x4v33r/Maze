#include "Character.hpp"

//-------------------------------------------------------------------------
// This is the constructor of the Character class. It sets the character
// to the respective char
//
// @ return - no returnvalue

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


//-------------------------------------------------------------------------
// This Method returns the enum of the respective character as char
//
// @ return - the enum of the repective character as char 

char Character::getSymbol() const
{
  return type_;
}


//-------------------------------------------------------------------------
// This Method finds out the exact position of one character
//
// @ return - the coordinates in form of a std::pair of integer 

std::pair<int, int> Character::getCoordinates()
{
  return coordinates_;
}


//-------------------------------------------------------------------------
// This Method sets the coordinates of the respective character 
//
// @ return - no returnvalue

void Character::setCoordinates(std::pair<int, int> global_coordinates)
{
  coordinates_.first = global_coordinates.first;
  coordinates_.second = global_coordinates.second;
}




