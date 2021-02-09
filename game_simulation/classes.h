#pragma once
#include <string>

class player
{
	int id, rank;
	std::string name_;
public:
	player() = default;
	player(int id, int rank, std::string name);
};

class hero
{
	int id, hp, damage;
	std::string name_;
public:
	hero() = default;
	hero(int id, int hp, int damage, std::string name_);
};
