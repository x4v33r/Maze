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
  //Tile(char tile_char) : tile_chars_{tile_char} {}
  Tile(const Tile &) = delete;                     // Copy Construkter mal deletet, brauchen wir ihn?
  virtual ~Tile() = default;  // den müssen wir vielleicht noch ändern falls irgendwo new verwendet wird. Oder wir nehmen die smart pointer

  void set_character(std::shared_ptr<Character> character);
  bool get_character_pointer();
  virtual std::vector<std::string>& getTileString() = 0; // laut Angabe pure virtual
};

#endif
