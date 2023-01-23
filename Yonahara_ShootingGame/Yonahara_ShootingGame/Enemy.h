#pragma once
#include "CharaBase.h"
class Enemy :public CharaBase
{
private:
	int hp;
	int point;
	int shotNum;
public:
	Enemy(T_Location location);

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Hit(int damage) override;
	bool HpCHeck();
	int GetPoint();
	void Move();
};

