#pragma once
#include "BulletsBase.h"
class StraightBullets :public BulletsBase
{
public:
	StraightBullets(T_Location location);

public:
	virtual void Updete() override;
	virtual void Draw() override;
};

