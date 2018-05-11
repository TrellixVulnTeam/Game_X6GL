#pragma once
class Title :public IGameObject
{
public:
	Title();
	~Title();
	bool Start();
	void Update();

	enum EnAnimClip {
		enAnimClip_jj,   //�^�C�g���̃A�j���[�V����
		enAnimClip_num,
	};
	CSkinModel m_skinModel;			//�X�L�����f��
	CSkinModelData m_skinModelData;	//�X�L�����f���f�[�^
	CAnimationClip m_animClip[enAnimClip_num];	//�A�j���[�V�����N���b�v
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;	//JJ���f���̍��W
	CQuaternion m_rotation = CQuaternion::Identity;	//��]
};

