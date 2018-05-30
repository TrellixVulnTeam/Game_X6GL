#pragma once
#include"NetaBase.h"

class koneta1 : public NetaBase
{
public:
	koneta1();
	~koneta1();
	bool Start();
	void Update();
	enum EnAnimClip {
		enAnimClip_idle,        //�ҋ@�A�j���[�V�����B
		enAnimClip_slip,		//�R�P�郂�[�V����
		enAnimClip_wakeup,		//�N���オ�胂�[�V�����B
		enAnimClip_num,			//�A�j���[�V�����f�[�^�̐��B
	};
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CAnimationClip m_animClip[enAnimClip_num];				//�A�j���[�V�����N���b�v�B
	int flag = 0;
};

