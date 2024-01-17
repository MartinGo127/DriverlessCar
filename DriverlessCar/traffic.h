#pragma once
#include "planning_base.h"	// car.h����,���Բ�д
#include "car.h"

/*********************�ϰ���***********************/
class Cone
{
public:
	Cone() = default;
	Cone(const double& pos_x, const double& pos_y, const double& R = 20.0);
	void showCone();

public:
	unique_ptr<Point>p_center;
	double r = 20.0;	// �뾶
};