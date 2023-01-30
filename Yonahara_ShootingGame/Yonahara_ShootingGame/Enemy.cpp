#include "DxLib.h"
#include "Enemy.h"
#include "StraightBullets.h"
#include "CircleBullet.h"

struct MoveInformetion
{
	int pattern; //行動パターン
	T_Location targetLocation;
	int next; //次の配列番号
	int waitTimeFlame; //待ち時間
	int attackPattern; //攻撃の種類
};

MoveInformetion moveInfo[5] = {
	{0,    640, 150, 1,   0, 0},
	{0, 1200.4, 150, 2,   0, 2},
	{1,      0,   0, 3, 300, 1},
	{0,   80.2, 150, 4,   0, 2},
	{1,      0,   0, 1, 300, 1}
};
//
//T_Location locations[3] = {
//	{ 640,150},
//	{ 1200.4,150},
//	{ 80.2,150},
//};
//
//int next[3] = {
//	1,
//	2,
//	1
//};

int current = 0;
int waitTime = 0;

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

	//Move();

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
	switch (moveInfo[current].pattern)
	{
	case 0:
		Move();
		break;
	case 1:
		waitTime++;
		if (moveInfo[current].waitTimeFlame <= waitTime)
		{
			waitTime = 0;
			current = moveInfo[current].next;
		}
		break;

	default:
		break;
	}
	int bulletCount;
	for (bulletCount = 0; bulletCount < 30; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Updete();
		

		//画面外に行ったら玉を消す
		if (bullets[bulletCount]->isScreenOut())
		{
			DeletBullet(bulletCount);
			bulletCount--;

		}
	}
	//if (moveInfo[current].attackPattern != 0)
	//{
	//	if (bulletCount < 30 && bullets[bulletCount] == nullptr)
	//	{
	//		if (moveInfo[current].attackPattern == 1)
	//		{
	//			//弾を作る
	//			bullets[bulletCount] =
	//				new CircleBullet(GetLocation(), 2.f, (20 * shotNum));
	//		}
	//		
	//		shotNum++;
	//		//bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0,-2 });
	//	}
	//}

	if (moveInfo[current].attackPattern != 0)
	{
		if (bulletCount < 30 && bullets[bulletCount] == nullptr)
		{
			if (moveInfo[current].attackPattern == 1)
			{
				bullets[bulletCount] = new StraightBullets (GetLocation(), T_Location{ 0,2 });
			}
			else if (moveInfo[current].attackPattern == 2)
			{
				shotNum++;
				bullets[bulletCount] = new CircleBullet (GetLocation(), 2.f, (20 * shotNum));
			}
		}
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

	
	if ((nextLocation.x == moveInfo[current].targetLocation.x) &&
		(nextLocation.y == moveInfo[current].targetLocation.y))
	{
		current = moveInfo[current].next;
		return;
	}
	else
	{
		if (nextLocation.y != moveInfo[current].targetLocation.y)
		{
			if (nextLocation.y < moveInfo[current].targetLocation.y)
			{
				nextLocation.y += speed.y;
				if ((moveInfo[current].targetLocation.y <= moveInfo[current].targetLocation.y) &&
					(moveInfo[current].targetLocation.y <= nextLocation.y))
				{
					nextLocation.y = moveInfo[current].targetLocation.y;
				}
			}
			else
			{
				nextLocation.y -= speed.y;
				if ((nextLocation.y <= moveInfo[current].targetLocation.y) &&
					(moveInfo[current].targetLocation.y <= GetLocation().y))
				{
					nextLocation.y = moveInfo[current].targetLocation.y;
				}
			}
		}
		if (nextLocation.x != moveInfo[current].targetLocation.x)
		{
			if (nextLocation.x < moveInfo[current].targetLocation.x)
			{
				nextLocation.x += speed.x;
				if ((GetLocation().x <= moveInfo[current].targetLocation.x) &&
					(moveInfo[current].targetLocation.x <= nextLocation.x))
				{
					nextLocation.x = moveInfo[current].targetLocation.x;
				}
			}
			else {
				nextLocation.x -= speed.x;
				if ((nextLocation.x <= moveInfo[current].targetLocation.x) &&
					(moveInfo[current].targetLocation.x <= GetLocation().x))
				{
					nextLocation.x = moveInfo[current].targetLocation.x;
				}
			}
		}
	}

	SetLocation(nextLocation);
}