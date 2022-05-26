#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>
#include <string>
#include <vector>

#include "ParseException.hpp"

class Input
{
public:
	static Input& instance();
	std::vector<std::string> getCommand();

private:
  std::vector<std::string> command_;

  Input() = default;
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

  //convert to lower case
  void toLowercase(std::string str);
};

#endif //INPUT_HPP
