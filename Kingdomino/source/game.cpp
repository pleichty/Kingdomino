#include "game.hpp"
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>

const u32 g_l = 96;
const u32 g_spacing = 16;
const u32 g_xstart = ceil((1280 - g_l*4 - g_spacing*3) / 2);
const u32 g_ystart = ceil((720 - g_l*4 - g_spacing*3) / 2);

static u32 score;


void Game::init(void)
{
  score = 0;
  Board player1Board = Board(1);
  Board player2Board = Board(2);
  player1Board.displayBoard();
  player2Board.displayBoard();



    //create dominos

    //loop
    //randomly pick 4 dominos
    //player makes selection
    //put selection in board
    //loop

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
    // background
  //  g_framebuf = gfxGetFramebuffer(&g_framebufWidth, NULL);
  //  memset(g_framebuf, 250, gfxGetFramebufferSize());


    //gfxFlushBuffers();
    //gfxSwapBuffers();
    //gfxWaitForVsync();
}
