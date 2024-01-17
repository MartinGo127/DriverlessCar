#pragma once
#include "traffic.h"

/***********************道路基类*************************/
class RoadBase
{
public:
	virtual ~RoadBase() = default;
	virtual void showRoad() = 0;	// 绘制道路，纯虚函数，为了后面多态实现绘制具体的道路

public:
	double Rwidth = 200.0;		// 车道宽
	double up_boundary = 0.0;	// 上边界
	double down_boundary = 0.0;	// 下边界
	double left_boundary = 0.0;	// 左边界
	double right_boundary = 0.0;// 右边界
};

/***********************一般道路**************************/
class RoadNormal : public RoadBase
{
public:
	RoadNormal(const double& r_width = 200.0);
	void showRoad() override;	// 子类必须重写父类的纯虚函数
};