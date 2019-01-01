#include "game.hpp"
#include <time.h>

static u32 score;

void Game::init(SDL_Renderer* renderer)
{
  score = 0;
  Board player1Board = Board(1);
  Board player2Board = Board(2);
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
