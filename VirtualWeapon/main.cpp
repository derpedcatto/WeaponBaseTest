#include <iostream>
#include <conio.h>
#include "Player.h"

void main()
{
	srand(time(0));
	Player player;
	int enemy = 100;

	printf("ENTER - Left Click\nSPACE - Right Click\nWEAPONS - 1-6\n\n");

	while (true)
	{
		player.CheckHP();
		player.PrintStatus(enemy);
		printf("\n\n");

		if (enemy < 1)
		{
			enemy = 100;
			player.AddToEnemyCount();
			player.SetHP(player.GetHP() * 1.5);
			printf("Enemy killed!\n\nKilled total: %d\nHP regenerated\n\n", player.GetEnemyCount());
			continue;
		}

		int key = _getch();

		switch (key)
		{
		case 49:	// KEY 1
		{
			player.SetActiveWeapon(1);
			continue;
		}
		case 50:
		{
			player.SetActiveWeapon(2);
			continue;
		}
		case 51:
		{
			player.SetActiveWeapon(3);
			continue;
		}
		case 52:
		{
			player.SetActiveWeapon(4);
			continue;
		}
		case 53:
		{
			player.SetActiveWeapon(5);
			continue;
		}
		case 54:
		{
			player.SetActiveWeapon(6);
			continue;
		}
		case 13:	// ENTER
		{
			enemy -= player.LeftClick(player.GetActiveWeapon());
			break;
		}
		case 32:	// SPACE
		{
			player.RightClick(player.GetActiveWeapon());
			break;
		}
		}

		if (rand() % 50 < 50)
		{
			player.SetHP(player.GetHP() - (5 + rand() % 15));
			printf("\nYou got hit!\n");
		}
		else
		{
			printf("\nEnemy missed!\n");
		}
	}
}