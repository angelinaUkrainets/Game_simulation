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

void player::show_player()
{
	std::cout << id << " " << name_ << "\t" << rank << std::endl;
}
