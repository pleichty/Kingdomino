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

    void printTile(SDL_Renderer* renderer,int x, int y, int startx, int starty,int player){
      //create texture for starting tiles
      SDL_Surface* tileSurface;

      SDL_Rect tileDestination;
      tileDestination.x = startx + (x * 100);
      tileDestination.y = starty + (y * 100);
      tileDestination.w = 100;
      tileDestination.h = 100;

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
    SDL_Texture* tileTexture = SDL_CreateTextureFromSurface(renderer, tileSurface);

    // Copy bg texture to renderer:
    SDL_RenderCopy(renderer, tileTexture, NULL, &tileDestination);
  }

private:
    Terrain terrain;
    int crownCount; //number of crowns on tile
};

#endif
