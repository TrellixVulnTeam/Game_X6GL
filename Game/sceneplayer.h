#pragma once
#include "Camera.h"

enum EnEventNo {
	enEventNo_Koneta1,
	enEventNo_Koneta2,
	enEventNo_Nessie,
	enEventNo_news,
};
enum EnScoopLevel {
	enBigScoop,		//��l�^,
	enMiddleScoop,	//���l�^,
	enSmallScoop,	//���l�^,
};
struct EventData {
	float invokeTime;		//�C�x���g�������ԁB
	EnScoopLevel netaLevel;	//�X�N�[�v�̃��x���B
	EnEventNo eventNo;		//�C�x���g�ԍ��B
};
class Camera;
class sceneplayer : public IGameObject
{
public:
	sceneplayer();
	~sceneplayer();
	void Update();
	void Init(EventData* eventDataTbl, int numEventData);

private:
	std::vector<EventData> m_eventDatas;	//!<�C�x���g�f�[�^�B
	std::vector<int> m_invokeEventFlags;	//!<�C�x���g�N���t���O�B
	float m_timer = 0.0f;					//!<�^�C�}�[�B
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	prefab::CSpriteRender* m_spriteRender;
	CVector3 m_position = CVector3::Zero;
	int m_renderTargetNo = 0;

	Camera m_camera;
	float hantei0 = 0;
	float hantei1 = 0;
	float hantei2 = 0;
	float timestanp0 = 0;
	float timestanp1 = 0;
	float timestanp2 = 0;

	float Smallhantei0 = 0;
	float Smallhantei1 = 0;
	float Smallhantei2 = 0;
	float Smalltimestanp0 = 0;
	float Smalltimestanp1 = 0;
	float Smalltimestanp2 = 0;

	float midlehantei0 = 0;
	float midlehantei1 = 0;
	float midlehantei2 = 0;
	float midletimestanp0 = 0;
	float midletimestanp1 = 0;
	float midletimestanp2 = 0;

};





//sceneplayer m_sceneplayer;




