#include <iostream>

#include "classes.h"

void player_mng::create_player(int id, std::string name_)
{
	player pl(id, name_);
	players_.push_back(pl);
}

player player_mng::get_player_by_name(std::string name)
{
	for(auto el:players_)
	{
		if ((el.get_name()).compare(name) == 0)
			return el;
	}
	std::cout << "There is no player with name " << name << std::endl;
}

player player_mng::get_player_by_id(int id)
{
	for(auto el:players_)
	{
		if (el.get_id() == id)
			return el;
	}
	std::cout << "There is no player with id " << id << std::endl;
}

void player_mng::delete_player(player pl)
{
	int count = 0;
	for(auto el:players_)
	{
		count++;
		if(el.get_id() == pl.get_id() && el.get_name().compare(pl.get_name()))
			break;
	}

	players_.erase(players_.begin() + count - 1);
}

void player_mng::show_player_info()
{
	for(auto el:players_)
	{
		el.show_player();
	}
}
