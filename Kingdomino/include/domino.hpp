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

    Domino(){
      
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

    void printDominoForSelection(SDL_Renderer* renderer, int dominoNumber, SDL_Texture* textures[]){
        tile1.printTile(renderer, 500, 50 + (dominoNumber * 100), textures);
        tile2.printTile(renderer, 600, 50 + (dominoNumber * 100), textures);
    }

private:
   Tile tile1;
   Tile tile2;
   int tileNumber;
};

#endif
