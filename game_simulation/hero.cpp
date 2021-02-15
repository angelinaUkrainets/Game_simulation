#include <iomanip>
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

int hero::get_hp()
{
	return this->hp;
}

int hero::get_damage()
{
	return this->damage;
}

void hero::show_hero()
{
	std::cout << std::setw(10) << id << std::setw(25) << name_ << std::setw(5) << hp << std::setw(8) << damage;
}
