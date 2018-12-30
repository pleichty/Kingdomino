#ifndef TILE_HPP
#define TILE_HPP

#include <switch.h>
#include <unordered_map>
#include <string>
#include <iostream>

extern const u32 g_l;
extern const u32 g_spacing;
extern const u32 g_xstart;
extern const u32 g_ystart;
using namespace std;

enum class Terrain{forest,grass,wheat,water,mine,swamp,wild,empty};

class Tile
{
public:

    Tile(){
    }

    Tile(Terrain t, int cc){
      terrain = t;
      crownCount = cc;
    }
    Terrain getTerrain(){
      return terrain;
    };

    int getCrownCount(){
      return crownCount;
    };
    void show(u8 i, u8 j);

    void printTile(){
      switch(terrain){
          case Terrain::empty:
            cout <<"[   empty   ]";
          break;

          case Terrain::wild:
            cout <<"[   wild    ]";
          break;

          case Terrain::grass:
            cout <<"[grass  - " <<  crownCount << "]";
          break;

          case Terrain::forest:
            cout << "[forest - " <<  crownCount << "]";
          break;

          case Terrain::wheat:
            cout <<"[wheat - " <<  crownCount << "]";
          break;

          case Terrain::water:
            cout << "[water - "<<  crownCount << "]";
          break;

          case Terrain::mine:
            cout << "[mine - " <<  crownCount << "]";
          break;

          case Terrain::swamp:
            cout << "[swamp - " <<  crownCount << "]";
          break;

          default:
            cout <<"[   no   ]";
          break;
    }
  }

private:
    Terrain terrain;
    int crownCount; //number of crowns on tile
};

#endif
