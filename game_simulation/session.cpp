#include <iostream>

#include "classes.h"

session::session(team &t1, team &t2)
{
	this->t1.set_name(t1.get_name());
	this->t1.set_team(*t1.get_team());

	this->t2.set_name(t2.get_name());
	this->t2.set_team(*t2.get_team());
}

int session::calculate_winner()
{
	int sum_t1 = 0, sum_t2 = 0;

	sum_t1 = t1.calculate_points();
	sum_t2 = t2.calculate_points();
	if (sum_t1 > sum_t2) {
		return -1;
	}
	if (sum_t1 < sum_t2) {
		return 1;
	}
	return 0;

}
