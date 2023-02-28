#pragma once
#include "SphereCollider.h"

class BulletsBase :public SphereCollider
{
private:
	int damage;
	/*T_Location speed;*/

protected:
	T_Location speed;

public:

	BulletsBase(T_Location location, float radius, int damage, T_Location speed);

public:
	virtual void Updete() = 0;
	virtual void Draw() = 0;
	virtual bool isScreenOut() = 0;
	int GetDamage();
};

