#pragma once

void pickTile(SDL_Renderer * renderer, SDL_Texture * bg_texture, int  tileNumbers[48], int tileCounter, SDL_Texture * textures[25], bool &decision_made, u32 &kdown, GameStateManager &gameStateManager);

void placeTile(bool &decision_made, SDL_Renderer * renderer, SDL_Texture * bg_texture, GameStateManager &gameStateManager, SDL_Texture * textures[25], u32 &kdown);
