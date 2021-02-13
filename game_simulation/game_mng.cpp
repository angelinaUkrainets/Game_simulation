#include "classes.h"

void game_mng::perform_game_session(std::string name1, std::string name2, player_mng pl, hero_mng hr)
{
	team t1(name1), t2(name2);

	t1.generate_two_teams(pl, hr, t2);

	t1.get_team_info();
	t2.get_team_info();
}