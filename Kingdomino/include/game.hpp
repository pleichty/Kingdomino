#ifndef GAME_HPP
#define GAME_HPP

#include <algorithm>
#include <cstring>
#include <cmath>
#include <array>
#include <ctime>
#include <vector>
#include "tile.hpp"
#include "board.hpp"

namespace Game
{
    void init(void);
    void scanInput(void);
    bool gameOver(void);
    void show(void);
}

#endif
