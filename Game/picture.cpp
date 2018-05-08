#include "stdafx.h"
#include "picture.h"
#include "Game.h"

picture::picture()
{
}


picture::~picture()
{
}


bool picture::Start()
{
	
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
		m_skinModelRender->Init(L"modelData/picture.cmo");
		m_skinModelRender->SetScale({ 0.15f, 0.15f, 0.15f });
		m_skinModelRender->SetPosition(m_position);
	return true;
}

void picture::Update()
{
	//�e�X�g�V�[���̃C���X�^���X����������B���̃R�[�h��Game�ł͎g���Ȃ��̂ŏC������K�v������B
	Game* scene = FindGO<Game>("Game");
	/*Game* scene = FindGO<Game>("Game");*/
	//�f�B�t���[�Y�e�N�X�`���������ւ���B
	m_skinModelRender->SetOverrideDiffuseTexture(scene->m_camera.renderTargets[m_renderTargetNo].GetRenderTargetSRV().GetBody());
}

void picture::Render(CRenderContext& rc)
{

}