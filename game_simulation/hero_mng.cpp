#include <iostream>

#include "classes.h"

void hero_mng::create_hero(int id, int hp, int damage, std::string name_)
{
	hero h(id, hp, damage, name_);
	heroes_.push_back(h);
}

std::vector<hero> hero_mng::get_heroes()
{
	return this->heroes_;
}

hero hero_mng::get_hero_by_name(std::string name)
{
	for(auto el : heroes_)
	{
		if(el.get_name().compare(name) == 0)
		{
			return el;
		}
	}
	std::cout << "There is no element with this name" << std::endl;
}

hero hero_mng::get_hero_by_id(int id)
{
	for(auto el:heroes_)
	{
		if(el.get_id() == id)
		{
			return el;
		}
	}
	std::cout << "There is no element with this id" << std::endl;
}

void hero_mng::delete_hero(hero h)
{
	int count = 0;
	for(auto el:heroes_)
	{
		count++;
		if(el.get_id()==h.get_id() && el.get_name().compare(h.get_name()) == 0)
			break;
	}
	heroes_.erase(heroes_.begin() + count - 1);
}

void hero_mng::show_hero_info()
{
	for(auto el:heroes_)
	{
		el.show_hero();
	}
}

bool hero_mng::is_hero(std::string name)
{
	for (auto el : heroes_)
	{
		if (el.get_name().compare(name) == 0)
		{
			return true;
		}
	}
	return false;
}
