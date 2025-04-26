#pragma once

#include "System/Sprite.h"
#include "Scene.h"

//�Z���N�g�V�[��
class SceneSelect : public Scene
{
public:
	SceneSelect() {};
	~SceneSelect() {};

	//������
	void Initialize() override;

	//�I����
	void Finalize() override;

	//�X�V����
	void Update(float elapsedTime) override;

	//�`�揈��
	void Render() override;

	//GUI�`��
	void DrawGUI() override;

private:
	Sprite* select = nullptr;
};
