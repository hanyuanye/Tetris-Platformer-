#pragma once
#include <vector>
#include <memory>
#include "Constant.h"
#include "Vec2d.h"
#include "Obstacle.h"
#include "Player.h"

extern int xInitial;
extern int yInitial;
extern int tileSize;
extern int lineSize;
extern int PLAYER_LIVES;

class HitboxManager
{
public:
	HitboxManager(const std::vector<std::vector<obstacle_type>>& board);
	HitboxManager();
	~HitboxManager();

	void generateAABB(const std::vector<std::vector<obstacle_type>>& board); //TODO: Currently generates a seperate AABB for each block. This is bad and will be optimized. 
	void checkCollisionsX(std::shared_ptr<Player>& player); //Iterates through the obstacle_list, checks collision and lets objects handle it if there are. 
	void checkCollisionsY(std::shared_ptr<Player>& player);

	int num_goals;
	int lives;

private:
	void addWall(Vec2d _min, Vec2d _max);
	void addGoal(Vec2d _min, Vec2d _max);
	void addSpike(Vec2d _min, Vec2d _max);
	bool checkAABB(std::unique_ptr<AABB>& A, std::unique_ptr<AABB>& B); //Helper function for checkCollision.

	void updatePlayerStatus(collision_result result, int i);

	std::vector<std::shared_ptr<Obstacle>> obstacle_list;
};

