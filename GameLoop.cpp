#include <iostream>

#include "GameLoop.hpp"
#include "Random.hpp"
#include <array>
#include <queue>



//----------------------------------------------------------------------------------
// This method makes and returns an instance of the class GameLoop
//
// @return - an instance of the class GameLoop
//
GameLoop& GameLoop::instance()
{
  static GameLoop instance_;
  return instance_;
}

//----------------------------------------------------------------------------------
// This is the constructor of the class GameLoop. When addressed, it prints the
// welcome prompt.
//
GameLoop::GameLoop()
{
  std::cout << "Welcome to the magical OOP1 Maze!!!\n" << std::endl;
}



//----------------------------------------------------------------------------------
// This method loops over all the tiles with a certain logic, to print the gameboard.
// If the the rooms are next to each other, the rooms are to be printed next to each
// other.
//
// @ param tiles - a vector of vectors of the strings of the tiles
// @ param rooms - the amount of rooms to be printed
// @ param roominformation - the character of the room from the commandline

void GameLoop::printTilesNextToEachOther(std::vector<std::vector<std::string> > tiles, int rooms, std::string roominformation)
{
  int amount_of_tiles = rooms * 25;
  int roomcounter = rooms;
  int index = 0;
  int indexcount = 5;
  int row = 0;
  int five_times = 1;
  int roominfoctr = 0;

  while (roomcounter > 0)
  {
    if(roomcounter < rooms) //this means it is not the first room
    {
      std::cout << "═══════════════════════════════════╬";
    }
    else
    {
      std::cout << "╬═══════════════════════════════════╬"; //this is the first room
    }
    roomcounter--;
  }
  std::cout << "\n║"; //erster linebreak von dem Oberen Rahmen

  roomcounter = rooms;
  while(five_times < 6)
  {
    while (roomcounter > 0) //Für row = 0
    {
      for(; index < indexcount; index++)
      {
        std::cout << tiles.at(index).at(row);
      }
      std::cout << "║";
      index += 20;
      indexcount += 25;

      roomcounter--; //how often to do counter +25
    }
    std::cout << "\n║";

    roomcounter = rooms;
    index -= amount_of_tiles;
    indexcount -= amount_of_tiles;
    row = 1;
    
    while (roomcounter > 0) //Für row = 0
    {
      for(; index < indexcount; index++)
      {
        if((index == 0) || (index == 25) || (index == 50) || (index == 75) || (index == 100))
        {
          std::cout << "███" << roominformation.at(roominfoctr) << "███";
          roominfoctr++;
        }
        else
        {
          std::cout << tiles.at(index).at(row);
        }
      }
      std::cout << "║";
      index += 20;
      indexcount += 25;
      roomcounter--; //how often to do counter +25
    }
      std::cout << "\n║";

    roomcounter = rooms;
    index -= amount_of_tiles;
    indexcount -= amount_of_tiles;
    row = 2;
    while (roomcounter > 0) //Für row = 0
    {
      for(; index < indexcount; index++)
      {
        std::cout << tiles.at(index).at(row);
      }
      std::cout << "║";
      index += 20;
      indexcount += 25;

      roomcounter--; //how often to do counter +25
    }

    if(five_times < 5)
    {
      std::cout << "\n║";
    }
    else
    {
      std::cout << '\n';
    }
    roomcounter = rooms;
    index = 5 * five_times;
    indexcount = index + 5;
    five_times++; //erst 1, 2, 3, 4, 5
  }
  roomcounter = rooms;
}

//----------------------------------------------------------------------------------
// little ugly helperfunktion
//
// @ return - no returnvalue
void GameLoop::printBottomFrame(int roomcounter, int rooms)
{
  while (roomcounter > 0)
    {
      if(roomcounter < rooms) //this means it is not the first room
      {
        std::cout << "═══════════════════════════════════╬";
      }
      else
      {
        std::cout << "╬═══════════════════════════════════╬"; //this is the first room
      }
      roomcounter--;
    }
    std::cout << std::endl;
}




//----------------------------------------------------------------------------------
// This function iterates with a certain logic over the vector of vectors of tiles
// According to this information, the gameboard is printed
//
// @ param tiles - a vector of vectors of tiles, with the information about all tiles
// @ param rooms - the number of rooms to be printed
// @ param lines - in how many lines the rooms should be printed
// @ param roominformation - holds the Room-ID from the command line argument

void GameLoop::printAllRooms(std::vector<std::vector<std::string> > tiles, int rooms, int lines, std::string roominformation)
{
  int linecounter = lines;
  int roomcounter = rooms;
  int rooms_to_print_per_line = rooms/lines;
  size_t start = 0;
  size_t end = rooms_to_print_per_line;
  std::string roominfo_partitioned;
  int all_tiles = tiles.size();
  int tile_elements = all_tiles / lines;
  int vector_counter = 0;

  std::vector<std::vector<std::string> > partitioned_tiles;

  while(linecounter > 0)
  {    
    partitioned_tiles.clear();
    roominfo_partitioned.clear();

    for(; vector_counter < tile_elements; vector_counter++)
    {
      partitioned_tiles.push_back(tiles.at(vector_counter));
    }
    roominfo_partitioned = roominformation.substr(start, end);
    start = end;
    end = end + start;
    GameLoop::printTilesNextToEachOther(partitioned_tiles, rooms_to_print_per_line, roominfo_partitioned);
    tile_elements += (all_tiles / lines);
    linecounter--;
  }
  roomcounter = rooms_to_print_per_line;
  GameLoop::printBottomFrame(roomcounter, rooms_to_print_per_line);
}




//----------------------------------------------------------------------------------
// This method prints the GameBoard. It takes the information about each room, which
// before where stored into a vector of vectors of Room*
//
// @ returhis method prints the GameBoard. It takes the information about each room, which
// before where stored into a vector of vectors of Room*n - no returnvalue

void GameLoop::printGameBoard(GameBoard game_board)
{
  std::vector<std::vector<Room*> > rooms = game_board.get_rooms();
  std::string roominformation = game_board.get_room_information();
  std::vector<std::vector<std::string> > all_tiles;

  int line_counter = 0;
  int room_counter = 0;
  for (auto& roomvector : rooms) //einzelner raumvector
  {
    for(auto& room : roomvector) //einzelner raum
    {
      std::map<std::pair<int, int>, Tile*> room_map = room->GetRoomMap();
      // implementation of the new room_map format
      for (int lokal_y = 0; lokal_y < 5; ++lokal_y)
      {
        for (int lokal_x = 0; lokal_x < 5; ++lokal_x)
        {
          std::vector<std::string> actual_tile = room_map.at(std::pair<int, int>(lokal_x, lokal_y))->getTileString();
          all_tiles.push_back(actual_tile);
          room_counter++;
        }
      }
    }
    line_counter++;
  }
  room_counter /= 25;

  GameLoop::printAllRooms(all_tiles, room_counter, line_counter, roominformation);

}

//----------------------------------------------------------------------------------
// This method mixes the movement cards according to the description.
//
// 

void GameLoop::move_card()
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



