#ifndef TILE_HPP
#define TILE_HPP


#include <string>
#include <vector>
#include <memory>

#include "Character.hpp"


class Tile
{
private:
  std::vector<std::string> tile_chars_;
  std::shared_ptr<Character> character_ = nullptr;

public:
  Tile() {}
  Tile(const Tile &) = delete;                     // Copy Construkter mal deletet, brauchen wir ihn?
  virtual ~Tile() = default;  // den müssen wir vielleicht noch ändern falls irgendwo new verwendet wird. Oder wir nehmen die smart pointer

  void setCharacter(std::shared_ptr<Character> character);
  bool checkIfPlayerOnTile();
  std::shared_ptr<Character> getCharacterPtr();

  virtual std::vector<std::string>& getTileString() = 0; // laut Angabe pure virtual
  std::vector<std::string> makeCharacterTile(char character);


};


#endif
