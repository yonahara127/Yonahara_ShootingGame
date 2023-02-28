#include "StraightBullets2.h"
#include <DxLib.h>

StraightBullets2::StraightBullets2(T_Location location, T_Location speed)
	:BulletsBase(location, 5.f, 1, speed)
{

}
void StraightBullets2::Updete()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);
}
void StraightBullets2::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 190, 155));

}
bool  StraightBullets2::isScreenOut()
{
	bool ret = ((GetLocation().x + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}
	ret = (720 <= (GetLocation().x - GetRadius()));
	return ret;
}