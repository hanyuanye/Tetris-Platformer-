#include "Obstacle.h"



Obstacle::Obstacle()
{
}


Obstacle::~Obstacle()
{
}

Wall::Wall(Vec2d _min, Vec2d _max)
{
	obstacle_hitbox = std::make_unique<AABB>(_min, _max);
	type = wall;
}

Goal::Goal(Vec2d _min, Vec2d _max)
{
	obstacle_hitbox = std::make_unique<AABB>(_min, _max);
	type = goal;
}

Spike::Spike(Vec2d _min, Vec2d _max)
{
	obstacle_hitbox = std::make_unique<AABB>(_min, _max);
	type = spike;
}
