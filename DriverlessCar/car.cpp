#include "car.h"

/*******************车基类*********************/
void CarBase::initCar(const double& pos_x, const double& pos_y, const double& heading, const double& width, const double& length)
{
	// 车辆大小参数
	car_width = width;
	car_length = length;
	heading_theta = heading;
	R0 = hypot(car_width / 2.0, car_length / 2.0);
	theta0 = atan(car_length / car_width);

	// 车辆位置参数，摆放车辆
	pmid = make_unique<Point>(pos_x, pos_y);	// 摆放中点,因为pmid是unique_ptr类型，所以必须make_unique
	// 根据几何中点pmid计算四顶点x,y,theta,r
	plf = make_unique<Point>(pmid->x - car_width / 2.0, pmid->y - car_length / 2.0, PI - theta0, R0);
	prf = make_unique<Point>(pmid->x + car_width / 2.0, pmid->y - car_length / 2.0, theta0, R0);
	plr = make_unique<Point>(pmid->x - car_width / 2.0, pmid->y + car_length / 2.0, PI + theta0, R0);
	prr = make_unique<Point>(pmid->x + car_width / 2.0, pmid->y + car_length / 2.0, -theta0, R0);

	// 初始化摆放航向角，旋转，由于pmid是指针类型，所以需要解引用*pmid
	plf->turnPoint(*pmid, heading_theta);
	plr->turnPoint(*pmid, heading_theta);
	prf->turnPoint(*pmid, heading_theta);
	prr->turnPoint(*pmid, heading_theta);

	// 更新前后轴中点
	updatePmidF();
	updatePmidR();
}

void CarBase::updatePmidF()
{
	double x = (plf->x + prf->x) / 2.0;
	double y = (plf->y + prf->y) / 2.0;
	if (pmidf)
	{
		pmidf->x = x;
		pmidf->y = y;
	}
	else // 首次更新，创建第一个前轴中点，initCar不初始化前后轴
	{
		pmidf = make_unique<Point>(x, y);
	}
}

void CarBase::updatePmidR()
{
	double x = (plr->x + prr->x) / 2.0;
	double y = (plr->y + prr->y) / 2.0;
	if (pmidr)
	{
		pmidr->x = x;
		pmidr->y = y;
	}
	else 
	{
		pmidr = make_unique<Point>(x, y);
	}
}

void CarBase::updatePmid()
{
	double x = (plf->x + prr->x) / 2.0;
	double y = (plf->y + prr->y) / 2.0;
	if (pmid)
	{
		pmid->x = x;
		pmid->y = y;
	}
	else 
	{
		pmid = make_unique<Point>(x, y);
	}
}

// 绘制车辆
void CarBase::showCar(const COLORREF& color)
{
	setlinestyle(PS_SOLID, 4);
	setlinecolor(color);
	line(plf->x, plf->y, prf->x, prf->x);
	line(prf->x, prf->y, prr->x, prr->y);
	line(prr->x, prr->y, plr->x, plr->y);
	line(plr->x, plr->y, plf->x, plf->y);
}

// 绘制轨迹线
void CarBase::showCircle()
{
	setlinestyle(PS_DOT, 2);
	setlinecolor(MAGENTA);
	circle(p_center->x, p_center->y, Rof);
	circle(p_center->x, p_center->y, Ror);
	circle(p_center->x, p_center->y, Rif);
	circle(p_center->x, p_center->y, Rir);
}

void CarBase::moveStraightStep()	// 单帧直行
{
	plf->movePoint(speed_x, speed_y);
	prf->movePoint(speed_x, speed_y);
	plr->movePoint(speed_x, speed_y);
	prr->movePoint(speed_x, speed_y);
	pmidf->movePoint(speed_x, speed_y);
	pmidr->movePoint(speed_x, speed_y);
	pmid->movePoint(speed_x, speed_y);
}

void CarBase::turnCarStep()		// 单帧转向,更新5个点，剩余两个轴心点调用update函数即可
{
	pmidr->turnPoint(*p_center, delta_theta);
	plf->turnPoint(*p_center, delta_theta);
	prf->turnPoint(*p_center, delta_theta);
	plr->turnPoint(*p_center, delta_theta);
	prr->turnPoint(*p_center, delta_theta);
	heading_theta += delta_theta;	// 更新航向角
}

/*******************一般车*********************/
CarNormal::CarNormal(const double& pos_x, const double& pos_y, const double& heading, const double& width, const double& length)
{
	// 这里注意，没有使用初始化列表，或者赋值方式初始化CarNormal，而是封装了initCar()函数
	// 因为后续其他地方可能也会需要初始化一般车辆，需要调用initCar()，不然就没法初始化车辆了
	initCar(pos_x, pos_y, heading, width, length);
}