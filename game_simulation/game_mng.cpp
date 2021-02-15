#include <iostream>

#include "classes.h"

void game_mng::perform_game_session(std::string name1, std::string name2, player_mng& pl, hero_mng& hr)
{
	team t1(name1), t2(name2);

	t1.generate_two_teams(pl, hr, t2);

	std::cout << "\n\n\t\tTEAMS BEFORE GAME\n\n" << std::endl;
	t1.get_team_info();
	t2.get_team_info();

	session s(t1, t2);
	int p = s.calculate_winner();

	if(p == -1)
	{
		pl.add_rang_by_team(t1, 25);
		pl.add_rang_by_team(t2, -25);
		/*t1.add_rank(25);
		t2.add_rank(-25);*/
		std::cout << "\n\t\tWINNER : " << t1.get_name() << std::endl;
		std::cout << "\t\tLOSER : " << t2.get_name() << std::endl;
	}
	else if (p == 1)
	{
		pl.add_rang_by_team(t2, 25);
		pl.add_rang_by_team(t1, -25);
		/*t2.add_rank(25);
		t1.add_rank(-25);*/
		std::cout << "\n\t\tWINNER : " << t2.get_name() << std::endl;
		std::cout << "\t\tLOSER : " << t1.get_name() << std::endl;
	}
	else
	{
		pl.add_rang_by_team(t1, 10);
		pl.add_rang_by_team(t2, 10);
		/*t1.add_rank(10);
		t2.add_rank(10);*/
		std::cout << "YOUR POINTS ARE EQUAL" << std::endl;
	}
}