#include "stdafx.h"
#include "sceneplayer.h"
#include"koneta1.h"
#include"koneta2.h"
#include "Game.h"



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
	
	/*Camera* m_camera = FindGO<Camera>("Camera");*/

	m_timer += GameTime().GetFrameDeltaTime();

	for (int i = 0; i < m_invokeEventFlags.size(); i++) {
		
		if (/*�C�x���g���N�����Ă��Ȃ����*/m_invokeEventFlags[i] == 0) {
			if (m_timer > m_eventDatas[i].invokeTime) {
				//�C�x���g���N������B
				if (m_eventDatas[i].eventNo == enEventNo_Koneta1) {
					NewGO<koneta1>(0, "koneta1");
				}

				if (m_eventDatas[i].eventNo == enEventNo_Koneta2) {
					NewGO<koneta2>(0, "koneta2");
				}

				if (m_eventDatas[i].eventNo == enEventNo_news) {
					m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
					m_skinModelRender->Init(L"modelData/news.cmo");
					m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });
					m_position = { 0.0f,0.0f,0.0f };
                    m_skinModelRender->SetPosition(m_position);
					//m_skinModelRender->SetModelDrawOnRenderFunction(false);

					

					//�e�X�g�V�[���̃C���X�^���X����������B���̃R�[�h��Game�ł͎g���Ȃ��̂ŏC������K�v������B
					Game* scene = FindGO<Game>("Game");
					//�f�B�t���[�Y�e�N�X�`���������ւ���B
					m_skinModelRender->FindMaterial([&](CModelEffect* material) {
						
						if (material->EqualMaterialName(L"01 - Default") == true) {
							//��l�^�̃C�x���g��T���B

							//��l�^�̃C�x���g������������A�J�����̃^�C���X�^���v�̔z���S�����ׂ�
							for (int j = 0; j < 2; j++) {
								m_camera.timestanp[j];


								/*	if (m_eventDatas[1].invokeTime <= m_camera->timestanp[j] && hantei <= 0)
									{
										hantei = m_camera->timestanp[j] - m_eventDatas[1].invokeTime;
									}
	*/
								hantei = m_camera.timestanp[i] - m_eventDatas[0].invokeTime;

							}

							//���̍������l�ȉ��Ȃ�A��l�^�ʐ^�������ւ���B
							if (hantei < 5) {
								material->SetDiffuseTexture(scene->m_camera.renderTargets[0].GetRenderTargetSRV().GetBody());
								m_spriteRender = NewGO<prefab::CSpriteRender>(0);
								m_spriteRender->Init(L"sprite/clear.dds", 1280, 720);
							}
						}
						if (material->EqualMaterialName(L"02 - Default") == true) {
							material->SetDiffuseTexture(scene->m_camera.renderTargets[1].GetRenderTargetSRV().GetBody());
						}
						if (material->EqualMaterialName(L"03 - Default") == true) {
							material->SetDiffuseTexture(scene->m_camera.renderTargets[2].GetRenderTargetSRV().GetBody());
						}

						
					});
		
				}
				
				//�C�x���g�̋N���t���O��1�ɂ���B
				m_invokeEventFlags[i] = 1;
			}
		}
	}
}

