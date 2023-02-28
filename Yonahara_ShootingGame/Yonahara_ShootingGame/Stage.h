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
	//�f�X�g���N�^
	virtual ~Stage()
	{};

public:
	//�`��ȊO�̍X�V����������
	virtual void Update() override;
	//�`��Ɋւ��鎖������
	virtual void Draw() const override;
	//�V�[���̕ύX����
	virtual AbstractScene* ChangeScene() override;
};
