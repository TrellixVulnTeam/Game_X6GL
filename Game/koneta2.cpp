#include "stdafx.h"
#include "koneta2.h"
#include"ike.h"


koneta2::koneta2()
{
}


koneta2::~koneta2()
{
	DeleteGO(m_skinModelRender);
}

bool koneta2::Start()
{
	m_animClip[enAnimClip_idle].Load(L"animData/idle.tka");
	m_animClip[enAnimClip_slip].Load(L"animData/slip.tka");
	m_animClip[enAnimClip_wakeup].Load(L"animData/wakeup.tka");
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/kokeruhito.cmo", m_animClip, enAnimClip_num);
	m_skinModelRender->SetScale({ 0.03f, 0.03f, 0.03f });

	m_pos = { -30.0f,0.0f,-30.0f };

	return true;
}

void koneta2::Update()
{
	m_pos.x = +20.0f;
	m_pos.z -= 0.1f;

	//座標を設定。
	m_skinModelRender->SetPosition(m_pos);

	ike*gl = FindGO<ike>("ike");
	CVector3 diff = CVector3::Zero;
	diff.z = m_pos.z - gl->m_position.z;
	if (diff.Length() <= 1.0f)
	{
		if (flag == 1) {
			return;
		}
		m_skinModelRender->PlayAnimation(enAnimClip_slip);

		m_pos.y -= 5.0f;

		flag = 1;
	}

	float time = 0;
	time = GameTime().GetFrameDeltaTime();
	if (time > 60 && Pad(0).IsPress(enButtonSelect)) {
		DeleteGO(this);
	}
}