#include "Board.hpp"

int Board::calculate_score(){
  int totalScore = 0;
  for(int x = 0; x < 5; x++){
    for(int y = 0; y < 5; y++){
		if (!tileArr[x][y].isDiscovered()) {
			Score score = score_tile(x, y, tileArr[x][y].terrain);
			totalScore += score.crownCount * score.tileCount;
		}
    }
  }
  return totalScore;
}

Score Board::score_tile(int x, int y, Terrain terrain) {
	Score score = Score();
	if (x < 0 || x > 4 || y < 0 || y > 4 || tileArr[x][y].terrain != terrain || tileArr[x][y].discovered == true) {
		return score;
	}
	if (tileArr[x][y].terrain == terrain) {
		score.crownCount += tileArr[x][y].getCrownCount();
		score.tileCount++;
		tileArr[x][y].set_discovered(true);
		Score leftScore = score_tile(x - 1, y, terrain);
		Score rightScore = score_tile(x + 1, y, terrain);
		Score upScore = score_tile(x, y - 1, terrain);
		Score downScore = score_tile(x, y + 1, terrain);

		score.crownCount += (leftScore.crownCount + rightScore.crownCount + upScore.crownCount + downScore.crownCount);
		score.tileCount += (leftScore.tileCount + rightScore.tileCount + upScore.tileCount + downScore.tileCount);
	}
	return score;
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
  this->tileArr[tile_1_coordinates.getXCoordinate()][tile_1_coordinates.getYCoordinate()]
	= domino.getTile1();
  this->tileArr[tile_2_coordinates.getXCoordinate()][tile_2_coordinates.getYCoordinate()]
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
