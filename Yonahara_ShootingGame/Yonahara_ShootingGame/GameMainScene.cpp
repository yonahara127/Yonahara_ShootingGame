#include "GameMainScene.h"

GameMainScene::GameMainScene()
{
	T_Location location = T_Location{ 20,100 };
	player = new Player(location);
}

//�`��ȊO�̍X�V����������
void GameMainScene::Update() 
{
	player->Update();
}
//�`��Ɋւ��鎖������
void GameMainScene::Draw() const
{
	player->Draw();
}
//�V�[���̕ύX����
AbstractScene* GameMainScene::ChangeScene() 
{
	return this;
}
