#pragma once
#include <iostream>

class WeaponBase abstract
{
private:
	int dmg;
	int accuracy;
	int magsize;
	int magcount;

public:
	virtual int LeftClick() = 0;
	virtual int RightClick() = 0;

	int FireBullet();

	void SetDMG(int dmg);
	void SetAccuracy(int accuracy);
	void SetMagSize(int magsize);
	void SetMagCount(int magcount);

	int GetDMG() const;
	int GetAccuracy() const;
	int GetMagSize() const;
	int GetMagCount() const;
};