#pragma once
#include "AbstractScene.h"
class Title :public AbstractScene
{
private:
	

public:
	Title();
	//�f�X�g���N�^
	virtual ~Title()
	{};

public:
	//�`��ȊO�̍X�V����������
	virtual void Update() override;
	//�`��Ɋւ��鎖������
	virtual void Draw() const override;
	//�V�[���̕ύX����
	virtual AbstractScene* ChangeScene() override;
};

