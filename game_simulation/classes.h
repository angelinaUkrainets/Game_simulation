#pragma once
#include <list>
#include <map>
#include <string>
#include <vector>

class team;

class player
{
	int id, rank;
	std::string name_;
public:
	player() = default;
	player(int id, std::string name);
	std::string get_name();
	int get_id();
	void set_rank(int rank);
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
	int get_hp();
	int get_damage();
	void show_hero();
};

class player_mng
{
	std::vector<player> players_;
public:
	player_mng() = default;
	std::vector<player>& get_players();
	void add_rang_by_team(team& t, int rank);
	void create_player(int id, std::string name_);
	player get_player_by_name(std::string name);
	player& get_player_by_id(int id);
	void delete_player(player pl);
	void show_player_info();
};

class hero_mng
{
	std::vector<hero> heroes_;
public:
	hero_mng() = default;
	std::vector<hero> get_heroes();
	void create_hero(int id, int hp, int damage, std::string name_);
	hero get_hero_by_name(std::string name);
	hero get_hero_by_id(int id);
	void delete_hero(hero h);
	void show_hero_info();
	bool is_hero(std::string name);
};

struct memb
{
	player pl;
	hero hr;
};

class i_team_mng
{
public:
	virtual void generate_new_team(player_mng player, hero_mng hero) = 0;
	virtual void get_team_info() = 0;
};

class team : public i_team_mng
{
	std::string name;
	std::vector<memb> team_;
public:
	team() = default;
	team(std::string name);
	std::vector<memb>& get_team();
	std::string get_name();
	void set_team(std::vector<memb> team);
	void set_name(std::string name);
	void fill_team(player& pl, hero& hr);
	int calculate_points();
	void add_rank(int num);
	void generate_new_team(player_mng player, hero_mng hero) override;
	void get_team_info() override;
	void generate_two_teams(player_mng& player, hero_mng& hero, team& t2);
};

class session
{
	team t1, t2;
public:
	session() = default;
	session(team &t1, team &t2);
	int calculate_winner();
};

class game_mng
{
	std::vector<session> sessions_;
public:
	void perform_game_session(std::string name1, std::string name2, player_mng& pl, hero_mng& hr);
};