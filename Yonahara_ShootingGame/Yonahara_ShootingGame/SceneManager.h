#pragma once
#include "AbstractScene.h"
class SceneManager:public AbstractScene
{
private:
	AbstractScene* mScene;//���݂̃V�[��
public:

	SceneManager(AbstractScene* scene):mScene(scene){}

	//�f�X�g���N�^
	~SceneManager() {
		delete mScene;
	}

	void Update() override;

	void Draw() const override;

	virtual AbstractScene* ChangeScene() override;
};

