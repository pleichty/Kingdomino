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

enum class Terrain{forest,grass,wheat,water,mine,swamp,p1,p2,empty};

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

    SDL_Texture* getTextureforTile(SDL_Renderer* renderer, SDL_Texture* textures[]){
      if(terrain == Terrain::grass){
        return textures[0];
      }
      else if(terrain == Terrain::forest){
        return textures[1];
      }
      else if(terrain == Terrain::wheat){
        return textures[2];
      }
      else if(terrain == Terrain::water){
        return textures[3];
      }
      else if(terrain == Terrain::mine){
        return textures[4];
      }
      else if(terrain == Terrain::swamp){
        return textures[5];
      }
      else if(terrain == Terrain::p1){
        return textures[7];
      }
      else if(terrain == Terrain::p2){
        return textures[8];
      }
      else{
        return textures[12];
      }
    }

    void printTile(SDL_Renderer* renderer,int x, int y, SDL_Texture* textures[]){
      SDL_Rect tileDestination;
      tileDestination.x = x;
      tileDestination.y = y;
      tileDestination.w = 100;
      tileDestination.h = 100;

      // Copy bg texture to renderer:
      SDL_RenderCopy(renderer, getTextureforTile(renderer, textures), NULL, &tileDestination);
  }

private:
    Terrain terrain;
    int crownCount; //number of crowns on tile
};

#endif
