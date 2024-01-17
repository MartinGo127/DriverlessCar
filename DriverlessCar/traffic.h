#pragma once
#include "planning_base.h"	// car.h包含,可以不写
#include "car.h"

/*********************障碍物***********************/
class Cone
{
public:
	Cone() = default;
	Cone(const double& pos_x, const double& pos_y, const double& R = 20.0);
	void showCone();

public:
	unique_ptr<Point>p_center;
	double r = 20.0;	// 半径
};