#include "stdafx.h"
#include "testscene.h"


testscene::testscene()
{
}


testscene::~testscene()
{
}


bool testscene::Start()
{
	//�J������ݒ�B
	MainCamera().SetTarget({ 0.0f, 10.0f, 0.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(100.0f);
	MainCamera().SetPosition({ 30.0f, 40.0f, 20.0f });
	MainCamera().Update();

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });
	return true;
}
void testscene::Update()
{
}
void testscene::Render(CRenderContext& rc)
{
}
