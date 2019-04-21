#include "Board.hpp"

int Board::calculate_score(){
  for(int x = 0; x < 5; x++){
    for(int y = 0; y < 5; y++){

    }
  }
  //TODO
  return 0;
}

bool Board::can_place_domino(Domino domino, Coordinates tile_1_coordinates, Coordinates tile_2_coordinates){
  if(tileArr[tile_1_coordinates.getXCoordinate()][tile_1_coordinates.getYCoordinate()].getTerrain() != Terrain::empty
	  || tileArr[tile_2_coordinates.getXCoordinate()][tile_2_coordinates.getYCoordinate()].getTerrain() != Terrain::empty)
  {
	  return false;
  }
  else if(check_position(tile_1_coordinates.getXCoordinate() - 1, tile_1_coordinates.getYCoordinate(), domino.getTile1().getTerrain())
	  || check_position(tile_1_coordinates.getXCoordinate() + 1, tile_1_coordinates.getYCoordinate(), domino.getTile1().getTerrain())
	  || check_position(tile_1_coordinates.getXCoordinate(), tile_1_coordinates.getYCoordinate() - 1, domino.getTile1().getTerrain())
	  || check_position(tile_1_coordinates.getXCoordinate(), tile_1_coordinates.getYCoordinate() + 1, domino.getTile1().getTerrain())
	  || check_position(tile_2_coordinates.getXCoordinate() - 1, tile_2_coordinates.getYCoordinate(), domino.getTile2().getTerrain())
	  || check_position(tile_2_coordinates.getXCoordinate() + 1, tile_2_coordinates.getYCoordinate(), domino.getTile2().getTerrain())
	  || check_position(tile_2_coordinates.getXCoordinate(), tile_2_coordinates.getYCoordinate() - 1, domino.getTile2().getTerrain())
	  || check_position(tile_2_coordinates.getXCoordinate(), tile_2_coordinates.getYCoordinate() + 1, domino.getTile2().getTerrain())
	  )
  {
	  return true;
  }
  return false;
}




bool Board::check_position(int x_coordinate, int y_coordinate, Terrain terrain)
{
	if(x_coordinate < 0 || x_coordinate > 4 || y_coordinate < 0 || y_coordinate > 4)
	{
		return false;
	}
	else if(tileArr[x_coordinate][y_coordinate].getTerrain() == terrain 
		|| tileArr[x_coordinate][y_coordinate].getTerrain() == Terrain::p1
		|| tileArr[x_coordinate][y_coordinate].getTerrain() == Terrain::p2)
	{
		return true;
	}
	return false;
}

void Board::place_domino(Domino domino, Coordinates tile_1_coordinates, Coordinates tile_2_coordinates){
  tileArr[tile_1_coordinates.getXCoordinate()][tile_1_coordinates.getYCoordinate()]
	= domino.getTile1();
  tileArr[tile_2_coordinates.getXCoordinate()][tile_2_coordinates.getYCoordinate()]
	= domino.getTile2();
}


void Board::displayBoard(SDL_Renderer* renderer, SDL_Texture* textures[]){
  const int start_x = 300;
  const int start_y = 150;

  for(int x=0; x< 5; x++){
    for(int y=0;y<5;y++){
        tileArr[x][y].printTile(renderer, start_x + (x * 100), start_y + (y * 100), textures);
    }
  }
}
