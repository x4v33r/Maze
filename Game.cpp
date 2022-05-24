#include <iostream>

#include "Game.hpp"
#include "Random.hpp"
#include <array>
#include <queue>



//----------------------------------------------------------------------------------
// This method makes and returns an instance of the class Game
//
// @return - an instance of the class Game
//
Game& Game::instance()
{
  static Game instance_;
  return instance_;
}

//----------------------------------------------------------------------------------
// This is the constructor of the class Game. When addressed, it prints the
// welcome prompt.
//
Game::Game()
{
  std::cout << "Welcome to the magical OOP1 Maze!!!\n" << std::endl;
}


//----------------------------------------------------------------------------------
// With this method, the gameloop starts. First of all, the board is printed. 
//
// 

void Game::startGame(GameBoard& game_board)
{

  game_board.printGameBoard(game_board);
}



//----------------------------------------------------------------------------------
// Beschreibung!!
//
// 

void Game::move_card()
{
  size_t number_of_cards_left = 4;
  std::string cards[4] = {"up", "right", "down", "left"};
  std::queue<std::string> card_queue;
  Random &random_number = Random::getInstance();

  // std::cout << random_numbers;
  while (card_queue.size() <= 4)
  {
    int number = random_number.getRandomCard(number_of_cards_left);
    if (number == 1)
    {
      card_queue.push(cards[number]);
      cards[number] = " ";
    }
    else if (number == 2)
    {
      card_queue.push(cards[number]);
      cards[number] = " ";
    }
    else if (number == 3)
    {
      card_queue.push(cards[number]);
      cards[number] = " ";
    }
    else if (number == 4)
    {
      card_queue.push(cards[number]);
      cards[number] = " ";
    }
    number_of_cards_left--;
  }
}



