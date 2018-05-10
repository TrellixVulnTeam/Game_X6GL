#pragma once
#include "Camera.h"

enum EnEventNo {
	enEventNo_Koneta1,
	enEventNo_Koneta2,
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
	std::vector<EventData> m_eventDatas ;	//!<�C�x���g�f�[�^�B
	std::vector<int> m_invokeEventFlags;	//!<�C�x���g�N���t���O�B
	float m_timer = 0.0f;					//!<�^�C�}�[�B
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	prefab::CSpriteRender* m_spriteRender;
	CVector3 m_position = CVector3::Zero;
	int m_renderTargetNo = 0;
    
	Camera m_camera;
	float hantei = 6;
	
	
};





//sceneplayer m_sceneplayer;




