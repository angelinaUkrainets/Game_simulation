#pragma once
#include <iostream>
#include <cstdlib>

#include "services.h"

using namespace std;
void menu(player_mng pl, hero_mng hr, game_mng gm);

void close_code(player_mng pl, hero_mng hr, game_mng gm)
{
	int n;
	cout << "CONTINUE ? \t[1] - yes [2] - no" << endl;
	cin >> n;
	if (n == 1)
	{
		system("cls");
		menu(pl, hr, gm);
	}
	else
		return;
}

void select(int num, player_mng pl, hero_mng hr, game_mng gm)
{
	switch (num)
	{
	case 1:
		{
			int n;
			cout << "Enter number of players, not less then 10" << endl;
			cin >> n;

			if (n < 10)
			{
				create_players(10, pl);
			}
			else
				create_players(n, pl);

			cout << "Players are created" << endl;

			close_code(pl, hr, gm);

			break;
		}
	case 2:
		{
			int n;
			cout << "Enter number of heroes, not less then 10" << endl;
			cin >> n;

			if (n < 10)
			{
				create_heroes(10, hr);
			}
			else
				create_heroes(n, hr);

			cout << "Heroes are created" << endl;

			close_code(pl, hr, gm);

			break;
		}
	case 3:
		{
			cout << "\nPLAYERS : " << endl;
			pl.show_player_info();
			close_code(pl, hr, gm);

			break;
		}
	case 4:
		{
			cout << "\nHEROES : " << endl;
			hr.show_hero_info();
			close_code(pl, hr, gm);

			break;
		}
	case 5:
		{
			string n1, n2;
			cout << "Enter names of teams" << endl;
			cin.ignore();
			getline(cin, n1);
			getline(cin, n2);

			gm.perform_game_session(n1, n2, pl, hr);
		}
	}
}

void menu(player_mng pl, hero_mng hr, game_mng gm)
{
	cout << "\t\t*****\tMENU\t*****" << endl;
	cout << "\t[1] - CREATE PLAYERS" << endl;
	cout << "\t[2] - CREATE HEROES" << endl;
	cout << "\t[3] - SHOW PLAYERS" << endl;
	cout << "\t[4] - SHOW HEROES" << endl;
	cout << "\t[5] - START SESSION (TEAMS WILL BE CREATING AUTOMATICALLY AND SHOW YOU BEFORE GAME)" << endl;
	cout << "\t[6] - EXIT" << endl;

	int num;
	cin >> num;
	select(num, pl, hr, gm);
}