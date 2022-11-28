#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
#include "ItemBase.h"
class GameMainScene :public AbstractScene
{
private:
	Player* player;
	Enemy** enemy;
	ItemBase** items;
	int Deletenemy;
public:
	GameMainScene();
	//�f�X�g���N�^
	virtual ~GameMainScene()
	{};

public:
	//�`��ȊO�̍X�V����������
	virtual void Update() override;
	//�`��Ɋւ��鎖������
	virtual void Draw() const override;
	//�V�[���̕ύX����
	virtual AbstractScene* ChangeScene() override;
};

