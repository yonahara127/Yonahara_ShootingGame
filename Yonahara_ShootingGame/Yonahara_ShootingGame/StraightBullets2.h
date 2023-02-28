#pragma once
#include "BulletsBase.h"

class StraightBullets2 :public BulletsBase
{

	public:
		StraightBullets2(T_Location location, T_Location Speed);

	public:
		virtual void Updete() override;
		virtual void Draw() override;
		virtual bool isScreenOut() override;
};

