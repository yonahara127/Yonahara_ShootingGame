#include "SceneManager.h"

void SceneManager::Update()
{
	mScene->Update();

	return this;

}
void SceneManager::Draw() const {
	mScene->Draw();
}
