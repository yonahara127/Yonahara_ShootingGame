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
	static bool OnKeyClicked(int key);//押した瞬間
	static bool OnKeyReleased(int key);//離した瞬間
	static bool OnKeyPressed(int key);//離してる間

	static bool OnMouseClicked(int key);//押した瞬間
	static bool OnMouseReleased(int key);//離した瞬間
	static bool OnMousePressed(int key);//離してる間
};

