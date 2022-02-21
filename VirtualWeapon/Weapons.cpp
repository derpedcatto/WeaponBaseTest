#include "Weapons.h"

//---------------------------------------------------------------// KNIFE

Knife::Knife()
{
	SetDMG(15);
	SetAccuracy(99);
}
int Knife::LeftClick()
{
	if (rand() % 100 < GetAccuracy())
	{
		printf("\nKnife attack!\n");
		return GetDMG();
	}
	else
	{
		printf("\nMissed!\n");
		return 0;
	}
}
int Knife::RightClick()
{
	printf("\nNo action!\n");
	return 0;
}

//---------------------------------------------------------------// GLOCK

Glock::Glock()
{
	SetDMG(25);
	SetAccuracy(80);
	SetMagSize(20);
	SetMagCount(20);
}
int Glock::LeftClick()
{
	/*1 bullet*/
	if (!secondaryFire)
	{
		SetAccuracy(80);

		/*Reload*/
		if (FireBullet() == 1)	//FireBullet() initializes
		{
			return 0;
		}

		/*Accuracy check*/
		if (rand() % 100 >= GetAccuracy())
		{
			printf("\nMiss!\n");
			return 0;
		}

		printf("\nHit!\n");
		return GetDMG();
	}

	/*3-burst fire*/
	if (secondaryFire)
	{
		SetAccuracy(65);
		int total_dmg = 0;
		for (int i = 0; i < 3; i++)
		{
			/*Reload*/
			if (FireBullet() == 1)	//FireBullet() initializes
			{
				break;
			}

			/*Accuracy check*/
			if (rand() % 100 >= GetAccuracy())
			{
				printf("Miss!\n");
				continue;
			}

			printf("Hit!\n");
			total_dmg += GetDMG();
		}

		return total_dmg;
	}
}
int Glock::RightClick()
{
	printf("\nSecondary fire switched!\n");
	secondaryFire = !secondaryFire;
	return 0;
}


//---------------------------------------------------------------// MP5

MP5::MP5()
{
	SetDMG(28);
	SetAccuracy(90);
	SetMagSize(30);
	SetMagCount(30);
}
int MP5::LeftClick()
{
	/*Single Fire*/
	if (firemode == 1)
	{
		SetAccuracy(90);

		/*Fire + check for reload*/
		if (FireBullet() == 1)	//FireBullet() initializes
		{
			return 0;
		}

		if (rand() % 100 >= GetAccuracy())
		{
			printf("\nMiss!\n");
			return 0;
		}

		printf("\nHit!\n");
		return GetDMG();
	}

	/*Burst-Fire*/
	if (firemode == 2)
	{
		SetAccuracy(75);
		int total_dmg = 0;
		for (int i = 0; i < 3; i++)
		{
			/*Reload*/
			if (FireBullet() == 1)	//FireBullet() initializes
			{
				break;
			}

			/*Accuracy check*/
			if (rand() % 100 >= GetAccuracy())
			{
				printf("Miss!\n");
				continue;
			}

			printf("Hit!\n");
			total_dmg += GetDMG();
		}

		return total_dmg;
	}

	/*Auto-Fire*/
	if (firemode == 3)
	{
		SetAccuracy(35);
		int total_dmg = 0;
		for (int i = 0; i < 5 + rand() % 10; i++)
		{
			/*Reload*/
			if (FireBullet() == 1)	//FireBullet() initializes
			{
				break;
			}

			/*Accuracy check*/
			if (rand() % 100 >= GetAccuracy())
			{
				printf("Miss!\n");
				continue;
			}

			printf("Hit!\n");
			total_dmg += GetDMG();
		}

		return total_dmg;
	}
}
int MP5::RightClick()
{
	printf("\nSecondary fire switched!\n");
	firemode++;
	if (firemode == 4)
		firemode = 1;

	return 0;
}

//---------------------------------------------------------------// M4A1

M4A1::M4A1()
{
	SetDMG(32);
	SetAccuracy(95);
	SetMagSize(30);
	SetMagCount(30);
}
int M4A1::LeftClick()
{
	/*Single Fire*/
	if (firemode == 1)
	{
		SetAccuracy(80);

		/*Fire + check for reload*/
		if (FireBullet() == 1)	//FireBullet() initializes
		{
			return 0;
		}

		if (rand() % 100 >= GetAccuracy())
		{
			printf("\nMiss!\n");
			return 0;
		}

		printf("\nHit!\n");
		return GetDMG();
	}

	/*Burst-Fire*/
	if (firemode == 2)
	{
		SetAccuracy(65);
		int total_dmg = 0;
		for (int i = 0; i < 3; i++)
		{
			/*Reload*/
			if (FireBullet() == 1)	//FireBullet() initializes
			{
				break;
			}

			/*Accuracy check*/
			if (rand() % 100 >= GetAccuracy())
			{
				printf("Miss!\n");
				continue;
			}

			printf("Hit!\n");
			total_dmg += GetDMG();
		}

		return total_dmg;
	}

	/*Auto-Fire*/
	if (firemode == 3)
	{
		SetAccuracy(30);
		int total_dmg = 0;
		for (int i = 0; i < 5 + rand() % 10; i++)
		{
			/*Reload*/
			if (FireBullet() == 1)	//FireBullet() initializes
			{
				break;
			}

			/*Accuracy check*/
			if (rand() % 100 >= GetAccuracy())
			{
				printf("Miss!\n");
				continue;
			}

			printf("Hit!\n");
			total_dmg += GetDMG();
		}

		return total_dmg;
	}
}
int M4A1::RightClick()
{
	printf("\nSecondary fire switched!\n");
	firemode++;
	if (firemode == 4)
		firemode = 1;

	return 0;
}

//---------------------------------------------------------------// AWP

AWP::AWP()
{
	SetDMG(100);
	SetAccuracy(100);
	SetMagSize(10);
	SetMagCount(10);
}
int AWP::LeftClick()
{
	if (!isCocked)
	{
		printf("\nAWP is not cocked!\n");
		return 0;
	}

	if (FireBullet() == 1)	//FireBullet() initializes
	{
		return 0;
	}

	if (rand() % 100 >= GetAccuracy())
	{
		printf("\nMiss!\n");
		return 0;
	}

	isCocked = false;

	printf("\nHit!\n");
	return GetDMG();
}
int AWP::RightClick()
{
	if (isCocked)
	{
		printf("\AWP is already cocked!\n");
	}
	else
	{
		isCocked = true;
		printf("\nYou can shoot now!\n");
	}
	return 0;
}

//---------------------------------------------------------------// AUTOSNIPER

Autosniper::Autosniper()
{
	SetDMG(70);
	SetAccuracy(80);
	SetMagSize(20);
	SetMagCount(20);
}
int Autosniper::LeftClick()
{
	if (!isScoped)
		SetAccuracy(15);
	if (isScoped)
		SetAccuracy(80);

	if (FireBullet() == 1)	//FireBullet() initializes
	{
		return 0;
	}

	if (rand() % 100 >= GetAccuracy())
	{
		printf("\nMiss!\n");
		return 0;
	}

	printf("\nHit!\n");
	return GetDMG();
}
int Autosniper::RightClick()
{
	if (!isScoped)
	{
		printf("\nScoped!\n");
		isScoped = true;
	}
	else
	{
		printf("\nUnscoped!\n");
		isScoped = false;
	}
	return 0;
}

// UNSCOPE WHEN SWITCHING WEAPONS