#include "Stage.h"
#include "GameMainScene.h"
#include "CharaBase.h"
#include "Recovery.h"
#include "Player.h"
#include "comon.h"
#include "Title.h"
#include "KeyManager.h"
#include "DxLib.h"
#include "GameClear.h"
#include "GameOver.h"

Stage::Stage()
{
	T_Location location = T_Location{ 600,600 };
	player = new Player(location);
	enemy = new Enemy2 * [10];
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;
	}
	//enemy[0] = new Enemy(T_Location{ 200,0 });
	enemy[0] = new Enemy2(T_Location{ SCREEN_WIDTH / 2,-30 });

	items = new ItemBase * [10];
	for (int i = 0; i < 10; i++)
	{
		items[i] = nullptr;
	}
}

//描画以外の更新を実装する
void Stage::Update()
{
	player->Update();

	int enemyCount;
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		enemy[enemyCount]->Update();
	}

	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;
		}
		items[i]->Update();
	}

	BulletsBase** bullet = player->GetBullets();
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		for (int bulletCount = 0; bulletCount < 30; bulletCount++)
		{
			if (bullet[bulletCount] == nullptr)
			{
				break;
			}
			if (enemy[enemyCount]->HitSphere(bullet[bulletCount]))
			{
				//エネミーにプレイヤーの玉がヒットしたいる

				//エネミーにダメージを与えます。
				enemy[enemyCount]->Hit(bullet[bulletCount]->GetDamage());

				//弾を削除します。
				player->DeletBullet(bulletCount);
				bulletCount--;

				//エネミーのHPが0以下だったら、エネミーを削除します。
				if (enemy[enemyCount]->HpCHeck())
				{
					for (int i = 0; i < 10; i++)
					{
						if (items[i] == nullptr)
						{
							items[i] = new Recovery(enemy[enemyCount]->GetLocation());
							break;
						}
					}


					//スコアの加算
					player->AddScore(enemy[enemyCount]->GetPoint());


					//エネミーの削除
					delete enemy[enemyCount];
					enemy[enemyCount] = nullptr;

					//配列を前に詰める
					for (int i = enemyCount; i < (10 - 1); i++)
					{
						if (enemy[i + 1] == nullptr)
						{
							break;
						}
						enemy[i - 1] = enemy[1];
						enemy[i] = nullptr;
					}
					enemyCount--;
					break;
				}

			}
		}
	}

	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		bullet = enemy[enemyCount]->GetBullets();
		for (int i = 0; i < 30; i++)
		{
			if (bullet[i] == nullptr)
			{
				break;
			}
			if (player->HitSphere(bullet[i]))
			{
				player->Hit(bullet[i]->GetDamage());

				enemy[enemyCount]->DeletBullet(i);
				i--;
			}
		}
	}

	for (int itemCount = 0; itemCount < 10; itemCount++)
	{
		if (items[itemCount] == nullptr)
		{
			break;
		}
		if (items[itemCount]->HitSphere(player) == true)
		{
			//回復処理
			player->Hit(items[itemCount]);

			//エネミーの削除
			delete items[itemCount];
			items[itemCount] = nullptr;

			//配列を前に詰める
			for (int i = itemCount; i < 10; i++)
			{
				if (items[i] == nullptr)
				{
					break;
				}
				items[i - 1] = items[i];
				items[i] = nullptr;
			}
			itemCount--;
			break;
		}
	}
}

//描画に関する事を実装
void Stage::Draw() const
{

	player->Draw();

	for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		enemy[enemyCount]->Draw();
	}
	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;
		}
		items[i]->Draw();
	}
}
//シーンの変更処理
AbstractScene* Stage::ChangeScene()
{
	int enemyCount;
	if (player->LifeCheck() == true)
	{
		return new GameOver;
	}
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] != nullptr)
		{
			break;
		}
		else if (enemy[9] == nullptr)
		{
			return new GameClear;
		}
	}
	return this;
}
