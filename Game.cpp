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
	//print game board
	game_board.printGameBoard(game_board);
		
	bool mapEnable = true;  //Enables or disables the game board output.

	//print >
	std::cout << "> ";

	while (true)
	{
		try {
			std::vector<std::string> commands = Input::instance().getCommand();

			if (commands[0] == "help")
			{//help
				std::cout << "- help\nPrints this help text.\n";
				std::cout << "- quit\nTerminates the game.\n";
				std::cout << "- map\nActivates or deactivates the map.\n";
				std::cout << "- flip\nChanges the possible move direction.\n";
				std::cout << "- move <CHARACTER> <DIRECTION> <DISTANCE>\n";
				std::cout << "	 Moves a character.\n";
				std::cout << "   <CHARACTER>: the character to move, T / F / S\n";
				std::cout << "   <DIRECTION> : the direction to move, up / down / left / right\n";
				std::cout << "   <DISTANCE> : optional, the distance to move\n";

				std::cout << "- unlock\nUnlocks a nearby door.\n";
				std::cout << "- fight\nFights a nearby monster.\n";
				std::cout << "- scry <KNOWN_ROOM> <DIRECTION>\n";
				std::cout << "	 Reveals an unknown room.\n";
				std::cout << "	 <KNOWN_ROOM>: where to scry from\n";
				std::cout << "	 <DIRECTION> : which direction to scry\n";
			}
			else if (commands[0] == "quit")
			{//QUIT
				break;
			}
			else if (commands[0] == "map")
			{//Enables or disables the game board output.
				mapEnable = !mapEnable;
			}
			else if (commands[0] == "move")
			{//Moves a character

				char ch = commands[1][0];  //t/ f/ s: Specifies which character to move (Thief, Fighter, Seer).
				std::string direction = commands[2]; //up/ down/ left/ right: Specifies which direction to move the character.

				//<distance>: The number of fields to walk (as a positive integer).
				//This is an optional additional parameter. 
				//If no distance is specified, the character moves exactly one space.
				int distance = 1;

				if (commands.size() == 4)
				{
					std::stringstream ss(commands[3]);
					ss >> distance;
				}

				//MOVE - TODO

				/*
				If, at the end of a movement, a character comes to a standstill on a square that is directly adjacent 
				to a previously unknown room, this room is automatically revealed.

				If a character lands on an hourglass space at the end of a movement, 
				the card flip counter is automatically reduced by 5 (minimum to 0). 
				The hourglass field turns into a normal gear.

				If all characters stand on the corresponding switch at the same time after the end of a movement, 
				all secret doors will be opened. All secret doors and all switches turn into a normal corridor.

				After the end of the movement, the card flip counter, the game plan (if game plan output is active), 
				the possible direction of movement and the prompt are output.
				*/

			}

			//print game board
			if (mapEnable)
			{
				//print game board
				game_board.printGameBoard(game_board);
			}

			//print >
			std::cout << "> ";
		}
		catch (const ParseException& ex) {
			std::cout << ex.what();
		}
	}
}


//----------------------------------------------------------------------------------
// Beschreibung!!
//
// 

void Game::move_card()
{
	size_t number_of_cards_left = 4;
	std::string cards[4] = { "up", "right", "down", "left" };
	std::queue<std::string> card_queue;
	Random& random_number = Random::getInstance();

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



