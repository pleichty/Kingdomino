#include "Board.hpp"
#include <iostream>
#include "direction.hpp"


int Board::calculateScore(){
  //TODO
  return 0;
}

bool Board::canPlaceDomino(Domino domino, int x, int y, Direction direction){
  //TODO
  return false;
}

void Board::placeDomino(Domino domino, int x, int y, Direction direction){
  tileArr[x][y] = domino.getTile1();
  if(direction == Direction::up){
    tileArr[x][y+1] = domino.getTile2();
  }
  else if(direction == Direction::left){
    tileArr[x-1][y] = domino.getTile2();
  }
  else if(direction == Direction::right){
    tileArr[x+1][y] = domino.getTile2();
  }
  else if(direction == Direction::down){
    tileArr[x][y+1] = domino.getTile2();
  }
}

void Board::displayBoard(){
  printf("player %d \n", player);
  for(int x=0; x< 5; x++){
    for(int y=0;y<5;y++){
        tileArr[x][y].printTile();
    }
        printf("\n");
  }
    printf("\n");
}
