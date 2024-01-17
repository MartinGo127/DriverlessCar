#pragma once
#include "traffic.h"

/***********************��·����*************************/
class RoadBase
{
public:
	virtual ~RoadBase() = default;
	virtual void showRoad() = 0;	// ���Ƶ�·�����麯����Ϊ�˺����̬ʵ�ֻ��ƾ���ĵ�·

public:
	double Rwidth = 200.0;		// ������
	double up_boundary = 0.0;	// �ϱ߽�
	double down_boundary = 0.0;	// �±߽�
	double left_boundary = 0.0;	// ��߽�
	double right_boundary = 0.0;// �ұ߽�
};

/***********************һ���·**************************/
class RoadNormal : public RoadBase
{
public:
	RoadNormal(const double& r_width = 200.0);
	void showRoad() override;	// ���������д����Ĵ��麯��
};