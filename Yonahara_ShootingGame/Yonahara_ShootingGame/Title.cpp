#include "Title.h"
#include "GameMainScene.h"
#include "DxLib.h"
#include "KeyManager.h"


Title::Title()
{
	
}
//描画以外の更新を実装する
void Title::Update()
{
	
}
void Title::Draw() const
{
	DrawString(550, 100, "タイトル", 0xffffff, FALSE);
	
}
//シーンの変更処理
AbstractScene* Title::ChangeScene()
{
	
	if (KeyManager::OnKeyPressed(KEY_INPUT_Z))
	{
		return new GameMainScene;
	}
	return this;
}
