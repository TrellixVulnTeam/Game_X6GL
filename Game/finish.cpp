#include "stdafx.h"
#include "finish.h"


finish::finish()
{
}


finish::~finish()
{
}
bool finish::Start()
{
	//�J������ݒ�B
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();

	//�X�L�����f�������_���[���쐬�B
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/news.cmo");
	m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });
	/*m_position.y = 200;
	m_skinModelRender->SetPosition(m_position);*/
	
	return true;
}
void finish::Update()
{ 
	/*m_position.y =+ 10.0f;
	m_skinModelRender->SetPosition(m_position);*/
}