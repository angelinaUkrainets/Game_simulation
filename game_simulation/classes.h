#pragma once
#include <string>
#include <vector>

class player
{
	int id, rank;
	std::string name_;
public:
	player() = default;
	player(int id, std::string name);
	std::string get_name();
	int get_id();
	void show_player();
};

class hero
{
	int id, hp, damage;
	std::string name_;
public:
	hero() = default;
	hero(int id, int hp, int damage, std::string name_);
};

class player_mng
{
	std::vector<player> players_;
public:
	player_mng() = default;
	void create_player(int id, std::string name_);
	player get_player_by_name(std::string name);
	player get_player_by_id(int id);
	void delete_player(player pl);
	void show_player_info();
};


