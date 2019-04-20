#ifndef GAME_STATE_MANAGER_HPP
#define GAME_STATE_MANAGER_HPP

#include <switch.h>
#include <unordered_map>
#include <string>
#include "Board.hpp"
#include "Coordinates.hpp"

enum class Orientation{horizontal, vertical, horizontal_reverse, vertical_flipped};

class GameStateManager
{
public:
	GameStateManager() {
		board1 = Board(1);
		board2 = Board(2);
		tile_1_coordinates = Coordinates(0,0);
		tile_2_coordinates = Coordinates(1,0);
		orientation = Orientation::horizontal;
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

	Orientation get_orientation()
	{
		return orientation;
	}

	void set_tile_1_coordinates(Coordinates coordinates)
	{
		tile_1_coordinates = coordinates;
	}

	void set_tile_2_coordinates(Coordinates coordinates)
	{
		tile_2_coordinates = coordinates;
	}

	Domino get_selected_domino()
	{
		return selected_domino;
	}

	void set_selected_domino(Domino domino)
	{
		this->selected_domino = domino;
	}

	void display_overlay(SDL_Renderer* renderer, struct SDL_Texture* textures[20])
	{
		//fix this
		selected_domino.getTile1().printTile(renderer, 100, 100, textures);
		selected_domino.getTile2().printTile(renderer, 300, 100, textures);
	}

private:
	Board board1;
	Board board2;
	Coordinates tile_1_coordinates;
	Coordinates tile_2_coordinates;
	Orientation orientation;
	Domino selected_domino;
};

#endif
