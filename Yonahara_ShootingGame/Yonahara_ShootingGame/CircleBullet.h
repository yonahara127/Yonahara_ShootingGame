#pragma once
#include "BulletsBase.h"
class CircleBullet : public BulletsBase
{
public:
	CircleBullet(T_Location location, float speed, int degAngle);

public:
	virtual void Updete() override;
	virtual void Draw() override;
	virtual bool isScreenOut() override;
};

