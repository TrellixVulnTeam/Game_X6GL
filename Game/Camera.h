#pragma once
class Camera 
{
public:
	Camera();
	~Camera();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);

	float time = 0;
	float timestanp[3];
	int shattercount = 0;
	CRenderTarget renderTargets[3];
	CSprite m_sprite;	//�V�[�����y�^�b�ƒ���t���邽�߂̃X�v���C�g
	int flag = 0;
};


