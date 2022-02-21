#pragma once
#include <iostream>
#include "WeaponBase.h"

class Knife : public WeaponBase
{
public:
	Knife();
	int LeftClick();
	int RightClick();
};

class Glock : public WeaponBase
{
private:
	bool secondaryFire = false;

public:
	Glock();
	int LeftClick();
	int RightClick();
};

class MP5 : public WeaponBase
{
private:
	int firemode = 1;	//1 - 1 bullet, 2 - burst fire, 3 - full auto

public:
	MP5();
	int LeftClick();
	int RightClick();
};

class M4A1 : public WeaponBase
{
private:
	int firemode = 1;	//1 - 1 bullet, 2 - burst fire, 3 - full auto

public:
	M4A1();
	int LeftClick();
	int RightClick();
};

class AWP : public WeaponBase
{
private:
	bool isCocked = true;

public:
	AWP();
	int LeftClick();
	int RightClick();
};

class Autosniper : public WeaponBase
{
private:
	bool isScoped = false;

public:
	Autosniper();
	int LeftClick();
	int RightClick();

};