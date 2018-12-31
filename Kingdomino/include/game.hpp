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

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

namespace Game
{
    void init(SDL_Renderer* renderer);
    void scanInput(void);
    bool gameOver(void);
    void show(void);
}

#endif
