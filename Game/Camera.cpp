#include "stdafx.h"
#include "Camera.h"
#include "error.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}


bool Camera::Start()
{
	m_sprite.Init(
		GraphicsEngine().GetMainRenderTarget().GetRenderTargetSRV(),
		1280.0f,
		720.0f
	);
	DXGI_SAMPLE_DESC sampleDesc;
	ZeroMemory(&sampleDesc, sizeof(sampleDesc));
	sampleDesc.Count = 1;
	sampleDesc.Quality = 0;
	
	for (int i = 0; i < 3; i++) {
		renderTargets[i].Create(
			1280,
			720,
			1,
			1,
			DXGI_FORMAT_R8G8B8A8_UNORM,
			DXGI_FORMAT_UNKNOWN,
			sampleDesc
		);
	}
	return true;
}

void Camera::Update()
{
	prefab::CSoundSource* ss;

	if (Pad(0).IsTrigger(enButtonRB1)) {
		if (shattercount < 3) {
			timestanp[shattercount] = time;
			shattercount++;
			flag = 1;

			ss = NewGO<prefab::CSoundSource>(0);
			ss->Init("sound/Shutter.mp3");
			ss->Play(false);

			//�G�t�F�N�g���쐬�B
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//�G�t�F�N�g���Đ��B
			effect->Play(L"effect/test.efk");
			CVector3 emitPos = m_pos;
			emitPos.x += 23.0f;
			emitPos.y += 10.0f;
			emitPos.z -= 30.0f;
			effect->SetPosition(emitPos);
		}
		else {
			NewGO<error>(0, "error");
					
			ss = NewGO<prefab::CSoundSource>(0);
			ss->Init("sound/error_1.wav");
			ss->Play(false);
			//MessageBox(NULL, "�����V���b�^�[�͉����܂���I", "�x��", MB_OK);
		}
		//�V���b�^�������ꂽ�t���O��true�ɂ���B
	}
	time += GameTime().GetFrameDeltaTime();
	//�V�[���v���C���[���g���Ƃ��A
	//time�Ɂ@�����̕��͎g���Ȃ�
	// if(time > 1 &&  ��x���Đ�����Ă��Ȃ��Ƃ���flg���K�v)
}

void Camera::Render(CRenderContext& rc)
{


	if (flag == 1) {
		//���ꂪ�B�e�����e�N�X�`���B������CSprite��Init�֐��ɓn���Ă��΂�����͂�
		//renderTargets[0].GetRenderTargetSRV();
		{
			CGraphicsEngine& ge = Engine().GetGraphicsEngine();
			ge.BeginGPUEvent(L"Camera::Render");

			//�����_�����O�^�[�Q�b�g���L�����Ă����B
			CRenderTarget* rtsBackup[8];
			unsigned int numView;
			rc.OMGetRenderTargets(numView, rtsBackup);

			//�����_�����O�^�[�Q�b�g�̐؂�ւ��B
			CRenderTarget* rts[] = {
				&renderTargets[shattercount - 1]
			};
			rc.OMSetRenderTargets(1, rts);

			m_sprite.Draw(rc, MainCamera2D().GetViewMatrix(), MainCamera2D().GetProjectionMatrix());

			//�R�s�[���I������猳�ɖ߂��B
			rc.OMSetRenderTargets(numView, rtsBackup);

			ge.EndGPUEvent();

			flag = 0;
		}
	}

	//if (/*�V���b�^�[��������Ă����t���O�������Ă�����*/) {
	//	//�V���b�^�[�������ꂽ�t���[�������A
	//	//renderTargets�Ƀe�N�X�`�����R�s�[����B
	//}
	/*�V���b�^�[��������Ă����t���O������*/
}