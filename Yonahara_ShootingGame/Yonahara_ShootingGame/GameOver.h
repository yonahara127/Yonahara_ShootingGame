#pragma once
#include "AbstractScene.h"
class GameOver :public AbstractScene
{
private:


public:
	GameOver();
	//�f�X�g���N�^
	virtual ~GameOver()
	{};

public:
	//�`��ȊO�̍X�V����������
	virtual void Update() override;
	//�`��Ɋւ��鎖������
	virtual void Draw() const override;
	//�V�[���̕ύX����
	virtual AbstractScene* ChangeScene() override;
};

