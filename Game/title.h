#pragma once
class Fade;


class title : public IGameObject
{
public:
	/////////////////////////////////////////////
	//�����o�֐��B
	/////////////////////////////////////////////
	title();
	~title();
	bool Start()override;
	void Update()override;

	/////////////////////////////////////////////
	//�����o�ϐ��Ƃ��B
	/////////////////////////////////////////////
	
	prefab::CSpriteRender* m_spriteRender;
	CVector3	m_position;		//���W�B
	CQuaternion m_rotation;	//��]�B
private:
	bool m_isWaitFadeout = false;
	Fade* m_fade = nullptr;
	CFont m_font;
};