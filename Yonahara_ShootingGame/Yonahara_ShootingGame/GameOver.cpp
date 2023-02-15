#include "GameOver.h"
#include "Title.h"
#include "DxLib.h"
#include "KeyManager.h"

GameOver::GameOver()
{
}

void GameOver::Update()
{
}

void GameOver::Draw() const
{
	DrawString(550, 100, "�Q�[���I�[�o�[", 0xffffff, FALSE);

}
//�V�[���̕ύX����
AbstractScene* GameOver::ChangeScene()
{

	if (KeyManager::OnKeyPressed(KEY_INPUT_A))
	{
		return new Title;
	}
	return this;
}
