/*
* Aruther: zhangyiheng02
* Createdtime: 2024/01/10 01:58:34
* Lastedmodified: 2024/01/10 01:58:34
*/

#pragma once
#include <iostream>
#include <graphics.h>	// eaxyX lib
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>

using namespace std;	// for convenience...

/*********************ȫ�ֱ���************************/
constexpr auto SCREEN_WIDTH = 1200.0;	// eazyX���ڿ�
constexpr auto SCREEN_HEIGHT = 1200.0;	// eazyX���ڸ�
constexpr auto PI = 3.1415926535;		// Բ����
constexpr auto SHOWCIRCLE = false;		// �Ƿ�չʾ(����)�켣��
constexpr auto DELAYTIME = 20;			// ֡���, ms
constexpr auto CHANGETIME = 1000;		// ����ʱ��, ms

// ���࣬����ѧ�˶����ܻ���
class Point
{
public:
	Point() = default;	// Ĭ��(�޲�)���캯�����ڣ����߱�����
	// �вι��캯��, �����꣺ֱ������ϵ��������ϵ
	Point(const double& p_x, const double& p_y, const double& p_theta = 0.0, const double& p_R = 0.0);	

	void showPoint();
	void movePoint(const double& speed_x, const double& speed_y);
	void turnPoint(const Point& center, const double& turn_speed);
	double disPoint(const Point& p);

public:
	double x;
	double y;
	double theta_P = 0.0;
	double R_P = 0.0;
	double r = 5;	// ���ư뾶
};

/***********************ȫ�ֺ���**********************/
void delay(const int& time);