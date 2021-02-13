#include <iomanip>
#include <iostream>

#include "classes.h"

team::team(std::string name)
{
	this->name = name;
}

std::vector<memb>* team::get_team()
{
	return &this->team_;
}

std::string team::get_name()
{
	return this->name;
}

void team::set_team(std::vector<memb> team)
{
	for (auto el : team)
		this->team_.push_back(el);
}

void team::set_name(std::string name)
{
	this->name = name;
}

void team::fill_team(player pl, hero hr)
{
	team_.push_back(memb{ pl, hr });
}

int team::calculate_points()
{
	int sum = 0;
	
	for (auto el:team_)
	{
		sum += el.hr.get_hp();
		sum -= el.hr.get_damage();
	}

	return sum;
}

void team::add_rank(int num)
{
	for(auto& el:team_)
	{
		el.pl.set_rank(num);
	}
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
		<< std::setw(10) << "ID HERO" << std::setw(25) << "NAME HERO" << std::setw(5) << "HP" <<
		std::setw(8) << "DAMAGE" << std::endl;
	for(auto el: team_)
	{
		el.pl.show_player();
		el.hr.show_hero();
		std::cout << "\n ---------------------------------------------------------------------------------- \n" << std::endl;
	}
}

void team::generate_two_teams(player_mng player, hero_mng hero, team& t2)
{
	auto pls = player.get_players();
	auto hrs = hero.get_heroes();

	int indx, indx2;

	for (int i = 0; i < 5; i++)
	{
		indx = rand() % hrs.size();
		indx2 = rand() % pls.size();

		this->fill_team(pls[indx2], hrs[indx]);

		pls.erase(pls.begin() + indx2);
		hrs.erase(hrs.begin() + indx);
	}

	for(int i = 0; i<5; i++)
	{
		indx = rand() % hrs.size();
		indx2 = rand() % pls.size();

		t2.fill_team(pls[indx2], hrs[indx]);

		pls.erase(pls.begin() + indx2);
		hrs.erase(hrs.begin() + indx);
	}
}
