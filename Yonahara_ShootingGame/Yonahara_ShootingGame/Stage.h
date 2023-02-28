#pragma once
#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy2.h"
#include "ItemBase.h"
#include "Title.h"
class Stage :public AbstractScene
{
private:
	Player* player;
	Enemy2** enemy;
	ItemBase** items;
	int Deletenemy;
public:
	Stage();
	//デストラクタ
	virtual ~Stage()
	{};

public:
	//描画以外の更新を実装する
	virtual void Update() override;
	//描画に関する事を実装
	virtual void Draw() const override;
	//シーンの変更処理
	virtual AbstractScene* ChangeScene() override;
};
