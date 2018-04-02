#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "Fade.h"
class testscene : public IGameObject
{
public:
	testscene();
	~testscene();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);

	void StartFadeIn()
	{
		m_state = enState_FadeIn;
	}

	enum EnState {
		enState_FadeIn,		//!<�t�F�[�h�C�����B
		enState_FadeOut,		//!<�t�F�[�h�A�E�g���B
		enState_Idle,		//!<�A�C�h�����B
		enState_InGame
	};

	Fade* m_fade = nullptr;
	EnState m_state = enState_Idle;	//!<��ԁB
	float m_currentAlpha = 1.0f;		//!<���݂̃��l�B
	CSprite m_sprite;
	CShaderResourceView m_texture;

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CAnimationClip m_animClip[1];							//�A�j���[�V�����N���b�v�B
	CAnimation m_animation;
	CVector3 m_pos = CVector3::Zero;
};
