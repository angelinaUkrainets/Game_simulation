#include <iomanip>
#include <iostream>

#include "classes.h"

team::team(std::string name)
{
	this->name = name;
}

void team::fill_team(player pl, hero hr)
{
	team_.push_back(memb{ pl, hr });
}

void team::generate_new_team(player_mng player, hero_mng hero)
{
	auto pls = player.get_players();
	auto hrs = hero.get_heroes();

	for(int i = 0; i<5; i++)
	{
		int indx = rand() % hrs.size();
		int indx2 = rand() % pls.size();

		this->fill_team(pls[indx2], hrs[indx]);

		pls.erase(pls.begin() + indx2);
		hrs.erase(hrs.begin() + indx);
	}
}

void team::get_team_info()
{
	std::cout << "\t TEAM`s NAME: " << name << std::endl;
	std::cout << std::setw(4) << "ID" << std::setw(25) << "NAME PLAYER" << std::setw(5) << "RANK"
		<< std::setw(10) << "ID HERO" << std::setw(25) << "NAME HERO" << std::setw(5) << "HP" << std::setw(8) << "DAMAGE" << std::endl;
	for(auto el: team_)
	{
		el.pl.show_player();
		el.hr.show_hero();
		std::cout << "\n ---------------------------------------------------------------------------------- \n" << std::endl;
	}
}
