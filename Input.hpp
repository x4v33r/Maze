#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>
#include <string>
#include <vector>

#include "ParseException.hpp"

class Input
{
public:
  std::vector<std::string> getCommand();

private:
  std::vector<std::string> command_;

  Input() = delete;
  Input(const Input &) = delete;
  ~Input() = default;

  std::vector<std::string> split(std::string input);
  void parseCommands();
  void parseNumberOfParameters();
  void parseSpecialCommands();
  void parseMove();
  void parseScry();
  void parseMoveCharacter();
  void parseMoveDirection();
  void parseMoveDistance();
  void parseScryRoom();
  void parseScryDirection();
};

#endif //INPUT_HPP
