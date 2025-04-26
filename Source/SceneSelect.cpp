#include "SceneSelect.h"
#include "System/Graphics.h"
#include "System/Input.h"
#include "SceneManager.h"
#include "SceneGame.h"

//初期化
void SceneSelect::Initialize()
{
	//スプライト初期化
	select = new Sprite("Data/Sprite/Select.jpg");
}

//終了化
void SceneSelect::Finalize()
{
	//スプライト終了化
	if (select != nullptr)
	{

		delete select;
		select = nullptr;
	}
}

//更新処理
void SceneSelect::Update(float elapsedTime)
{
	GamePad& gamePad = Input::Instance().GetGamePad();

	//なにかボタンを押したらゲームシーンへ切り替え
	const GamePadButton anyButton =
		GamePad::BTN_A
		| GamePad::BTN_B
		| GamePad::BTN_X
		| GamePad::BTN_Y
		;

	if (gamePad.GetButtonDown() & anyButton)
	{
		SceneManger::Instance().ChangeScene(new SceneGame);
	}

}

//描画処理
void SceneSelect::Render()
{
	Graphics& graphics = Graphics::Instance();
	ID3D11DeviceContext* dc = graphics.GetDeviceContext();
	ShapeRenderer* shapeRenderer = graphics.GetShapeRenderer();
	ModelRenderer* modelRenderer = graphics.GetModelRenderer();

	// 描画準備
	RenderContext rc;
	rc.deviceContext = dc;
	rc.lightDirection = { 0.0f, -1.0f, 0.0f };	// ライト方向（下方向）
	rc.renderState = graphics.GetRenderState();

	//2Dスプライト描画
	{
		//タイトル描画
		float screenWidth = static_cast<float>(graphics.GetScreenWidth());
		float screenHeight = static_cast<float>(graphics.GetScreenHeight());
		select->Render(rc,
			0, 0, 0, screenWidth, screenHeight,
			0,
			1, 1, 1, 1);
	}
}

//GUI描画
void SceneSelect::DrawGUI()
{
}
