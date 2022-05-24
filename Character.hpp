#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>

enum character_classes
{
  fighter_ = 'F',
  thief_ = 'T',
  seer_ = 'S'
};

class Character
{
public:
  Character(char type);

  char getSymbol() const;
  std::pair<int, int> getCoordinates();
  void setCoordinates(std::pair<int, int> global_coordinates);

private:
  character_classes type_;
  std::pair<int, int> coordinates_;

};

#endif // ROOM_HPP
