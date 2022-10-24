#include "GameMainScene.h"

GameMainScene::GameMainScene()
{
	T_Location location = T_Location{ 20,100 };
	player = new Player(location);
}

//描画以外の更新を実装する
void GameMainScene::Update() 
{
	player->Update();
}
//描画に関する事を実装
void GameMainScene::Draw() const
{
	player->Draw();
}
//シーンの変更処理
AbstractScene* GameMainScene::ChangeScene() 
{
	return this;
}
