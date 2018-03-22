#pragma once
class koneta1 : public IGameObject
{
public:
	koneta1();
	~koneta1();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);
	enum EnAnimClip {
		enAnimClip_slip,		//�R�P�郂�[�V����
		enAnimClip_wakeup,		//�N���オ�胂�[�V�����B
		enAnimClip_num,			//�A�j���[�V�����f�[�^�̐��B
	};
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CAnimationClip m_animClip[enAnimClip_num];				//�A�j���[�V�����N���b�v�B
	CVector3 m_pos = CVector3::Zero;
};

