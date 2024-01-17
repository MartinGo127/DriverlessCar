#include "planning_base.h"

/************************��**********************/
// �вι�����������ʼ���б�
Point::Point(const double& p_x, const double& p_y, const double& p_theta, const double& p_R) : x(p_x), y(p_y), theta_P(p_theta), R_P(p_R) {}

// ���Ƶ㣬easyX�⺯��
void Point::showPoint()
{
	setfillcolor(BLACK);
	solidcircle(x, y, r);
}

// �ƶ��㣬������Ϊԭ�Ӳ���
void Point::movePoint(const double& speed_x, const double& speed_y)
{
	x += speed_x;
	y += speed_y;
}

// ��ת�㣬ͨ��������->ֱ������ʵ��
void Point::turnPoint(const Point& center, const double& turn_speed)
{
	theta_P += turn_speed;
	x = R_P * cos(theta_P) + center.x;
	y = -R_P * sin(theta_P) + center.y;
}

// ��p�����
double Point::disPoint(const Point& p)
{
	return hypot(x - p.x, y - p.y);
}

// ˢ���ӳ�(���)����
void delay(const int& time)
{
	clock_t cur_time = clock();
	while (cur_time - clock() < time)
	{

	}
}

