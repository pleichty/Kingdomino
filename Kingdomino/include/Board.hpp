#ifndef BOARD_HPP
#define BOARD_HPP

#include <switch.h>
#include <unordered_map>
#include <string>
#include "domino.hpp"
#include "direction.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

class Board
{
public:

  void placeDomino(Domino domino, int x, int y, Direction direction);

  bool canPlaceDomino(Domino domino, int x, int y, Direction direction);

  void displayBoard(SDL_Renderer* renderer);

  int calculateScore();

    Board(int p){
      player = p;
      score = 0;
      tileArr[0][0] = Tile(Terrain::empty, 0);
      tileArr[0][1] = Tile(Terrain::empty, 0);
      tileArr[0][2] = Tile(Terrain::empty, 0);
      tileArr[0][3] = Tile(Terrain::empty, 0);
      tileArr[0][4] = Tile(Terrain::empty, 0);
      tileArr[1][0] = Tile(Terrain::empty, 0);
      tileArr[1][1] = Tile(Terrain::empty, 0);
      tileArr[1][2] = Tile(Terrain::empty, 0);
      tileArr[1][3] = Tile(Terrain::empty, 0);
      tileArr[1][4] = Tile(Terrain::empty, 0);
      tileArr[2][0] = Tile(Terrain::empty, 0);
      tileArr[2][1] = Tile(Terrain::empty, 0);
      tileArr[2][2] = Tile(Terrain::wild, 0);
      tileArr[2][3] = Tile(Terrain::empty, 0);
      tileArr[2][4] = Tile(Terrain::empty, 0);
      tileArr[3][0] = Tile(Terrain::empty, 0);
      tileArr[3][1] = Tile(Terrain::empty, 0);
      tileArr[3][2] = Tile(Terrain::empty, 0);
      tileArr[3][3] = Tile(Terrain::empty, 0);
      tileArr[3][4] = Tile(Terrain::empty, 0);
      tileArr[4][0] = Tile(Terrain::empty, 0);
      tileArr[4][1] = Tile(Terrain::empty, 0);
      tileArr[4][2] = Tile(Terrain::empty, 0);
      tileArr[4][3] = Tile(Terrain::empty, 0);
      tileArr[4][4] = Tile(Terrain::empty, 0);
    }

    int getScore(){
      return score;
    }

    int getPlayer(){
      return player;
    }

private:
    int score;
    int player;
    Tile tileArr[5][5];
};

#endif
