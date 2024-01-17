#pragma once
#include "car.h"
#include "road.h"

// 由于场景比较多，基类不写到每一个场景里面了，单独写一个文件去继承
// 每个具体场景代码量也不小
class SceneBase
{
public:
	virtual ~SceneBase();
	// 虚函数，绘制场景，子类如果不重写，就调用这里父类的函数
	// 对于通用场景可以直接用父类虚函数，对于需特殊处理场景子类重写父类虚函数再调用
	virtual void showScene();	
	virtual void obsMoveStep();		// 虚函数，obs单帧移动，描述障碍物的简单行为。通过子类重写实现描述复杂行为
	virtual void planning_base() = 0;	// 纯虚函数，整个过程

	/*********************直行*******************/
	void uniformStraight(const double& total_s);	// 直行，行驶指定距离
	void uniformAccBySpeed(const double& target_speed_y);	// 已知加速度，行驶到指定速度，匀加（减）速直线运动
	void uniformAccByDis(const double& dis, const double& target_speed_y);	// 行驶到指定距离时，达到指定速度
	void uniformAccByTime(const double& target_time, const double& target_speed);	// 直行，行驶到指定时间时，达到指定速度


public:
	unique_ptr<RoadBase> road0;	// 道路父类指针，指向子类对象，实现多态
	unique_ptr<CarBase> car0;	// 车辆父类指针
	double speedlimit = -6.0;

};
