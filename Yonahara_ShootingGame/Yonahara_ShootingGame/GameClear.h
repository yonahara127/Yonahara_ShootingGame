#pragma once
#include "AbstractScene.h"
class GameClear :public AbstractScene
{
private:
	

public:
	GameClear();
	//�f�X�g���N�^
	virtual ~GameClear()
	{};

public:
	//�`��ȊO�̍X�V����������
	virtual void Update() override;
	//�`��Ɋւ��鎖������
	virtual void Draw() const override;
	//�V�[���̕ύX����
	virtual AbstractScene* ChangeScene() override;
};


