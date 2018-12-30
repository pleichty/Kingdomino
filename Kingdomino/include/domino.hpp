#ifndef DOMINO_HPP
#define DOMINO_HPP

#include <switch.h>
#include <unordered_map>
#include <string>
#include "tile.hpp"


class Domino
{
public:
    Domino(Tile t1, Tile t2, int tileNum){
      tile1 = t1;
      tile2 = t2;
      tileNumber = tileNum;
    }

    Tile getTile1(){
      return tile1;
    }

    Tile getTile2(){
      return tile2;
    }

    int getTileNumber(){
      return tileNumber;
    }

private:
   Tile tile1;
   Tile tile2;
   int tileNumber;
};

#endif
