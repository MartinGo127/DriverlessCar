#include "scenario_base.h"

void SceneBase::showScene()	// ���ƣ��麯����Ĭ��״ֻ̬���������͵�·����obs������д
{
	BeginBatchDraw();
	cleardevice();

	road0->showRoad();	// ����roadbaseָ�룬��������roadnormal������
	car0->showCar(BLACK);
	
	if (SHOWCIRCLE && car0->p_center)
	{
		car0->showCircle();
	}
	EndBatchDraw();
	delay(DELAYTIME);
}