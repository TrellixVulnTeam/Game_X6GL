#include "stdafx.h"
#include "koneta1.h"
#include"banana.h"


koneta1::koneta1()
{
}


koneta1::~koneta1()
{
}

bool koneta1::Start()
{
	////カメラを設定。
	MainCamera().SetTarget({ 0.0f, 10.0f, 0.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(100.0f);
	MainCamera().SetPosition({ 30.0f, 10.0f, 0.0f });
	MainCamera().Update();

	m_animClip[enAnimClip_idle].Load(L"animData/idle.tka");
	m_animClip[enAnimClip_slip].Load(L"animData/slip.tka");
	m_animClip[enAnimClip_wakeup].Load(L"animData/wakeup.tka");
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/kokeruhito.cmo", m_animClip, enAnimClip_num, CSkinModel::enFbxUpAxisY);
	m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });
	return true;
}

void koneta1::Update()
{
	m_position.z -= 0.1f;

	//座標を設定。
	m_skinModelRender->SetPosition(m_position);


	banana*gl = FindGO<banana>("banana");
	CVector3 diff = CVector3::Zero;
	/*diff.x = m_position.x - gl->m_position.x;
	diff.y = m_position.y - gl->m_position.y;*/
	diff.z = m_position.z - gl->m_position.z;
	if (diff.Length() <= 1.0f)
	{
		if (flag == 1) {
			return;
		}
			m_skinModelRender->PlayAnimation(enAnimClip_wakeup);
			

		flag = 1;
	}
}

void koneta1::Render(CRenderContext& rc)
{

}