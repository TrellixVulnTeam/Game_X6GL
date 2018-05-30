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
	prefab::CSkinModelRender* m_skinModelRender2 = nullptr;	//�X�L�����f�������_���[�B
	prefab::CSkinModelRender* m_skinModelRender3 = nullptr;	//�X�L�����f�������_���[�B
	prefab::CSpriteRender* m_spriteRender = nullptr;
	CVector3 m_position= CVector3::Zero;	//���W�B
	int m_renderTargetNo = 0;
	float time = 0;

	std::vector<picture*>	m_picList;
};

