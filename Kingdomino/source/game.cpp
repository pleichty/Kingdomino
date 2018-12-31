#include "game.hpp"
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

static u32 score;

void Game::init(void)
{
  score = 0;
  Board player1Board = Board(1);
  Board player2Board = Board(2);
  player1Board.displayBoard();
  player2Board.displayBoard();
}

void Game::scanInput(void)
{
    hidScanInput();
    u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

    //scan input


}

bool Game::gameOver(void)
{
   return false;
}


void Game::show(void)
{

}
