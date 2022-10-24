#include "SceneManager.h"

void SceneManager::Update()
{
	//Œ»Ý
	mScene->Update();

	/*return this;*/

}
void SceneManager::Draw() const {
	mScene->Draw();
}
AbstractScene* SceneManager::ChangeScene()
{
	AbstractScene* nextScene = mScene->ChangeScene();

	if (nextScene != mScene) {
		delete mScene;
		mScene = nextScene;
	}
	return nextScene;
}
