#ifndef ORDER_HPP
#define ORDER_HPP

using namespace std;

class Order
{
public:

	int first_player;
	int second_player;
	int third_player;
	int fourth_player;
	int current_player;

	Order()
	{
		first_player = 1;
		second_player = 2;
		third_player = 3;
		fourth_player = 4;
		current_player = 1;
	}

};

#endif
