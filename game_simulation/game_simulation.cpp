#include <iostream>

#include "menu_service.h"
#include "services.h"

int main()
{
	srand(time(nullptr));
	player_mng pl;
	hero_mng hr;
	game_mng gm;
	
	/*player_mng pl;
	create_players(20, pl);

	hero_mng hr;
	create_heroes(20, hr);

	team t1("PUSHKA"), t2("SAMALIOT");
	t1.generate_new_team(pl, hr);
	t1.get_team_info();
	std::cout << std::endl;

	t2.generate_new_team(pl, hr);
	t2.get_team_info();

	session s(t1, t2);
	s.calculate_winner();

	std::cout << std::endl << "AFTER GAME" << std::endl;

	t1.get_team_info();

	t2.add_rank(-25);
	t2.get_team_info();*/

	menu(pl, hr, gm);
}

