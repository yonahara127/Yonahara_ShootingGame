#pragma once
#include "CharaBase.h"
struct MoveInformetion
{
	int pattern; //行動パターン
	T_Location targetLocation; //目的地
	int next; //次の配列番号
	int waitTimeFlame; //待ち時間
	int attackPattern; //攻撃の種類
};
class Enemy2 :public CharaBase
{
	private:
		int hp;
		int point;
		int shotNum;

		MoveInformetion moveInfo[5] = {
		};

		int current = 0;
		int waitTime = 0;

	public:
		Enemy2(T_Location location);

	public:
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Hit(int damage) override;
		bool HpCHeck();
		int GetPoint();
		void Move();
		void inputCSV();

};

