#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"

class error;

class Camera : public IGameObject
{
public:
	Camera();
	~Camera();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);

	float time = 0;
	float timestanp[3];
	int shattercount = 0;
	CRenderTarget renderTargets[3];
	CSprite m_sprite;	//�V�[�����y�^�b�ƒ���t���邽�߂̃X�v���C�g
	int flag = 0;
	prefab::CSoundSource* m_bgmSoundSource = nullptr;	//BGM�p�̃T�E���h�\�[�X�B
	CVector3 m_pos = CVector3::Zero;
	
};