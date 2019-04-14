#ifndef GAME_STATE_MANAGER_HPP
#define GAME_STATE_MANAGER_HPP

#include <switch.h>
#include <unordered_map>
#include <string>
#include "Board.hpp"


class GameStateManager
{
public:
	GameStateManager() {
		board1 = Board(1);
		board2 = Board(2);
	}

	Board getBoard1() {
		return board1;
	}

	Board getBoard2() {
		return board2;
	}


private:
	Board board1;
	Board board2;
};

#endif
