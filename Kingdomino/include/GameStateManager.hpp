#ifndef GAME_STATE_MANAGER_HPP
#define GAME_STATE_MANAGER_HPP

#include <switch.h>
#include <unordered_map>
#include <string>
#include "Board.hpp"
#include "Coordinates.hpp"

class GameStateManager
{
public:
	GameStateManager() {
		board1 = Board(1);
		board2 = Board(2);
		tile_1_coordinates = Coordinates();
		tile_2_coordinates = Coordinates();
	}

	Board getBoard1() {
		return board1;
	}

	Board getBoard2() {
		return board2;
	}

	Coordinates getCoordinates1()
	{
		return tile_1_coordinates;
	}

	Coordinates getCoordinates2()
	{
		return tile_2_coordinates;
	}


private:
	Board board1;
	Board board2;
	Coordinates tile_1_coordinates;
	Coordinates tile_2_coordinates;
};

#endif
