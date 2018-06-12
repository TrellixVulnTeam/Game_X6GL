#include "stdafx.h"
#include "GameCamera.h"


GameCamera::GameCamera()
{
}

GameCamera::~GameCamera()
{
}
bool GameCamera::Start()
{
	//�J�����̃j�A�N���b�v�ƃt�@�[�N���b�v��ݒ肷��B
	MainCamera().SetNear(1.0f);
	MainCamera().SetFar(10000.0f);

	MainCamera().SetPosition({ 0,5,0});
	MainCamera().SetTarget({ 0,5,-10 });

	return true;
}
void GameCamera::Update()
{
	MainCamera().Update();

	CVector3 Pos = MainCamera().GetPosition();
	CVector3 Target = MainCamera().GetTarget();
	//���_���璍���_�Ɍ������ĐL�т�x�N�g��V�����߂�B
	CVector3 V = Target - Pos;

	//�p�b�h�̓��͂��g���ăJ�������񂷁B
	float x = Pad(0).GetRStickXF();
	//Y������̉�]�N�H�[�^�j�I�������߂�B
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 6.0f * x);
	//V = V * qRot
	qRot.Multiply(V);

	//V��X������ɉ�]

	//�p�b�h�̓��͂��g���ăJ�������񂷁B
	float y = Pad(0).GetRStickYF();
	//X������̉�]�B
	CVector3 axisX;
	axisX.Cross(CVector3::Up, V);
	axisX.Normalize();
	qRot.SetRotationDeg(axisX, -6.0f * y);

	CVector3 vBackup = V;

	qRot.Multiply(V);

	CVector3 vNorm = V;
	vNorm.Normalize();

	if (vNorm.y > 0.2f) {
		V = vBackup;
	}
	else if (vNorm.y < -0.2f) {
		V = vBackup;
	}
	//�V�������_�����߂�B
	Target = Pos + V;

	MainCamera().SetTarget(Target);
}