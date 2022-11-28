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
	static bool OnKeyClicked(int key);//‰Ÿ‚µ‚½uŠÔ
	static bool OnKeyReleased(int key);//—£‚µ‚½uŠÔ
	static bool OnKeyPressed(int key);//—£‚µ‚Ä‚éŠÔ

	static bool OnMouseClicked(int key);//‰Ÿ‚µ‚½uŠÔ
	static bool OnMouseReleased(int key);//—£‚µ‚½uŠÔ
	static bool OnMousePressed(int key);//—£‚µ‚Ä‚éŠÔ
};

