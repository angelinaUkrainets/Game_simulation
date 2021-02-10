#pragma once
#include <map>
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
	std::string get_name();
	int get_id();
	void show_hero();
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

class hero_mng
{
	std::vector<hero> heroes_;
public:
	hero_mng() = default;
	void create_hero(int id, int hp, int damage, std::string name_);
	hero get_hero_by_name(std::string name);
	hero get_hero_by_id(int id);
	void delete_hero(hero h);
	void show_hero_info();
};

class team
{
	std::string name;
	std::map<player, hero> team_;
public:
};