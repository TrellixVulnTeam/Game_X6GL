#include "stdafx.h"
#include "testscene.h"
#include"koneta1.h"
#include"banana.h"
#include"koneta2.h"
#include"ike.h"

testscene::testscene()
{
}


testscene::~testscene()
{
}


bool testscene::Start()
{
	m_camera.Start();

	//�J������ݒ�B
	MainCamera().SetTarget({ 0.0f, 10.0f, 0.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(100.0f);
	MainCamera().SetPosition({ 30.0f, 40.0f, 20.0f });
	MainCamera().Update();

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });

	NewGO<koneta1>(0, "koneta1");
	NewGO<banana>(0, "banana");
	NewGO<koneta2>(0, "koneta2");
	NewGO<ike>(0, "ike");
	return true;
}
void testscene::Update()
{
	m_camera.Update();
}

void testscene::Render(CRenderContext& rc)
{
	m_camera.Render(rc);
}
