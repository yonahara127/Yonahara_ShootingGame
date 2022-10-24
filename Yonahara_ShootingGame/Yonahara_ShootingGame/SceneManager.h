#pragma once
#include "AbstractScene.h"
class SceneManager:public AbstractScene
{
private:
	AbstractScene* mScene;//現在のシーン
public:

	SceneManager(AbstractScene* scene):mScene(scene){}

	//デストラクタ
	~SceneManager() {
		delete mScene;
	}

	void Update() override;

	void Draw() const override;

	virtual AbstractScene* ChangeScene() override;
};

