#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"

class error;

class Camera : public IGameObject
{
public:
	struct SShutterData {
		float time;				//�V���b�^�[�������ꂽ���ԁB
		bool isExistNeta[3];	//�l�^���������Ă��邩�ǂ����̃t���O�B
		CVector3 netaPos[3];	//�l�^�̍��W�B
		CMatrix mView;			//�V���b�^�[���������Ƃ��̃J�����s��B
	};
	Camera();
	~Camera();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);

	float time = 0;
	//float timestanp[3];
	SShutterData shutterData[3];
	int shattercount = 0;
	CRenderTarget renderTargets[3];
	CSprite m_sprite;	//�V�[�����y�^�b�ƒ���t���邽�߂̃X�v���C�g
	int flag = 0;
	prefab::CSoundSource* m_bgmSoundSource = nullptr;	//BGM�p�̃T�E���h�\�[�X�B
	CVector3 m_pos = CVector3::Zero;
	
};