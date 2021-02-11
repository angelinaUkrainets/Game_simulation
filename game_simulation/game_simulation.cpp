#include <iostream>
#include "services.h"

int main()
{
	srand(time(nullptr));
	player_mng pl;
	create_players(20, pl);

	hero_mng hr;
	create_heroes(20, hr);

	team t("PUSHKA");
	t.generate_new_team(pl, hr);
	t.get_team_info();
}

