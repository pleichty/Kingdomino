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
	const int x_start = 300;
	const int y_start = 150;

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
		SDL_Rect tile_position_1;
		tile_position_1.x = x_start + (tile_1_coordinates.getXCoordinate() * 100);
		tile_position_1.y = y_start + (tile_1_coordinates.getYCoordinate() * 100);
		tile_position_1.w = 100;
		tile_position_1.h = 100;
		SDL_Rect tile_position_2;
		tile_position_2.x = x_start + (tile_2_coordinates.getXCoordinate() * 100);
		tile_position_2.y = y_start + (tile_2_coordinates.getYCoordinate() * 100);
		tile_position_2.w = 100;
		tile_position_2.h = 100;
		//TODO which board
		if(board1.can_place_domino(selected_domino, tile_1_coordinates, tile_2_coordinates))
		{
			SDL_RenderCopy(renderer, textures[10], nullptr, &tile_position_1);
			SDL_RenderCopy(renderer, textures[10], nullptr, &tile_position_2);
		}
		else
		{
			SDL_RenderCopy(renderer, textures[11], nullptr, &tile_position_1);
			SDL_RenderCopy(renderer, textures[11], nullptr, &tile_position_2);
		}
	}

	void move_right()
	{
		tile_1_coordinates.move_right();
		tile_2_coordinates.move_right();
	}

	void move_left()
	{
		tile_1_coordinates.move_left();
		tile_2_coordinates.move_left();
	}

	void move_up()
	{
		tile_1_coordinates.move_up();
		tile_2_coordinates.move_up();
	}

	void move_down()
	{
		tile_1_coordinates.move_down();
		tile_2_coordinates.move_down();
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
