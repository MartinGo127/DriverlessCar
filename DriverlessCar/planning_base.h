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

/*********************全局变量************************/
constexpr auto SCREEN_WIDTH = 1200.0;	// eazyX窗口宽
constexpr auto SCREEN_HEIGHT = 1200.0;	// eazyX窗口高
constexpr auto PI = 3.1415926535;		// 圆周率
constexpr auto SHOWCIRCLE = false;		// 是否展示(绘制)轨迹线
constexpr auto DELAYTIME = 20;			// 帧间隔, ms
constexpr auto CHANGETIME = 1000;		// 换挡时间, ms

// 点类，动力学运动的总基础
class Point
{
public:
	Point() = default;	// 默认(无参)构造函数存在，告诉编译器
	// 有参构造函数, 点坐标：直角坐标系、极坐标系
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
	double r = 5;	// 绘制半径
};

/***********************全局函数**********************/
void delay(const int& time);