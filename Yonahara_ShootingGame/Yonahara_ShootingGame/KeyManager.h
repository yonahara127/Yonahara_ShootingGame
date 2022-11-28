#pragma once
class KeyManager
{
private:
	static char oldKey[256];
	static char nowKey[256];

	static int oldMouse;
	static int nowMouse;

private:
	KeyManager() = default;

public:
	static void Update();
	static bool OnKeyClicked(int key);//�������u��
	static bool OnKeyReleased(int key);//�������u��
	static bool OnKeyPressed(int key);//�����Ă��

	static bool OnMouseClicked(int key);//�������u��
	static bool OnMouseReleased(int key);//�������u��
	static bool OnMousePressed(int key);//�����Ă��
};

