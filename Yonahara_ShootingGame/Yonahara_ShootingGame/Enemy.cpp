#include "DxLib.h"
#include "Enemy.h"
#include "StraightBullets.h"
#include "CircleBullet.h"






void Enemy::inputCSV()
{
	FILE* fp; //FILE構造体
	errno_t error; //fopen_sのエラー確認

	error = fopen_s(&fp, "CSV/Yonahara_ShootingGame.vcxproj.FileListAbsolute.csv", "r");
	if (error != 0)
	{
		//エラー発生
		return;
	}
	else
	{
		//ファイルを開いた
		char line[100];
		for(int i = 0; fgets(line, 100, fp) !=NULL; i++)
		//while (fgets(line, 100, fp) !=NULL)
		{
			sscanf_s(line, "%d, %f, %f, %d, %d, %d",
				&moveInfo[i].pattern,
			    &moveInfo[i].targetLocation.x,
			    &moveInfo[i].targetLocation.y,
			    &moveInfo[i].next,
			    &moveInfo[i].waitTimeFlame,
			    &moveInfo[i].attackPattern);
		}

		return;
	}
	fclose(fp); //ファイルを閉じる
}

Enemy::Enemy(T_Location location):CharaBase(location,20.f,T_Location{5,1})
,hp(10),point(10),shotNum(0)
{
	inputCSV();
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