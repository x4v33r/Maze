#ifndef MAGICTILE_HPP
#define MAGICTILE_HPP

class MagicTile : public Tile 
{
  private:
    std::vector<std::string> magic_chars_;
    bool magic_used_;

  public:
    MagicTile(char roominfo); //Constructor
    MagicTile(const MagicTile&) = delete; //brauchen wir den copy-Konstruktor?
    ~MagicTile() = default; //eventuell ändern/ausbauen

   std::vector<std::string>& getTileString() override;
   void magicUsed();
};

#endif
