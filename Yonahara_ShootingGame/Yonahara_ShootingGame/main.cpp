#include "DxLib.h"
#include "SceneManager.h"

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	// �^�C�g���� test �ɕύX
	SetMainWindowText("ShootingGame");

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	SetFontSize(20);		// �����T�C�Y��ݒ�

	SceneManager sceneMng((AbstractScene*)new Title());
	// �Q�[�����[�v
	while (ProcessMessage() == 0 ) {

		
		ClearDrawScreeen();
        sceneMng.Update();
		sceneMng.Draw();
		if (sceneMng.ChangeScene() != nullptr)
		{
			DxLib_End();//DX���C�u�����g�p�̏C������

			return 0;//�\�t�g�̏I��
		}
		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f

	}

	DxLib_End();	// DX���C�u�����g�p�̏I������

	return 0;	// �\�t�g�̏I��
}
