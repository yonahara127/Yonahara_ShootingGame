#include "GameClear.h"
#include "Title.h"
#include "DxLib.h"
#include "KeyManager.h"

GameClear::GameClear()
{
}

void GameClear::Update()
{
}

void GameClear::Draw() const
{
	DrawString(550, 100, "ゲームクリア", 0xffffff, FALSE);

}
//シーンの変更処理
AbstractScene* GameClear::ChangeScene()
{

	if (KeyManager::OnKeyPressed(KEY_INPUT_A))
	{
		return new Title;
	}
	return this;
}

