#include <iostream>

#include "classes.h"

hero::hero(int id, int hp, int damage, std::string name_)
{
	this->id = id;
	this->hp = hp;
	this->damage = damage;
	this->name_ = name_;
}

std::string hero::get_name()
{
	return this->name_;
}

int hero::get_id()
{
	return this->id;
}

void hero::show_hero()
{
	std::cout << id << " " << name_ << "\t" << hp << "  " << damage << std::endl;
}
