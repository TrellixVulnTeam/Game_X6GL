#include "stdafx.h"
#include "sceneplayer.h"
#include"koneta1.h"
#include"koneta2.h"
#include"Nessie.h"
#include "Game.h"
#include "selectstage.h"

					

sceneplayer::sceneplayer()
{

}


sceneplayer::~sceneplayer()
{

	DeleteGO(m_skinModelRender);
	DeleteGO(m_spriteRender);

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
			if (m_timer > m_eventDatas[i].invokeTime) {
				//�C�x���g���N������B
				if (m_eventDatas[i].eventNo == enEventNo_Koneta1) {
				   NewGO<koneta1>(0, "koneta1");
				}
				if (m_eventDatas[i].eventNo == enEventNo_Koneta2) {
					NewGO<koneta2>(0, "koneta2");
				}
				if (m_eventDatas[i].eventNo == enEventNo_Nessie) {
					NewGO<Nessie>(0, "Nessie");
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
								timestanp0 = scene->m_camera.timestanp[0];
								timestanp1 = scene->m_camera.timestanp[1];
								timestanp2 = scene->m_camera.timestanp[2];

								hantei0 = timestanp0 - m_eventDatas[2].invokeTime;
								hantei1 = timestanp1 - m_eventDatas[2].invokeTime;
								hantei2 = timestanp2 - m_eventDatas[2].invokeTime;
								//���̍������l�ȉ��Ȃ�A��l�^�ʐ^�������ւ���B
								if (hantei0 >= 0 && hantei0 < 5) {
										material->SetDiffuseTexture(scene->m_camera.renderTargets[0].GetRenderTargetSRV().GetBody());
									
									m_spriteRender = NewGO<prefab::CSpriteRender>(0);
									m_spriteRender->Init(L"sprite/clear.dds", 1280, 720);
									TK_LOG("��l�^�̍����ւ�_0");
								}
								else if (hantei1 >= 0 && hantei1 < 5) {
									material->SetDiffuseTexture(scene->m_camera.renderTargets[1].GetRenderTargetSRV().GetBody());
									m_spriteRender = NewGO<prefab::CSpriteRender>(0);
									m_spriteRender->Init(L"sprite/clear.dds", 1280, 720);
									TK_LOG("��l�^�̍����ւ�_1");
								}
								else if (hantei2 >= 0 && hantei2 < 5) {
									material->SetDiffuseTexture(scene->m_camera.renderTargets[2].GetRenderTargetSRV().GetBody());
									m_spriteRender = NewGO<prefab::CSpriteRender>(0);
									m_spriteRender->Init(L"sprite/clear.dds", 1280, 720);
									TK_LOG("��l�^�̍����ւ�_2");
								}
							}

							if (material->EqualMaterialName(L"02 - Default") == true) {
								Smalltimestanp0 = scene->m_camera.timestanp[0];
								Smalltimestanp1 = scene->m_camera.timestanp[1];
								Smalltimestanp2 = scene->m_camera.timestanp[2];
								Smallhantei0 = Smalltimestanp0 - m_eventDatas[1].invokeTime;
								Smallhantei1 = Smalltimestanp1 - m_eventDatas[1].invokeTime;
								Smallhantei2 = Smalltimestanp2 - m_eventDatas[1].invokeTime;

								//���̍������l�ȉ��Ȃ�A��l�^�ʐ^�������ւ���B
								if (Smallhantei0 >= 0 && Smallhantei0 < 5) {
									material->SetDiffuseTexture(scene->m_camera.renderTargets[0].GetRenderTargetSRV().GetBody());
									TK_LOG("���l�^0�̍����ւ�_0");
								}
								else if (Smallhantei1 >= 0 && Smallhantei1 < 5) {
									material->SetDiffuseTexture(scene->m_camera.renderTargets[1].GetRenderTargetSRV().GetBody());
									TK_LOG("���l�^0�̍����ւ�_1");
								}
								else if (Smallhantei2 >= 0 && Smallhantei2 < 5) {
									material->SetDiffuseTexture(scene->m_camera.renderTargets[2].GetRenderTargetSRV().GetBody());
									TK_LOG("���l�^0�̍����ւ�_2");
								}

							}
							if (material->EqualMaterialName(L"03 - Default") == true) {

								midletimestanp0 = scene->m_camera.timestanp[0];
								midletimestanp1 = scene->m_camera.timestanp[1];
								midletimestanp2 = scene->m_camera.timestanp[2];
								midlehantei0 = midletimestanp0 - m_eventDatas[0].invokeTime;
								midlehantei1 = midletimestanp1 - m_eventDatas[0].invokeTime;
								midlehantei2 = midletimestanp2 - m_eventDatas[0].invokeTime;
								//���̍������l�ȉ��Ȃ�A��l�^�ʐ^�������ւ���B
								if (midlehantei0 >= 0 && midlehantei0 < 5) {
									material->SetDiffuseTexture(scene->m_camera.renderTargets[0].GetRenderTargetSRV().GetBody());
									TK_LOG("���l�^1�̍����ւ�_0");
								}
								else if (midlehantei1 >= 0 && midlehantei1 < 5) {
									material->SetDiffuseTexture(scene->m_camera.renderTargets[1].GetRenderTargetSRV().GetBody());
									TK_LOG("���l�^1�̍����ւ�_1");
								}
								else if (midlehantei2 >= 0 && midlehantei2 < 5) {
									material->SetDiffuseTexture(scene->m_camera.renderTargets[2].GetRenderTargetSRV().GetBody());
									TK_LOG("���l�^1�̍����ւ�_2");
								}
							}
						});

					}
					
				//if (m_eventDatas[i].eventNo == enEventNo_change) {
				//	//�C�x���g�̋N���t���O��1�ɂ���B
				//}
				
				m_invokeEventFlags[i] = 1;
	
		/*		if (m_invokeEventFlags[0] != 0) {
					koneta1*kone = FindGO<koneta1>("koneta1");
					DeleteGO(kone);
				}
				if (m_invokeEventFlags[1] != 0) {
					koneta2*kone2 = FindGO<koneta2>("koneta2");
					DeleteGO(kone2);
				}
				if (m_invokeEventFlags[2] != 0) {
					Nessie*ne = FindGO<Nessie>("Nessie");
					DeleteGO(ne);
				}*/

			}
		}
	}
	
}

