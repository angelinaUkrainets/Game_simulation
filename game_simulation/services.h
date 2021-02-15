#pragma once
#include <ctime>
#include <string>
#include "classes.h"

static int member = 0;

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

void create_heroes(int number, hero_mng& hr)
{
    for (int i = 0; i < number; i++)
    {
        int num;
        std::string name;
        int count = 0;
        do {
            num = rand();
            num = (num % 20) + 4;
            name = rand_name(num);
            for (int j = i; j > 0; j--)
            {
                if (hr.is_hero(name))
                    count++;
            }
        } while (count != 0);

        hr.create_hero(generate_id(), rand() % 100 + 1, rand() % 20 + 1, name);
    }
}