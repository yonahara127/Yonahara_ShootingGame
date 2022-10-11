#pragma once

class AbstractScene
{
public:
	//デストラクタ
	virtual ~AbstractScene()
	{};
	//描画以外の更新を実装する
	virtual void Update() = 0;
	//描画に関する事を実装
	virtual void Draw() const = 0;
	//シーンの変更処理
	virtual AbstractScene* ChangeScene() = 0;;;
};