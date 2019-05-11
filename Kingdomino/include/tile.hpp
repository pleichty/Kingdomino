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

	  SDL_Rect crownDestination;
	  crownDestination.x = x + 75;
	  crownDestination.y = y;
	  crownDestination.w = 25;
	  crownDestination.h = 25;


      // Copy bg texture to renderer:
      SDL_RenderCopy(renderer, getTextureforTile(renderer, textures), NULL, &tileDestination);
	  if (crownCount == 1) {
		  SDL_RenderCopy(renderer, textures[13], NULL, &crownDestination);
	  }
	  else if (crownCount == 2) {
		  SDL_RenderCopy(renderer, textures[14], NULL, &crownDestination);
	  }
	  else if (crownCount == 3) {
		  SDL_RenderCopy(renderer, textures[15], NULL, &crownDestination);
	  }
  }

    Terrain terrain;
    int crownCount; //number of crowns on tile
	bool discovered;
};

#endif
