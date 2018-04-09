#include "stdafx.h"
#include "Camera.h"


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
	if (Pad(0).IsTrigger(enButtonRB1)) {
		if (shattercount < 3) {
			timestanp[shattercount] = time;
			shattercount++;
			flag = 1;
		}
		else {
			MessageBox(NULL, "�����V���b�^�[�͉����܂���I", "�x��", MB_OK);
		}
		//�V���b�^�������ꂽ�t���O��true�ɂ���B
	}
	time += GameTime().GetFrameDeltaTime();
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
		}
	}

	//if (/*�V���b�^�[��������Ă����t���O�������Ă�����*/) {
	//	//�V���b�^�[�������ꂽ�t���[�������A
	//	//renderTargets�Ƀe�N�X�`�����R�s�[����B
	//}
	/*�V���b�^�[��������Ă����t���O������*/
}