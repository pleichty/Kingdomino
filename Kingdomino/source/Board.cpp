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
  int startx = 100;
  int starty;
  printf("player %d \n", player);
  //display board for either player 1 or 2
  if(player == 1){
    starty = 500;
  }
  else{
    starty = 900;
  }
  for(int x=0; x< 5; x++){
    for(int y=0;y<5;y++){
        tileArr[x][y].printTile(x,y,startx,starty);
    }
  }
}
