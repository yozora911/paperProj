#include "SceneSelect.h"
#include "System/Graphics.h"
#include "System/Input.h"
#include "SceneManager.h"
#include "SceneGame.h"

//������
void SceneSelect::Initialize()
{
	//�X�v���C�g������
	select = new Sprite("Data/Sprite/Select.jpg");
}

//�I����
void SceneSelect::Finalize()
{
	//�X�v���C�g�I����
	if (select != nullptr)
	{

		delete select;
		select = nullptr;
	}
}

//�X�V����
void SceneSelect::Update(float elapsedTime)
{
	GamePad& gamePad = Input::Instance().GetGamePad();

	//�Ȃɂ��{�^������������Q�[���V�[���֐؂�ւ�
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

//�`�揈��
void SceneSelect::Render()
{
	Graphics& graphics = Graphics::Instance();
	ID3D11DeviceContext* dc = graphics.GetDeviceContext();
	ShapeRenderer* shapeRenderer = graphics.GetShapeRenderer();
	ModelRenderer* modelRenderer = graphics.GetModelRenderer();

	// �`�揀��
	RenderContext rc;
	rc.deviceContext = dc;
	rc.lightDirection = { 0.0f, -1.0f, 0.0f };	// ���C�g�����i�������j
	rc.renderState = graphics.GetRenderState();

	//2D�X�v���C�g�`��
	{
		//�^�C�g���`��
		float screenWidth = static_cast<float>(graphics.GetScreenWidth());
		float screenHeight = static_cast<float>(graphics.GetScreenHeight());
		select->Render(rc,
			0, 0, 0, screenWidth, screenHeight,
			0,
			1, 1, 1, 1);
	}
}

//GUI�`��
void SceneSelect::DrawGUI()
{
}
