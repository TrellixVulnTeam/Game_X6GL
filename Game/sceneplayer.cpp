#include "stdafx.h"
#include "sceneplayer.h"
#include"koneta1.h"
#include"koneta2.h"




sceneplayer::sceneplayer()
{
}


sceneplayer::~sceneplayer()
{
}

void sceneplayer::Init(EventData* eventDataTbl, int numEventData)
{
	m_eventDatas.resize(numEventData);
	m_invokeEventFlags.resize(numEventData);
	
	for (int i = 0; i < m_invokeEventFlags.size(); i++) {
		//�C�x���g�N���t���O�͂��ׂ�0�ɂ���B
		m_invokeEventFlags[i] = 0;
		m_eventDatas[i] = eventDataTbl[i];
		
	}
}

void sceneplayer::Update() 
{	
	m_timer += GameTime().GetFrameDeltaTime();

	for (int i = 0; i < m_invokeEventFlags.size(); i++) {
		
		if (/*�C�x���g���N�����Ă��Ȃ����*/m_invokeEventFlags[i] == 0) {
			if (m_timer>m_eventDatas[i].invokeTime/*m_timer���C�x���g�̋N�����Ԃ����傫���Ȃ��Ă���*/) {
				//�C�x���g���N������B
				if (m_timer > 5&& m_timer<30) {
					NewGO<koneta1>(0, "koneta1");
				}

				if (m_timer > 30&& m_timer<60) {
					NewGO<koneta2>(0, "koneta2");
				}

				if (m_timer > 60) {
					
					m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
					m_skinModelRender->Init(L"modelData/news.cmo");
					m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });
					//m_skinModelRender->SetModelDrawOnRenderFunction(false);
				}


				
				//�C�x���g�̋N���t���O��1�ɂ���B
				m_invokeEventFlags[i] = 1;
			}
		}
	}
}

