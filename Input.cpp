#include "Input.hpp"

std::vector<std::string> Input::getCommand()
{
  std::string input;
  std::getline(std::cin, input);

  //convert to lower case
  toLowercase(input);

  command_ = split(input);

  parseCommands();
  parseNumberOfParameters();

  return command_;
}

std::vector<std::string> Input::split(std::string input)
{
  std::vector<std::string> command;
  int position = 0;

  while (position != -1)
  {
    position = input.find(' ');
    command.push_back(input.substr(0, position));
    input.erase(0, position + 1);
  }

  return command;
}

void Input::parseCommands()
{
  if (command_.at(0) != "help" &&
      command_.at(0) != "quit" &&
      command_.at(0) != "map" &&
      command_.at(0) != "flip" &&
      command_.at(0) != "unlock" &&
      command_.at(0) != "fight" &&
      command_.at(0) != "move" &&
      command_.at(0) != "scry")
  {
    throw ParseException("Please enter a KNOWN COMMAND to not confuse your treasure hunters!\n");
  }
}

void Input::parseNumberOfParameters()
{
  if ((command_.at(0) == "help" ||
       command_.at(0) == "quit" ||
       command_.at(0) == "map" ||
       command_.at(0) == "flip" ||
       command_.at(0) == "unlock" ||
       command_.at(0) == "fight") &&
      command_.size() == 1)
  {
    return;
  }
  else if (command_.at(0) == "move" && command_.size() == 4)
  {
    return;
  }
  else if (command_.at(0) == "scry" && command_.size() == 3)
  {
    return;
  }

  throw ParseException("Please enter a correct NUMBER OF PARAMETERS to not confuse your treasure hunters!\n");
}

void Input::parseSpecialCommands()
{
  if (command_.at(0) == "move")
  {
    parseMove();
  }
  else if (command_.at(0) == "scry")
  {
    parseScry();
  }
}

void Input::parseMove()
{
  parseMoveCharacter();
  parseMoveDirection();
  parseMoveDistance();
}

void Input::parseMoveCharacter()
{
  if (command_.at(1) != "f" && command_.at(1) != "t" && command_.at(1) != "s")
  {
    throw ParseException("Who do you want to move?!?\n");
  }
}

void Input::parseMoveDirection()
{
  if (command_.at(2) != "up" &&
      command_.at(2) != "down" &&
      command_.at(2) != "right" &&
      command_.at(2) != "left")
  {
    throw ParseException(command_.at(1) + ": \"I don't understand where I should go!\"\n");
  }
}

void Input::parseMoveDistance()
{
  for (char& number: command_.at(3))
  {
    if (number < '0' || number > '9')
    {
      throw ParseException(command_.at(1) + ": \"I don't understand how far I should go!\"\n");
    }
  }
}

void Input::parseScry()
{
  parseScryRoom();
  parseScryDirection();
}

void Input::parseScryRoom()
{

}

void Input::parseScryDirection()
{
  if (command_.at(2) != "up" &&
      command_.at(2) != "down" &&
      command_.at(2) != "right" &&
      command_.at(2) != "left")
  {
    throw ParseException("Seer: \"I don't understand which room I should scry!\"\n");
  }
}


//convert to lower case
void Input::toLowercase(std::string str) {

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32; //+32 to change to lower case - ASCII
        }
    }
}

//----------------------------------------------------------------------------------
// This method makes and returns an instance of the class Input
//
// @return - an instance of the class Input
//
Input& Input::instance()
{
    static Input instance_;
    return instance_;
}
