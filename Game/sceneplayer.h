#pragma once

enum EnEventNo {
	enEventNo_Koneta1,
	enEventNo_Koneta2,
	enEventNo_news,
};
struct EventData {
	float invokeTime;		//�C�x���g�������ԁB
	EnEventNo eventNo;		//�C�x���g�ԍ��B
};
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
};



//sceneplayer m_sceneplayer;




