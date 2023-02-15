#pragma once
#include "AbstractScene.h"
class GameClear :public AbstractScene
{
private:
	

public:
	GameClear();
	//デストラクタ
	virtual ~GameClear()
	{};

public:
	//描画以外の更新を実装する
	virtual void Update() override;
	//描画に関する事を実装
	virtual void Draw() const override;
	//シーンの変更処理
	virtual AbstractScene* ChangeScene() override;
};


