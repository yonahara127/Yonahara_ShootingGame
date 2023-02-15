#include "Title.h"
#include "GameMainScene.h"
#include "DxLib.h"
#include "KeyManager.h"


Title::Title()
{
	
}
//�`��ȊO�̍X�V����������
void Title::Update()
{
	
}
void Title::Draw() const
{
	DrawString(550, 100, "�^�C�g��", 0xffffff, FALSE);
	
}
//�V�[���̕ύX����
AbstractScene* Title::ChangeScene()
{
	
	if (KeyManager::OnKeyPressed(KEY_INPUT_Z))
	{
		return new GameMainScene;
	}
	return this;
}
