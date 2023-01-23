#include "DxLib.h"
#include "SceneManager.h"
#include "GameMainScene.h"
#include "KeyManager.h"

//#define SCREEN_WIDTH 1280;
//#define SCREEN_HEIGHT 720;
//#define SCREEN_COLOR_BIT_16;

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	// タイトルを test に変更
	SetMainWindowText("ShootingGame");

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	SetWindowSize(SCREEN_WIDTH,SCREEN_HEIGHT);
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR );



	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SetFontSize(20);		// 文字サイズを設定

	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new GameMainScene()));
	// ゲームループ
	while (ProcessMessage() == 0 ) 
	{
		ClearDrawScreen();

		KeyManager::Update();
		/*KeyManager::;*/

        sceneMng.Update();
		sceneMng.Draw();
		if (sceneMng.ChangeScene() == nullptr)
		{
			DxLib_End();//DXライブラリ使用の修了処理

			return 0;//ソフトの終了
		}
		ScreenFlip();			// 裏画面の内容を表画面に反映

	}

	DxLib_End();	// DXライブラリ使用の終了処理

	return 0;	// ソフトの終了
}
