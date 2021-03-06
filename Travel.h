#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "HitboxManager.h"
#include "TetrisBoard.h"

//This class defines the part of the game where the player controls a sprite.

enum PlayerMove { none_player, left_player, right_player, up_player };
enum game_state { game_won, game_lost, game_ongoing };

extern int PLAYER_VELOCITY_X;
extern int PLAYER_VELOCITY_JUMP;
extern int TILE_SIZE;
extern int LINE_SIZE;
extern int X_INITIAL;

class Travel
{
public:
	Travel();
	Travel(SDL_Renderer * _ren);
	~Travel();
	void createPlayer(const int& boardWidth, const int& boardHeight, const int& playerWidth, const int& playerHeight, const int& hitboxWidth, const int& hitboxHeight);
	void handleInput(PlayerMove pmove);
	game_state update(std::unique_ptr<HitboxManager>& hitbox_manager);
	void render(std::unique_ptr<TetrisBoard>& Tetris);


private: 
	void updateX();
	void updateY();
	std::shared_ptr<Player> player;
	SDL_Renderer * ren;
};

