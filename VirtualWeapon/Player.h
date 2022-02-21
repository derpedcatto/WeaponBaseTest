#pragma once
#include "Weapons.h"
class Player
{
private:
	int hp = 100;
	int enemycount = 0;
	int activeweapon = 1;	//какое оружие в руках 1-6

public:
	Knife knife;
	Glock glock;
	MP5 mp5;
	M4A1 m4a1;
	AWP awp;
	Autosniper autosniper;

	void PrintStatus(int enemyhp);

	int LeftClick(int key);
	int RightClick(int key);

	void CheckHP();
	void SetHP(int hp);
	int GetHP() const;

	void AddToEnemyCount();
	int GetEnemyCount() const;

	void SetActiveWeapon(int num);
	int GetActiveWeapon() const;
};