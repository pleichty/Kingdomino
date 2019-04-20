#ifndef COORDINATES_HPP
#define COORDINATES_HPP

class Coordinates
{
public:
	Coordinates(int x, int y) {
		x_coordinate = x;
		y_coordinate = y;
	}

	Coordinates() {
		x_coordinate = 0;
		y_coordinate = 0;
	}

	int getXCoordinate()
{
		return x_coordinate;
}
	int getYCoordinate()
{
		return y_coordinate;
}
	void set_x_coordinate(int x)
	{
		x_coordinate = x;
	}

	void set_y_coordinate(int y)
	{
		y_coordinate = y;
	}

private:
	int x_coordinate;
	int y_coordinate;
};

#endif
