#include "Tile.hpp"
#include "BasicTile.hpp"

#include <iostream>
//-------------------------------------------------------------------------
// This method returns the attribute of class BasicTile
//
// @return returns the attribute

std::vector<std::string>& BasicTile::getTileString() //const
{
  return basic_chars_;
}

//------------------------------------------------------------------------------
// This is the constructor of the class BasicTile. Depending on the information 
// from the RoomInfo class, the BasicTile is initialized.
//
// @ param char roominfo - this char tells the constructor, which kind of
//                         Tile it is.

BasicTile::BasicTile(char roominfo)
{
  if (roominfo == 'W')
  {
    for(int counter = 0; counter < 3; counter ++)
    {
      basic_chars_.push_back("███████");
    }

  }
  else if (roominfo == 'P')
  {
    for(int counter = 0; counter < 3; counter ++)
    {
      basic_chars_.push_back("       ");
    }
  }
}



