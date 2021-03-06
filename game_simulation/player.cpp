#include <iomanip>
#include <iostream>

#include "classes.h"

player::player(int id, std::string name)
{
	this->id = id;
	this->rank = 0;
	this->name_ = name;
}

std::string player::get_name()
{
	return this->name_;
}

int player::get_id()
{
	return this->id;
}

void player::set_rank(int rank)
{
	this->rank += rank;
}

void player::show_player()
{
	std::cout << std::setw(4) << id << std::setw(25) << name_ << std::setw(5) << rank;
}
