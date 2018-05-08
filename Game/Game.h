#pragma once

#include "Camera.h"
#include "tkEngine/graphics/effect/tkEffect.h"
#include"sceneplayer.h"
#include "Fade.h"
#include "Camera.h"
class Game : public IGameObject
{
public:
	enum EnAnimClip {
		enAnimClip_slip,		//�R�P�郂�[�V����
		enAnimClip_wakeup,		//�N���オ�胂�[�V�����B
		enAnimClip_num,			//�A�j���[�V�����f�[�^�̐��B
	};
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	prefab::CSpriteRender* m_spriteRender;
	CAnimationClip m_animClip[enAnimClip_num];				//�A�j���[�V�����N���b�v�B
	CVector3 m_pos = CVector3::Zero;
	sceneplayer m_sceneplayer;

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
	float m_waitTimer = 0.0f;
	Camera m_camera;
	CVector3 m_position = CVector3::Zero;

	float time = 0;
};

