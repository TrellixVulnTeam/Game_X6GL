#pragma once

#include"Fade.h"
#include"modoru.h"

class selectstage : public IGameObject
{
public:
	selectstage();
	~selectstage();
	bool Start();
	void Update();

	prefab::CSpriteRender* m_spriteRender1;
	prefab::CSpriteRender* m_spriteRender2;
	prefab::CSpriteRender* m_spriteRender3;
	prefab::CSpriteRender* m_spriteRender4;


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
	float m_waitTimer = 0.0f;
	bool m_isWaitFadeout = false;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	/*Game*m_game = nullptr;*/
	CVector3 m_position = CVector3::Zero;
	modoru* md = nullptr;
};

