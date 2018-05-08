#pragma once
class picture : public IGameObject
{
public:
	picture();
	~picture();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 m_position= CVector3::Zero;	//���W�B
	int m_renderTargetNo = 0;
};

