#include "StraightBullets.h"
#include <DxLib.h>
StraightBullets::StraightBullets(T_Location location)
:BulletsBase(location,5.f,1,T_Location{0,2})
{

}
void StraightBullets::Updete()
{
	T_Location newLocation = GetLocation();
	newLocation.y -= speed.y;
	SetLocation(newLocation);
}
void StraightBullets::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
 }