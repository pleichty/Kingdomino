#include "Board.hpp"

int Board::calculateScore(){
  int calculateScore = 0;
  for(int x = 0; x < 5; x++){
    for(int y = 0; y < 5; y++){

    }
  }
  //TODO
  return 0;
}

bool Board::canPlaceDomino(Domino domino, Coordinates tile_1_coordinates, Coordinates tile_2_coordinates){
  //TODO
  return false;
}

void Board::placeDomino(Domino domino, Coordinates tile_1_coordinates, Coordinates tile_2_coordinates){
  tileArr[tile_1_coordinates.getXCoordinate()][tile_1_coordinates.getYCoordinate()]
	= domino.getTile1();
  tileArr[tile_2_coordinates.getXCoordinate()][tile_2_coordinates.getYCoordinate()]
	= domino.getTile2();
}


void Board::displayBoard(SDL_Renderer* renderer, SDL_Texture* textures[]){
  const int start_x = 500;
  const int start_y = 360;

  for(int x=0; x< 5; x++){
    for(int y=0;y<5;y++){
        tileArr[x][y].printTile(renderer, start_x + (x * 100), start_y + (y * 100), textures);
    }
  }
}
