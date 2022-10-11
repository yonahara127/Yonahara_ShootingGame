#pragma once

class AbstractScene
{
public:
	//�f�X�g���N�^
	virtual ~AbstractScene()
	{};
	//�`��ȊO�̍X�V����������
	virtual void Update() = 0;
	//�`��Ɋւ��鎖������
	virtual void Draw() const = 0;
	//�V�[���̕ύX����
	virtual AbstractScene* ChangeScene() = 0;;;
};