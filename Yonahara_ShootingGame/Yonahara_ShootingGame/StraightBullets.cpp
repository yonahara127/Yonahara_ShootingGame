#include "StraightBullets.h"
#include <DxLib.h>




StraightBullets::StraightBullets(T_Location location ,T_Location speed)
:BulletsBase(location,5.f,1,speed)
{

}
void StraightBullets::Updete()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);
}
void StraightBullets::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));

 }
bool  StraightBullets::isScreenOut()
{
	bool ret = ((GetLocation().y +GetRadius())<= 0);
	if (ret)
	{
		return ret;
	}
	ret = (720 <= (GetLocation().y - GetRadius()));
	return ret;
}