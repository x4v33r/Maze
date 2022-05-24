#include "Tile.hpp"
#include "MagicTile.hpp"

#include <iostream> //danach löschen

//------------------------------------------------------------------------------
// This is the constructor of the class MagicTile. Depending on the information 
// from the RoomInfo class, the MagicTile is initialized.
//
// @ param char roominfo - this char tells the constructor, which kind of
//                         Tile it is.

MagicTile::MagicTile(char roominfo)
{
  // laut angabe ist auch noch normale Tür "Door" dabei, aber ich finde die Angabe dazu nirgends

  if (roominfo == 'X')
  {
    for(int counter = 0; counter < 3; counter ++)
    {
      magic_chars_.push_back("███████");
    }
  }

  else if (roominfo == 'M')
  {
    magic_chars_.push_back("       ");
    magic_chars_.push_back("   M   ");
    magic_chars_.push_back("       ");
  }
  else if (roominfo == 'G')
  {
    magic_chars_.push_back(" \\   / ");
    magic_chars_.push_back("  | |  ");
    magic_chars_.push_back(" /   \\ ");
  }
  else if (roominfo == 'C')
  {
    magic_chars_.push_back("  / \\  ");
    magic_chars_.push_back(" |   | ");
    magic_chars_.push_back("  \\ /  ");
  }
  // die Nächsten zwei, "H" für horizontale Tür, und "V" für vertikale Tür eventuell nicht direkt in abgeleiteter Klasse
  // sondern vielleicht in die Elternklasse rein? und das Über den Konstruktor machen?
  else if (roominfo == 'H')
  {
    magic_chars_.push_back("       ");
    magic_chars_.push_back("███████");
    magic_chars_.push_back("       ");
  }
  else if (roominfo == 'V')
  {
    magic_chars_.push_back("   █   ");
    magic_chars_.push_back("   █   ");
    magic_chars_.push_back("   █   ");
  }
  else if (roominfo == 'L')
  {
    magic_chars_.push_back("$$$$$$$");
    magic_chars_.push_back("$     $");
    magic_chars_.push_back("$$$$$$$");
  }
  else if (roominfo == 'T')
  {
    magic_chars_.push_back("TTTTTTT");
    magic_chars_.push_back("T     T");
    magic_chars_.push_back("TTTTTTT");
  }
  else if (roominfo == 'F')
  {
    magic_chars_.push_back("FFFFFFF");
    magic_chars_.push_back("F     F");
    magic_chars_.push_back("FFFFFFF");
  }
  else if (roominfo == 'S')
  {
    magic_chars_.push_back("SSSSSSS");
    magic_chars_.push_back("S     S");
    magic_chars_.push_back("SSSSSSS");
  }
}


//-------------------------------------------------------------------------
// This method is a "getter" of the class MagicTile. It returns the strings
// to be printed as game board.
//
// @return magic_chars_ - returns the current attribute

std::vector<std::string>& MagicTile::getTileString() //const
{
  return magic_chars_;
}


//------------------------------------------------------------------------------
// This method changes the Tile into a 'Passage' after magic was used (e.g. by
// fighting a monster, or opening a door.)
//
// @ return - no returnvalue

void MagicTile::magicUsed() //eventuell ein anderer Übergabeparameter, der die Info über benutzte Magie beinhaltet
{
  for(int counter = 0; counter < 3; counter ++)
  {
    magic_chars_.push_back("       ");
  }
}
  
