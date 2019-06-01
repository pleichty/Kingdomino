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
	  
	  else if(terrain == Terrain::forest && crownCount == 0){
        return textures[3];
      }
	  
	  else if (terrain == Terrain::forest && crownCount == 1) {
		  return textures[4];
	  }
	  else if (terrain == Terrain::forest && (crownCount != 0 || crownCount != 1)) {
		  TTF_Font* font;

		  font = TTF_OpenFont("romfs:/resources/fonts/MiniSet2.ttf", 24);
		  std::string player_2_score_text = "Player 2 Score: " + std::to_string(crownCount);


		  SDL_Color textColor = { 255, 255, 255, 0 };

		  SDL_Surface* textSurface = TTF_RenderText_Solid(font, player_2_score_text.c_str(), textColor);
		  SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, textSurface);
		  int text_width = textSurface->w;
		  int text_height = textSurface->h;
		  SDL_FreeSurface(textSurface);
		  SDL_Rect renderQuad = { 20, 720 - 30, text_width, text_height };
		  SDL_RenderCopy(renderer, text, NULL, &renderQuad);
		  return textures[17];
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
        return textures[13 + crownCount];
      }
      else if(terrain == Terrain::p1){
        return textures[17];
      }
      else if(terrain == Terrain::p2){
        return textures[18];
      }
	  
      else{
        return textures[21];
      }
	  
		return textures[0];
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
