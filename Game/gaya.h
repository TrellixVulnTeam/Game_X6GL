#pragma once
class gaya : public IGameObject
{
public:
	gaya();
	~gaya();
	bool Start();
	
	void Update();

	float time = 0;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[
	prefab::CSkinModelRender* m_skinModelRender2 = nullptr;	//�X�L�����f�������_���[
	prefab::CSkinModelRender* m_skinModelRender3 = nullptr;	//�X�L�����f�������_���[
	CVector3 m_position = CVector3::Zero;
	CVector3 m_position2 = CVector3::Zero;
	CVector3 m_position3 = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;	//��]�B
	CQuaternion m_rotation2 = CQuaternion::Identity;	//��]�B
	CQuaternion m_rotation3 = CQuaternion::Identity;	//��]�B
	int returnFlag = 0;
};

