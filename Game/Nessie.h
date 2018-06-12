#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "NetaBase.h"

class Nessie : public NetaBase
{
public:
	Nessie();
	~Nessie();
	bool Start();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	prefab::CSoundSource* m_bgmSoundSource = nullptr;	//BGM�p�̃T�E���h�\�[�X�B
	int NFlag = 0;
};