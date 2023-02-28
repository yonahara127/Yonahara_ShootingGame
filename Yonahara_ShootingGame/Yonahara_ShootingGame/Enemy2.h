#pragma once
#include "CharaBase.h"
struct MoveInformetion
{
	int pattern; //�s���p�^�[��
	T_Location targetLocation; //�ړI�n
	int next; //���̔z��ԍ�
	int waitTimeFlame; //�҂�����
	int attackPattern; //�U���̎��
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

