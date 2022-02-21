#include "Player.h"

void Player::PrintStatus(int enemyhp)
{
	printf("Player HP: %d\nEnemy HP: %d", hp, enemyhp);
	switch (GetActiveWeapon())
	{
	case 2:
	{
		printf("\nBullets %d/%d", glock.GetMagCount(), glock.GetMagSize());
		return;
	}
	case 3:
	{
		printf("\nBullets %d/%d", mp5.GetMagCount(), mp5.GetMagSize());
		return;
	}
	case 4:
	{
		printf("\nBullets %d/%d", m4a1.GetMagCount(), m4a1.GetMagSize());
		return;
	}
	case 5:
	{
		printf("\nBullets %d/%d", awp.GetMagCount(), awp.GetMagSize());
		return;
	}
	case 6:
	{
		printf("\nBullets %d/%d", autosniper.GetMagCount(), autosniper.GetMagSize());
		return;
	}
	}
}

/*Weapon action menu wheel that initiates active weapon action*/
int Player::LeftClick(int key)
{
	switch (key)
	{
	case 1:
		return knife.LeftClick();

	case 2:
		return glock.LeftClick();

	case 3:
		return mp5.LeftClick();

	case 4:
		return m4a1.LeftClick();

	case 5:
		return awp.LeftClick();

	case 6:
		return autosniper.LeftClick();
	}
}
int Player::RightClick(int key)
{
	switch (key)
	{
	case 1:
		return knife.RightClick();

	case 2:
		return glock.RightClick();

	case 3:
		return mp5.RightClick();

	case 4:
		return m4a1.RightClick();

	case 5:
		return awp.RightClick();

	case 6:
		return autosniper.RightClick();
	}
}

void Player::SetActiveWeapon(int num)
{
	activeweapon = num;
	switch (num)
	{
	case 1:
	{
		printf("1 - Knife selected!\n");
		return;
	}
	case 2:
	{
		printf("2 - Glock selected!\n");
		return;
	}
	case 3:
	{
		printf("3 - MP5 selected!\n");
		return;
	}
	case 4:
	{
		printf("4 - M4A1 selected!\n");
		return;
	}
	case 5:
	{
		printf("5 - AWP selected!\n");
		return;
	}
	case 6:
	{
		printf("6 - Autosniper selected!\n");
		return;
	}
	}
}
int Player::GetActiveWeapon() const
{
	return activeweapon;
}

void Player::CheckHP()
{
	if (GetHP() < 1)
	{
		printf("Game over!\nTotal enemies killed: %d", GetEnemyCount());
		exit(0);
	}
}
void Player::SetHP(int hp)
{
	if (hp >= 100)
	{
		this->hp = 100;
		return;
	}

	this->hp = hp;
}
int Player::GetHP() const
{
	return hp;
}

void Player::AddToEnemyCount()
{
	enemycount++;
}
int Player::GetEnemyCount() const
{
	return enemycount;
}