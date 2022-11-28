#pragma once
#include "BulletsBase.h"
class StraightBullets :public BulletsBase
{
public:
	StraightBullets(T_Location location, T_Location Speed);

public:
	virtual void Updete() override;
	virtual void Draw() override;
	virtual bool isScreenOut() override;
};

