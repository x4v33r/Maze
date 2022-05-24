#ifndef BASICTILE_HPP
#define BASICTILE_HPP
#include "Tile.hpp"
#include <string>

class BasicTile : public Tile
{
  private:
    std::vector<std::string> basic_chars_;

  public:
    BasicTile(char roominfo); //Konstruktor

    BasicTile(const BasicTile&) = delete; //brauchen wir den copy-Konstruktor?
    ~BasicTile() = default; //achtung bei Memory Allokierung bitte ändern

    std::vector<std::string>& getTileString() override; //simple getter
    
};

#endif
