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

bool Board::canPlaceDomino(Domino domino, GameStateManager game_state_manager){
  //TODO
  return false;
}

void Board::placeDomino(Domino domino, GameStateManager game_state_manager){
  tileArr[game_state_manager.getCoordinates1().getXCoordinate()][game_state_manager.getCoordinates1().getYCoordinate()]
	= domino.getTile1();
  tileArr[game_state_manager.getCoordinates2().getXCoordinate()][game_state_manager.getCoordinates2().getYCoordinate()]
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
