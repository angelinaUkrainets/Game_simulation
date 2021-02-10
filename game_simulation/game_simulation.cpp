#include <iostream>
#include "services.h"

int main()
{
	srand(time(nullptr));
	player_mng pl;
	create_players(20, pl);
}

