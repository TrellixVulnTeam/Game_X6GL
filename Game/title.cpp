#include "stdafx.h"
#include "title.h"
#include "testscene.h"
#include "Fade.h"


title::title()
{
}


title::~title()
{
	DeleteGO(m_spriteRender);
}


bool title::Start()
{
	//スプライトを初期化。
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/title.dds", 1280, 720);

	m_fade = FindGO<Fade>("Fade");
		
	
	m_font.SetShadowParam(true, 1.0f, { 26.0f / 255.0f, 49 / 255.0f, 103 / 255.0f, 1.0f });
	m_fade->StartFadeIn();
	

	return true;
}

 void title::Update()
{
	 if (m_isWaitFadeout) {
		 if (!m_fade->IsFade()) {
			 NewGO<testscene>(0, "testscene");
			 DeleteGO(this);
		 }
	 }
	 else {
		 if (Pad(0).IsPress(enButtonA)) {
			 m_isWaitFadeout = true;
			 m_fade->StartFadeOut();

		 }
	 }
	 
	 

}