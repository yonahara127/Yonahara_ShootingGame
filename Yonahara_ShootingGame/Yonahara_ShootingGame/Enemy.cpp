#include "DxLib.h"
#include "Enemy.h"
#include "StraightBullets.h"
#include "CircleBullet.h"

struct MoveInformetion
{
	T_Location targetLocation;
	int pattern;
	int next;
	int waitTimeFlame;
	int attackPattern;
};

MoveInformation moveInfo[10] = {
	{    640,150,0,1,0,0},
	{ 1200.4,150,0,2,0,0},
	{      0,0,1,3,180,1},
	{ 80.2,150,0,4,  0,2},
	{    0,  0,1,5,180,1},
	{1200.4,150, 0, 2, 0,1},
};

T_Location locations[3] = {
	{ 640,150},
	{ 1200.4,150},
	{ 80.2,150},
};

int next[3] = {
	1,
	2,
	1
};

int current = 0;

Enemy::Enemy(T_Location location):CharaBase(location,20.f,T_Location{5,1})
,hp(10),point(10),shotNum(0)
{
	bullets = new BulletsBase * [30];
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}
}
void Enemy::Update() 
{

	Move();

	/*T_Location newLocation = GetLocation();
	newLocation.y +=speed.y;
	SetLocation(newLocation);*/
	/*T_Location newLocation = GetLocation();
	if (newLocation.y <= 50)
	{
		speed = { 0,1 };
		newLocation.y += speed.y;
		SetLocation(newLocation);
	}
	else if(newLocation.x >= 0)
	{
		speed = { 1,0 };
		newLocation.x -= speed.x;
		SetLocation(newLocation);
	}
	else if (newLocation.y <= 100)
	{
		speed = { 0,1 };
		newLocation.y += speed.y;
		SetLocation(newLocation);
	}
	else if (newLocation.x <= 80)
	{
		speed = { 1,0 };
		newLocation.x += speed.x;
		SetLocation(newLocation);
	}*/

	int bulletCount;
	for (bulletCount = 0; bulletCount < 30; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Updete();
		

		//‰æ–ÊŠO‚És‚Á‚½‚ç‹Ê‚ðÁ‚·
		if (bullets[bulletCount]->isScreenOut())
		{
			DeletBullet(bulletCount);
			bulletCount--;

		}
	}
	
		if (bulletCount < 30 && bullets[bulletCount] == nullptr)
		{
			//’e‚ðì‚é
			bullets[bulletCount] =
				new CircleBullet(GetLocation(), 2.f, (20 * shotNum));
			shotNum++;
			//bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0,-2 });
		}
		

}
void Enemy::Draw() 
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));

	for (int bulletCount = 0; bulletCount < 30; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Draw();
	}
}
void Enemy::Hit(int damage)
{
	if (0 < damage)
	{
		hp -= damage;
		if (hp < 0)
		{
			hp = 0;
		}
	}
}
bool Enemy::HpCHeck() 
{
	bool ret = (hp <= 0);
	return ret;
	
}
int Enemy::GetPoint() 
{
	return point;
}


void Enemy::Move()
{
	T_Location nextLocation = GetLocation();

	
	if ((nextLocation.y == locations[current].y) &&
		(nextLocation.x == locations[current].x))
	{
		current = next[current];
	}
	else
	{
		if (nextLocation.y != locations[current].y)
		{
			if (nextLocation.y < locations[current].y)
			{
				nextLocation.y += speed.y;
				if ((GetLocation().y <= locations[current].y) &&
					(locations[current].y <= nextLocation.y))
				{
					nextLocation.y = locations[current].y;
				}
			}
			else
			{
				nextLocation.y -= speed.y;
				if ((nextLocation.y <= locations[current].y) &&
					(locations[current].y <= GetLocation().y))
				{
					nextLocation.y = locations[current].y;
				}
			}
		}
		if (nextLocation.x != locations[current].x)
		{
			if (nextLocation.x < locations[current].x)
			{
				nextLocation.x += speed.x;
				if ((GetLocation().x <= locations[current].x) &&
					(locations[current].x <= nextLocation.x))
				{
					nextLocation.x = locations[current].x;
				}
			}
			else {
				nextLocation.x -= speed.x;
				if ((nextLocation.x <= locations[current].x) &&
					(locations[current].x <= GetLocation().x))
				{
					nextLocation.x = locations[current].x;
				}
			}
		}
	}

	SetLocation(nextLocation);
}