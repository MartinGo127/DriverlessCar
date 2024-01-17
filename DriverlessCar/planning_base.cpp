#include "planning_base.h"

/************************点**********************/
// 有参构建函数，初始化列表
Point::Point(const double& p_x, const double& p_y, const double& p_theta, const double& p_R) : x(p_x), y(p_y), theta_P(p_theta), R_P(p_R) {}

// 绘制点，easyX库函数
void Point::showPoint()
{
	setfillcolor(BLACK);
	solidcircle(x, y, r);
}

// 移动点，均定义为原子操作
void Point::movePoint(const double& speed_x, const double& speed_y)
{
	x += speed_x;
	y += speed_y;
}

// 旋转点，通过极坐标->直角坐标实现
void Point::turnPoint(const Point& center, const double& turn_speed)
{
	theta_P += turn_speed;
	x = R_P * cos(theta_P) + center.x;
	y = -R_P * sin(theta_P) + center.y;
}

// 求到p点距离
double Point::disPoint(const Point& p)
{
	return hypot(x - p.x, y - p.y);
}

// 刷新延迟(间隔)函数
void delay(const int& time)
{
	clock_t cur_time = clock();
	while (cur_time - clock() < time)
	{

	}
}

