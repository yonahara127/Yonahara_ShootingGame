#pragma once
#include "AbstractScene.h"
#include "Player.h"
class GameMainScene :public AbstractScene
{
private:
	Player* player;
	
public:
	GameMainScene();
	//デストラクタ
	virtual ~GameMainScene()
	{};

public:
	//描画以外の更新を実装する
	virtual void Update() override;
	//描画に関する事を実装
	virtual void Draw() const override;
	//シーンの変更処理
	virtual AbstractScene* ChangeScene() override;
};

