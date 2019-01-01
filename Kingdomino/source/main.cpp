#include <switch.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include "game.hpp"
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#define SCREEN_W 1280
#define SCREEN_H 720

Domino stack[48] = {
   Domino(Tile(Terrain::wheat, 0),Tile(Terrain::wheat, 0),1)
  ,Domino(Tile(Terrain::wheat, 0),Tile(Terrain::wheat, 0),2)
  ,Domino(Tile(Terrain::forest, 0),Tile(Terrain::forest, 0),3)
  ,Domino(Tile(Terrain::forest, 0),Tile(Terrain::forest, 0),4)
  ,Domino(Tile(Terrain::forest, 0),Tile(Terrain::forest, 0),5)
  ,Domino(Tile(Terrain::forest, 0),Tile(Terrain::forest, 0),6)
  ,Domino(Tile(Terrain::water, 0),Tile(Terrain::water, 0),7)
  ,Domino(Tile(Terrain::water, 0),Tile(Terrain::water, 0),8)
  ,Domino(Tile(Terrain::water, 0),Tile(Terrain::water, 0),9)
  ,Domino(Tile(Terrain::grass, 0),Tile(Terrain::grass, 0),10)
  ,Domino(Tile(Terrain::grass, 0),Tile(Terrain::grass, 0),11)
  ,Domino(Tile(Terrain::swamp, 0),Tile(Terrain::swamp, 0),12)
  ,Domino(Tile(Terrain::wheat, 0),Tile(Terrain::forest, 0),13)
  ,Domino(Tile(Terrain::wheat, 0),Tile(Terrain::water, 0),14)
  ,Domino(Tile(Terrain::wheat, 0),Tile(Terrain::grass, 0),15)
  ,Domino(Tile(Terrain::wheat, 0),Tile(Terrain::swamp, 0),16)
  ,Domino(Tile(Terrain::forest, 0),Tile(Terrain::water, 0),17)
  ,Domino(Tile(Terrain::forest, 0),Tile(Terrain::grass, 0),18)
  ,Domino(Tile(Terrain::wheat, 1),Tile(Terrain::forest, 0),19)
  ,Domino(Tile(Terrain::wheat, 1),Tile(Terrain::water, 0),20)
  ,Domino(Tile(Terrain::wheat, 1),Tile(Terrain::grass, 0),21)
  ,Domino(Tile(Terrain::wheat, 1),Tile(Terrain::swamp, 0),22)
  ,Domino(Tile(Terrain::wheat, 1),Tile(Terrain::mine, 0),23)
  ,Domino(Tile(Terrain::forest, 1),Tile(Terrain::wheat, 0),24)
  ,Domino(Tile(Terrain::forest, 1),Tile(Terrain::wheat, 0),25)
  ,Domino(Tile(Terrain::forest, 1),Tile(Terrain::wheat, 0),26)
  ,Domino(Tile(Terrain::forest, 1),Tile(Terrain::wheat, 0),27)
  ,Domino(Tile(Terrain::forest, 1),Tile(Terrain::water, 0),28)
  ,Domino(Tile(Terrain::forest, 1),Tile(Terrain::grass, 0),29)
  ,Domino(Tile(Terrain::water, 1),Tile(Terrain::wheat, 0),30)
  ,Domino(Tile(Terrain::water, 1),Tile(Terrain::wheat, 0),31)
  ,Domino(Tile(Terrain::water, 1),Tile(Terrain::forest, 0),32)
  ,Domino(Tile(Terrain::water, 1),Tile(Terrain::forest, 0),33)
  ,Domino(Tile(Terrain::water, 1),Tile(Terrain::forest, 0),34)
  ,Domino(Tile(Terrain::water, 1),Tile(Terrain::forest, 0),35)
  ,Domino(Tile(Terrain::wheat, 0),Tile(Terrain::grass, 1),36)
  ,Domino(Tile(Terrain::water, 0),Tile(Terrain::grass, 1),37)
  ,Domino(Tile(Terrain::wheat, 0),Tile(Terrain::swamp, 1),38)
  ,Domino(Tile(Terrain::grass, 0),Tile(Terrain::swamp, 1),39)
  ,Domino(Tile(Terrain::mine, 1),Tile(Terrain::wheat, 0),40)
  ,Domino(Tile(Terrain::wheat, 0),Tile(Terrain::grass, 2),41)
  ,Domino(Tile(Terrain::water, 0),Tile(Terrain::grass, 2),42)
  ,Domino(Tile(Terrain::wheat, 0),Tile(Terrain::swamp, 2),43)
  ,Domino(Tile(Terrain::grass, 0),Tile(Terrain::swamp, 2),44)
  ,Domino(Tile(Terrain::mine, 2),Tile(Terrain::wheat, 0),45)
  ,Domino(Tile(Terrain::swamp, 0),Tile(Terrain::mine, 2),46)
  ,Domino(Tile(Terrain::swamp, 0),Tile(Terrain::mine, 2),47)
  ,Domino(Tile(Terrain::wheat, 0),Tile(Terrain::mine, 3),48)
};

int main(int argc, char** argv)
{
  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_PNG);
  TTF_Init();
  romfsInit();

  // Create an SDL window & renderer
  SDL_Window* window = SDL_CreateWindow("Main-Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

  SDL_Surface* bg_surface = IMG_Load("romfs:/resources/images/background.png");			// Read image as surface
  SDL_Texture* bg_texture = SDL_CreateTextureFromSurface(renderer, bg_surface);	// Create texture from surface
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, bg_texture, NULL, NULL);
  SDL_RenderPresent(renderer);

  //determine where to start in the domino stack
  int tileCounter = 0;
  int tileNumbers[48];

  for(int i = 0; i<48;i++){
    tileNumbers[i] = i + 1;
  }

  //shuffle up the tile numbers
  std::srand(std::time(0));
  random_shuffle(std::begin(tileNumbers), std::end(tileNumbers));

  Game::init(renderer);

  while(appletMainLoop())
  {
    hidScanInput();								//Scans our controllers for any button presses since the last time this function was called
    u32 kdown = hidKeysDown(CONTROLLER_P1_AUTO);	//Read the last button presses and store them in the kdown variable. CONTROLLER_P1_AUTO reads the values from the currently used controller.

    if(kdown & KEY_PLUS)						//This isn't a convention but just for consistency. If the Plus button gets pressed, close the program. Most homebrews do that.
      break;

    if(kdown & KEY_A  && tileCounter < 48){
      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, bg_texture, NULL, NULL);
      Domino dominoSelection[4] = {stack[tileNumbers[tileCounter]]
      ,stack[tileNumbers[tileCounter+1]]
      ,stack[tileNumbers[tileCounter+2]]
      ,stack[tileNumbers[tileCounter+3]]};
      printf("here");
      dominoSelection[0].printDominoForSelection(renderer, 1);
      dominoSelection[1].printDominoForSelection(renderer, 2);
      dominoSelection[2].printDominoForSelection(renderer, 3);
      dominoSelection[3].printDominoForSelection(renderer, 4);
      SDL_RenderPresent(renderer);
      tileCounter+=4;
    }
  }
  SDL_Quit();				// SDL cleanup
	return EXIT_SUCCESS;
}
