#include "GameBoard.hpp"


//----------------------------------------------------------------------------------
// This is a "getter" of the GameBoard class. It gives access to the private
// attribute "room_information_".
//
// @ return room_information_ - this is a std::string with the information about
//                              the order of the rooms

const std::string GameBoard::getRoomInformation()
{
  return room_information_;
}


//----------------------------------------------------------------------------------
// This is a "getter" of the GameBoard class. It gives access to the the layout
// of how the rooms are arranged on the game_board
//
// @ return rooms - this is a vector of vectors of Room pointers to the actual rooms

const std::vector<std::vector<Room *> > GameBoard::getRooms()
{
  return rooms_;
}


//----------------------------------------------------------------------------------
// This method creates a very well thought through game board consisting of a vector
// of Room pointers to the actual rooms.
//
// @ param room_layout - the room_layout holds all the information about the actual
//                       tiles, and how they are arranged
// @ return - no returnvalue

void GameBoard::createGameBoard(std::vector<std::string> room_layout)
{
  room_layout_ = room_layout;

  generateRooms();
  generateRoomInformation();
  generateCoordinates();
  generateCharacters();

  placeCharacters();
}


//------------------------------------------------------------------------------------
// This method generates an exact plan of the rooms, and inserts additional information
// in form of coordinates to be able to access certain Rooms later.
//
// @ return - no returnvalue

void GameBoard::generateRooms()
{
  int global_x = 1;
  int global_y = 1;
  for (std::string &row: room_layout_)
  {
    std::vector<Room *> room_row;
    for (char &room: row)
    {
      room_row.push_back(new Room(room, std::pair<int, int>(global_x, global_y)));
      global_x += 5;
    }

    rooms_.push_back(room_row);
    global_x = 1;
    global_y += 5;
  }
}


//----------------------------------------------------------------------------------
// This method takes the information from the command line and puts it into the 
// attribute room_information_ to be able to work further with this information
// 
// @ return - no returnvalue

void GameBoard::generateRoomInformation()
{
  for (std::string &row: room_layout_)
  {
    room_information_ += row;
  }
}


//----------------------------------------------------------------------------------
// This method generates coordinates to be able to access special regions on the 
// game board later.
// 
// @ return - no returnvalue

void GameBoard::generateCoordinates()
{
  coordinates_.first = room_layout_.at(0).size() * 5;
  coordinates_.second = room_layout_.size() * 5;
}


//----------------------------------------------------------------------------------
// This method generates the characters who will move on the board, and fills the
// attributes fighter_, thief_ and seer_ with pointers to the fitting characters
// 
// @ return - no returnvalue

void GameBoard::generateCharacters()
{
  fighter_ = std::make_shared<Character>('F');
  thief_ = std::make_shared<Character>('T');
  seer_ = std::make_shared<Character>('S');
}



//----------------------------------------------------------------------------------
// This method puts the characters to certain locations, based on the information in
// the coordinates.
// 
// @ return - no returnvalue

void GameBoard::placeCharacters()
{
  Room *start_room = findStartRoom();
  start_room->setPlayerToTile(fighter_, std::pair<int, int> (1, 1));
  start_room->setPlayerToTile(thief_, std::pair<int, int> (3, 1));
  start_room->setPlayerToTile(seer_, std::pair<int, int> (1, 3));

  fighter_->setCoordinates(start_room->getGlobalCoordinates(std::pair<int, int>(1, 1)));
  thief_->setCoordinates(start_room->getGlobalCoordinates(std::pair<int, int>(3, 1)));
  seer_->setCoordinates(start_room->getGlobalCoordinates(std::pair<int, int>(1, 3)));
}


//----------------------------------------------------------------------------------
// This method finds the starting room within the game board and returns a pointer
// to this room. 
// 
// @ return Room* - this is a pointer to the actual start room

Room *GameBoard::findStartRoom()
{
  for (auto &row: rooms_)
  {
    for (auto &room: row)
    {
      if (room->GetRoomID() == 'S')
      {
        return room;
      }
    }
  }
  //hier fehlt ein else return, ich hab nullptr hinzugefügt wegen warning
  return nullptr;
}


//---------------------------------------------------------------------------------------
// This method converts the information from the GameBoard game_board into a vector
// of vectors of strings, so that a following method can easily access each tile to print.
// Additional to that, it counts the number of rooms and rows as this is important for the
// printing algorithm
//
// @ param game_board - this is a vector of Room pointers to the actual rooms
// @ param all_tiles - the easier to access vector of vector of the strings of the tiles
// @ param rooms - the number of rooms to count
// @ param rows - the number of rows to count
// @ param revealed - checks, if the room is revealed
// @ return - no returnvalue

void GameBoard::prepareGameBoard(GameBoard& game_board, std::vector<std::vector<std::string> >& all_tiles,
                                  int& rooms, int& rows)
{
  std::string unknown_string{"UUUUUUU"};
  std::string start_room{'S'};
  std::vector<std::string> unknown_tile{unknown_string, unknown_string, unknown_string};

  std::vector<std::vector<Room*> > roomvector_vector = game_board.getRooms();
  std::string roominformation = game_board.getRoomInformation();

  int found_startroom = roominformation.find(start_room); //Looking for startroom with index of the roominformation
  int room_counter_roominfo{0};

  for (auto& roomvector : roomvector_vector) //einzelner raumvector
  {
    for(auto& room : roomvector) //einzelner raum
    {
      if(room_counter_roominfo == found_startroom) //Bessere Möglichkeit um Startroom zu finden?
      {
        room->SetRoom(true); // Startroom ist immer revealed. Bessere möglichkeit für zugriff?
      }
      std::map<std::pair<int, int>, Tile*> room_map = room->GetRoomMap();

      for (int lokal_y = 0; lokal_y < 5; ++lokal_y)
      {
        for (int lokal_x = 0; lokal_x < 5; ++lokal_x)
        {
          if(!room->GetRoomRevealed()) //Prüft ob room revealed
          {
            all_tiles.push_back(unknown_tile); //wenn nicht revealed -> alles mit UUUU printen
          }
          else //wenn revealed
          {
            bool player_here = room_map.at(std::pair<int, int>(lokal_x, lokal_y))->checkIfPlayerOnTile();
            if(player_here) //wenn ein player oben steht, mach entsprechende Tile
            {
              std::shared_ptr<Character> my_character = room_map.at(std::pair<int, int>(lokal_x, lokal_y))
                                                          ->getCharacterPtr();
              char symbol = my_character->getSymbol();
              std::vector<std::string> character_tile = room_map.at(std::pair<int, int>(lokal_x, lokal_y))
                                                        ->makeCharacterTile(symbol);
              all_tiles.push_back(character_tile);
            }
            else
            {
              std::vector<std::string> actual_tile = room_map.at(std::pair<int, int>(lokal_x, lokal_y))
                                                                  ->getTileString();
              all_tiles.push_back(actual_tile);
            }
          }
          rooms++;
        }
      }
      room_counter_roominfo++;
    }
    rows++;
  }
  rooms /= 25;
}


//---------------------------------------------------------------------------------------
// This method prints all the rooms row by row with a certain logic
//
// @ param all_tiles - the easier to access vector of vector of the strings of the tiles
// @ param rooms_per_row - the number of rooms to print per row
// @ param startvalue - the index to start to have access to the respective tile
// @ param roominfo_index - the index of the current letter of the roominfo 
// @ param position_counter - to find the exact position to insert the roominformation
// @ return - no returnvalue

void GameBoard::printLineByLine(std::vector<std::vector<std::string> >& all_tiles, int rooms_per_row, int startvalue,
                             int& roominfo_index, int& position_counter)
{
  int room = rooms_per_row;
  int vector_pos = 0;
  int end = 0;
  int str_pos = 0;
  int row = 0;
  std::string unrevealed{"UUUUUUU"};

  vector_pos = startvalue;
  end = vector_pos + 5;

  while (room > 0)
  {
    std::cout << "╬═══════════════════════════════════";
    room--;
  }
  std::cout << "╬" << std::endl;
  room = rooms_per_row;

  while(row < 5)
  {
    while (str_pos < 3)
    {
      while (room > 0) // eine Zeile tiles 
      {
        std::cout << "║"; //left horizontal frame
        for(; vector_pos < end; vector_pos++)
        {
          if((str_pos == 1) && (vector_pos == position_counter))
          {
            if((all_tiles.at(vector_pos).at(str_pos).compare(unrevealed)) == 0)
            {
              std::cout << unrevealed;
              position_counter += 25;
              roominfo_index++;
            }
            else
            {
              std::cout << "███" << room_information_.at(roominfo_index) << "███"; //Info of the Room
              position_counter += 25;
              roominfo_index++;
            }
            //std::cout << "███" << room_information_.at(roominfo_index) << "███"; //Info of the Room
            //position_counter += 25;
            //roominfo_index++;
          }
          else
          {
            std::cout << all_tiles.at(vector_pos).at(str_pos);
          }
        }
        vector_pos += 20;
        end += 25;
        room--;
      }
      std::cout << "║" << std::endl; //right horizontal frame

      str_pos++;
      vector_pos = startvalue;
      end = (startvalue + 5);
      room = rooms_per_row;
    }
    row++;
    startvalue += 5;
    str_pos = 0;
    vector_pos = startvalue;
    end = (startvalue + 5);
  }
  room = rooms_per_row;
}


//----------------------------------------------------------------------------------
// This method prints the game board with a certain logic. After preparing the game
// board and extracting informations, it loops line by line over each room.
// 
// @ param game_board - this is a vector of Room pointer to the actual rooms
// @ return - no returnvalue

void GameBoard::printGameBoard(GameBoard& game_board)
{  
  int rows{0};
  int rooms_number{0};
  int rooms_per_row{0};
  int roomscounter{0};
  int startvalue{0};
  int roominfo_index{0};
  int position_counter{0};
  std::vector<std::vector<std::string> > all_tiles;

  GameBoard::prepareGameBoard(game_board, all_tiles, rooms_number, rows);

  rooms_per_row = rooms_number / rows;
  roomscounter = rooms_per_row;

  while(rows > 0)
  {
    GameBoard::printLineByLine(all_tiles, rooms_per_row, startvalue, roominfo_index, position_counter);
    
    startvalue += (25 * rooms_per_row);
    rows--;
    rooms_per_row = roomscounter;
  }

  while (roomscounter > 0) // Print bottom frame
  {
    std::cout << "╬═══════════════════════════════════";
    roomscounter--;
  }
  std::cout << "╬" << std::endl;
}


