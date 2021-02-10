#pragma once
#include <ctime>
#include <string>

#include "classes.h"

std::string rand_name(int length)
{
	char consonents[] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z' };
	char vowels[] = { 'a','e','i','o','u','y' };

	std::string name = "";

	int random = rand() % 2;
    int count = 0;

    for (int i = 0; i < length; i++) {

        if (random < 2 && count < 2) {
            name = name + consonents[rand() % 19];
            count++;
        }
        else {
            name = name + vowels[rand() % 5];
            count = 0;
        }

        random = rand() % 2;

    }
    return name;
}

int generate_id()
{
    static int member = 0;
    return ++member;
}

void create_players(int number, player_mng& pl)
{
	for(int i = 0; i<number; i++)
	{
        auto num = rand();
        num = (num % 20) + 4;
        pl.create_player(generate_id(), rand_name(num));
		
	}
}