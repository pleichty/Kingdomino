#ifndef TILE_HPP
#define TILE_HPP

#include <switch.h>
#include <unordered_map>
#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

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

    SDL_Texture* getTextureforTile(SDL_Renderer* renderer, int player = 1){
      SDL_Surface* tileSurface;

      if(terrain == Terrain::wild && player == 1){
        tileSurface = IMG_Load("romfs:/resources/images/startingTile1.png");
      }
      else if(terrain == Terrain::wild && player == 2){
        tileSurface = IMG_Load("romfs:/resources/images/startingTile2.png");
      }
      else if(terrain == Terrain::grass){
        tileSurface = IMG_Load("romfs:/resources/images/grassTile.png");
      }
      else if(terrain == Terrain::forest){
        tileSurface = IMG_Load("romfs:/resources/images/forestTile.png");
      }
      else if(terrain == Terrain::wheat){
        tileSurface = IMG_Load("romfs:/resources/images/wheatTile.png");
      }
      else if(terrain == Terrain::water){
        tileSurface = IMG_Load("romfs:/resources/images/waterTile.png");
      }
      else if(terrain == Terrain::mine){
        tileSurface = IMG_Load("romfs:/resources/images/mineTile.png");
      }
      else if(terrain == Terrain::swamp){
        tileSurface = IMG_Load("romfs:/resources/images/swampTile.png");
      }
      //empty
      else{
        tileSurface = IMG_Load("romfs:/resources/images/emptyTile.png");
      }
      return  SDL_CreateTextureFromSurface(renderer, tileSurface);
    }

    void printTile(SDL_Renderer* renderer,int x, int y){
      SDL_Rect tileDestination;
      tileDestination.x = x;
      tileDestination.y = y;
      tileDestination.w = 100;
      tileDestination.h = 100;

      // Copy bg texture to renderer:
      SDL_RenderCopy(renderer, getTextureforTile(renderer), NULL, &tileDestination);
  }

private:
    Terrain terrain;
    int crownCount; //number of crowns on tile
};

#endif
