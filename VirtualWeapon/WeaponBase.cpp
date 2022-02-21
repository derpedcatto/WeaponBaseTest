#include "WeaponBase.h"

int WeaponBase::FireBullet()
{
	if (magcount == 0)
	{
		printf("\nReloading...\n");
		magcount = magsize;
		return 1;
	}
	magcount--;
	return 0;
}

void WeaponBase::SetDMG(int dmg)
{
	this->dmg = dmg;
}
void WeaponBase::SetAccuracy(int accuracy)
{
	this->accuracy = accuracy;
}
void WeaponBase::SetMagSize(int magsize)
{
	this->magsize = magsize;
}
void WeaponBase::SetMagCount(int magcount)
{
	this->magcount = magcount;
}

int WeaponBase::GetDMG() const
{
	return dmg;
}
int WeaponBase::GetAccuracy() const
{
	return accuracy;
}
int WeaponBase::GetMagSize() const
{
	return magsize;
}
int WeaponBase::GetMagCount() const
{
	return magcount;
}