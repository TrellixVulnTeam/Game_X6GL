#include "stdafx.h"
#include "Title.h"


Title::Title()
{
}


Title::~Title()
{
}

bool Title::Start()
{
	//�J������ݒ�B
	MainCamera().SetTarget({ 180.0f,50.0f,-20.0f });		//�J�����̌���
	MainCamera().SetPosition({ 175.0f,70.0f,-400.0f });	//�J�����̈ʒu
	MainCamera().Update();

	//�A�j���[�V�����N���b�v�̃��[�h�B
	m_animClip[enAnimClip_jj].Load(L"animdata/title.tka");
	//�X�L�����f�������_���[���쐬�B
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Title.cmo", m_animClip, enAnimClip_num);
	m_skinModelRender->SetScale({ 5.0f,5.0f,5.0f });
	//�Ȃ񂩂悤�킩��񂯂ǃ��[�v
	m_animClip[enAnimClip_jj].SetLoopFlag(true);

	return true;
}

void Title::Update()
{

}
