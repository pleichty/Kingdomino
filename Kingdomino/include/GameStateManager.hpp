#ifndef GAME_STATE_MANAGER_HPP
#define GAME_STATE_MANAGER_HPP

#include <switch.h>
#include <unordered_map>
#include <string>
#include "Board.hpp"
#include "Coordinates.hpp"
#include "Order.hpp"

enum class Orientation{horizontal, vertical, horizontal_reverse, vertical_flipped};

class GameStateManager
{
public:
	Board board1;
	Board board2;
	Coordinates tile_1_coordinates;
	Coordinates tile_2_coordinates;
	Orientation orientation;
	Domino selected_domino_1;
	Domino selected_domino_2;
	Domino selected_domino_3;
	Domino selected_domino_4;
	Order order;
	const int x_start = 300;
	const int y_start = 150;

	GameStateManager() {
		board1 = Board(1);
		board2 = Board(2);
		tile_1_coordinates = Coordinates(0,0);
		tile_2_coordinates = Coordinates(1,0);
		orientation = Orientation::horizontal;
		order = Order();
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
		this->tile_1_coordinates = coordinates;
	}

	void set_tile_2_coordinates(Coordinates coordinates)
	{
		this->tile_2_coordinates = coordinates;
	}

	Domino get_domino_for_player(int player)
	{
		switch (player) {
		case 1:
			return selected_domino_1;
		case 2:
			return selected_domino_2;
		default:
			return selected_domino_1;
			/*
		case 3:
			return selected_domino_3;
		case 4:
			return selected_domino_4;
		}
		*/
		}
	}

	void set_domino_for_player(Domino domino, int player)
	{
		switch (player) {
		case 1:
			selected_domino_1 = domino;
		case 2:
			selected_domino_2 = domino;

		default:
			selected_domino_1 = domino;
			/*
		case 3:
			selected_domino_3 = domino;
		case 4:
			selected_domino_4 = domino;
		}
		*/
		}
	}

	Board get_board_for_player(int player) {
		switch (player) {
		case 1:
			return board1;
		case 2:
			return board2;
		default:
			return board1;
			/*
		case 3:
			return nullptr;
		case 4:
			return nullptr;
		}
		*/
		}
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
		if(get_board_for_player(order.current_player).can_place_domino(get_domino_for_player(order.current_player), tile_1_coordinates, tile_2_coordinates))
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

	void clear_selections()
	{
		tile_1_coordinates = Coordinates(0, 0);
		tile_2_coordinates = Coordinates(1, 0);
		orientation = Orientation::horizontal;
	}

	void place_domino(Domino domino, Coordinates tile_1_coordinates, Coordinates tile_2_coordinates) {
		get_board_for_player(order.current_player).place_domino(domino, tile_1_coordinates, tile_2_coordinates);
	}

	void update_orientation() {
		if (orientation == Orientation::horizontal && tile_1_coordinates.y_coordinate < 4) {
			orientation = Orientation::vertical;
			tile_2_coordinates.x_coordinate -= 1;
			tile_2_coordinates.y_coordinate += 1;
			
		}
		else if (orientation == Orientation::vertical && tile_1_coordinates.x_coordinate > 0) {
			orientation = Orientation::horizontal_reverse;
			tile_2_coordinates.x_coordinate -= 1;
			tile_2_coordinates.y_coordinate -= 1;
		}
		else if (orientation == Orientation::horizontal_reverse && tile_1_coordinates.y_coordinate > 0) {
			orientation = Orientation::vertical_flipped;
			tile_2_coordinates.x_coordinate += 1;
			tile_2_coordinates.y_coordinate -= 1;
		}
		else if(orientation == Orientation::vertical_flipped && tile_1_coordinates.x_coordinate < 4){
			orientation = Orientation::horizontal;
			tile_2_coordinates.x_coordinate += 1;
			tile_2_coordinates.y_coordinate += 1;

		}
	}

	void update_order(int first, int second, int third, int fourth) {
		order.first_player = first;
		order.second_player = second;
		order.third_player = third;
		order.fourth_player = fourth;
	}
};

#endif
