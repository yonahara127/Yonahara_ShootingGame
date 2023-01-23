#include "DxLib.h"
#include "SceneManager.h"
#include "GameMainScene.h"
#include "KeyManager.h"

//#define SCREEN_WIDTH 1280;
//#define SCREEN_HEIGHT 720;
//#define SCREEN_COLOR_BIT_16;

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	// �^�C�g���� test �ɕύX
	SetMainWindowText("ShootingGame");

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	SetWindowSize(SCREEN_WIDTH,SCREEN_HEIGHT);
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR );



	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	SetFontSize(20);		// �����T�C�Y��ݒ�

	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new GameMainScene()));
	// �Q�[�����[�v
	while (ProcessMessage() == 0 ) 
	{
		ClearDrawScreen();

		KeyManager::Update();
		/*KeyManager::;*/

        sceneMng.Update();
		sceneMng.Draw();
		if (sceneMng.ChangeScene() == nullptr)
		{
			DxLib_End();//DX���C�u�����g�p�̏C������

			return 0;//�\�t�g�̏I��
		}
		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f

	}

	DxLib_End();	// DX���C�u�����g�p�̏I������

	return 0;	// �\�t�g�̏I��
}
