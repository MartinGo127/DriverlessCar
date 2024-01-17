#pragma once
#include "planning_base.h"

/**********************״̬��*********************/
enum Shift
{
	m_D,
	m_N,
	m_R,
	m_P,
};

enum TurnDirection
{
	TurnLeft,
	TurnRight,
};

/**********************������*********************/
class CarBase
{
public:
	virtual ~CarBase() = default;
	void initCar(const double& pos_x, const double& pos_y, const double& heading, const double& width, const double& length);	// ��ʼ������
	void updatePmidF();		// ����ǰ�е�xyֵ
	void updatePmidR();		// ���º��е�xyֵ
	void updatePmid();		// ���¼����е�xyֵ
	void showCar(const COLORREF& color);	// ���Ƴ���
	void showCircle();	// ���ƹ켣��
	void coutInfo();	// ��ӡ��Ϣ

	void moveStraightStep();	// ��֡ǰ��������4/7���������ֵ����
	void turnCarStep();			// ��֡ת��

public:
	// ����
	double car_length = 160.0;
	double car_width = 80.0;

	// ������̬��
	unique_ptr<Point> plf;	// ��ǰ��
	unique_ptr<Point> prf;	// ��ǰ��
	unique_ptr<Point> plr;	// ����
	unique_ptr<Point> prr;	// �Һ��
	unique_ptr<Point> p_center;	 // ת�����ĵ�

	unique_ptr<Point> pmidf;	// ǰ���е�
	unique_ptr<Point> pmidr;	// �����е�
	unique_ptr<Point> pmid;		// �����е�

	// ת��뾶
	// �Ż��㣺д�������ļ�(����)�����ݲ�ͬ�������ò�ͬת��뾶
	double Rmin = 100.0;	// ��Сת��뾶����Ϊ�涨
	double Rof = 0.0;	// ��ǰ�뾶
	double Ror = 0.0;	// ���뾶
	double Rif = 0.0;	// ��ǰ�뾶
	double Rir = 0.0;	// �ں�뾶

	double R0;	// ��б������ת�뾶��Ư�ƹ���ʹ��
	double theta0;	// atan(car_leight/car_width)

	// �ٶ�
	// x,y���ٶ���speedͨ������Ǽ���õ�
	double speed = 0.0;  // ���ٶȣ�����ʵ���ٶȣ�����ǰ������������
	double speed_x = 0.0;	// x������ٶȣ�����������������
	double speed_y = 0.0;	// y������ٶȣ��������ϣ���������

	// ���ٶ�
	double acc = 0.0;  // �ϼ��ٶȣ�����ʵ�ʼ��ٶȣ��������٣���������
	double acc_x = 0.0;	// x����ּ��ٶȣ�����������������
	double acc_y = 0.0;	// y����ּ��ٶȣ��������ϣ���������

	// ��̬�Ƕ�
	double delta_theta = 0.0;		// ���ٶȣ�����˳ʱ�룬������ʱ��
	double delta_theta_rot = 0.0;	// ��ת���ٶȣ�����˳ʱ�룬������ʱ��
	double heading_theta = 0.0;		// ����ǣ�Ϊ0����ֱ���ϣ�������ƫ����������ƫ��

};

/**********************һ�㳵*********************/
class CarNormal : public CarBase
{
public:
	CarNormal(const double& pos_x, const double& pos_y, const double& heading, const double& width, const double& length);
};