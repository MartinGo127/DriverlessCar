#include "scenario_base.h"

void SceneBase::showScene()	// 绘制，虚函数，默认状态只包含主车和道路，画obs子类重写
{
	BeginBatchDraw();
	cleardevice();

	road0->showRoad();	// 父类roadbase指针，调用子类roadnormal对象函数
	car0->showCar(BLACK);
	
	if (SHOWCIRCLE && car0->p_center)
	{
		car0->showCircle();
	}
	EndBatchDraw();
	delay(DELAYTIME);
}