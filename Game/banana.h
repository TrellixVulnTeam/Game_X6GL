#pragma once
class banana : public IGameObject
{
public:
	banana();
	~banana();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero;	//���W�B
	CQuaternion m_rotation = CQuaternion::Identity;
};
