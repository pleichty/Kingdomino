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
	  discovered = false;
    }

    Terrain getTerrain(){
      return terrain;
    };

    int getCrownCount(){
      return crownCount;
    };

	bool isDiscovered() {
		return discovered;
	}

	void set_discovered(bool disc) {
		discovered = disc;
	}

    SDL_Texture* getTextureforTile(SDL_Renderer* renderer, SDL_Texture* textures[]){
      if(terrain == Terrain::grass){
        return textures[0 + crownCount];
      }

      else if(terrain == Terrain::forest){
        return textures[3 + crownCount];
      }
      else if(terrain == Terrain::wheat){
        return textures[5 + crownCount];
      }
      else if(terrain == Terrain::water){
        return textures[7 + crownCount];
      }
      else if(terrain == Terrain::mine){
        return textures[9 + crownCount];
      }
      else if(terrain == Terrain::swamp){
        return textures[12 + crownCount];
      }
      else if(terrain == Terrain::p1){
        return textures[16];
      }
      else if(terrain == Terrain::p2){
        return textures[17];
      }
      else{
        return textures[20];
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

    Terrain terrain;
    int crownCount; //number of crowns on tile
	bool discovered;
};

#endif
