#include "stdafx.h"
#include "Game.h"
#include "testscene.h"
#include"koneta1.h"
#include "koneta2.h"
#include "sceneplayer.h"
#include"banana.h"
#include "ike.h"
#include"finish.h"

Game::Game()
{
}


Game::~Game()
{
}
bool Game::Start()
{	
	m_camera.Start();

	//�J������ݒ�B
	MainCamera().SetTarget({ 0.0f, 10.0f, 50.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(200.0f);
	MainCamera().SetPosition({ 0.0f, 10.0f, -50.0f });
	MainCamera().Update();

	/*m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });*/
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/stage1.cmo");
	m_skinModelRender->SetScale({ 0.15f, 0.15f, 0.15f });
   
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/skydome.cmo");
	m_skinModelRender->SetScale({0.1f, 0.1f, 0.1f });

	
		//m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
		//m_skinModelRender->Init(L"modelData/news.cmo");
		//m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });
		////news��PostRender�ŕ`�悷��B
		//m_skinModelRender->SetModelDrawOnRenderFunction(false);
		
	
	

	//�X�v���C�g���������B
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	/*m_spriteRender->Init(L"sprite/sky.dds", 1280, 720);*/


	time += GameTime().GetFrameDeltaTime();
	/*NewGO<finish>(0, "finish");*/
	NewGO<banana>(0, "banana");
	NewGO<ike>(0, "ike");
	m_fade = FindGO<Fade>("Fade");
	m_fade->StartFadeIn();
	m_state = enState_FadeIn;

	EventData eventDataTbl[] = {
		{5.0f, enEventNo_Koneta1 },
		{30.0f, enEventNo_Koneta2 },
	    {60.0f, enEventNo_news },
		/*{3.0f, enEventNo_Koneta1 },*/
	};
	m_sceneplayer.Init(eventDataTbl, sizeof(eventDataTbl) / sizeof(eventDataTbl[0]));
	return true;
}
void Game::Update()
{
	m_sceneplayer.Update();
	m_camera.Update();

	m_position = { 0.0f,290.0f,200.0f };

	m_spriteRender->SetPosition(m_position);

	switch (m_state) {
	case enState_FadeIn:
		GraphicsEngine().GetTonemap().Reset();
		if (!m_fade->IsFade()) {
			m_state = enState_InGame;
		}
		break;
	case enState_InGame: {
		m_sceneplayer.Update();
		m_waitTimer += GameTime().GetFrameDeltaTime();
		if (m_waitTimer < 0.1f) {
			//�Q�[�����J�n����0.1�b�o�߂���܂Ńg�[���}�b�v�̖��Ï����͂��Ȃ��B
			GraphicsEngine().GetTonemap().Reset();
		}

		break;
	}
	
	}
	

	/*if (Pad(0).IsPress(enButtonA)) {
		DeleteGO(this);
	 }*/

	 //�X�y�[�X�L�[�Ńe�X�g�V�[����

	 //if (Pad(0).IsPress(enButtonSelect)) {
	 //	NewGO<testscene>(0, "testscene");
	 //}
	 //if (Pad(0).IsPress(enButtonA)) {
	 //	//A�{�^���������ꂽr���B
	 //	m_skinModelRender->PlayAnimation(enAnimClip_slip);
	 //}
	 //if (Pad(0).IsPress(enButtonB)) {
	 //	//B�{�^���������ꂽ��B
	 //	m_skinModelRender->PlayAnimation(enAnimClip_wakeup);
	 //}
}
void Game::Render(CRenderContext& rc)
{
	m_camera.Render(rc);
	
}

