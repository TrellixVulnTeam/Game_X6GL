#pragma once
class finish : public IGameObject
{
public:
	//////////////////////////////////////
	// �����o�֐��B
	//////////////////////////////////////
	finish();
	~finish();
	bool Start();
	void Update();
	//////////////////////////////////////
	// �����o�ϐ��B
	//////////////////////////////////////
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;	//���W�B
};
