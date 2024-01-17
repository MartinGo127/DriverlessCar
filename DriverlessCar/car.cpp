#include "car.h"

/*******************������*********************/
void CarBase::initCar(const double& pos_x, const double& pos_y, const double& heading, const double& width, const double& length)
{
	// ������С����
	car_width = width;
	car_length = length;
	heading_theta = heading;
	R0 = hypot(car_width / 2.0, car_length / 2.0);
	theta0 = atan(car_length / car_width);

	// ����λ�ò������ڷų���
	pmid = make_unique<Point>(pos_x, pos_y);	// �ڷ��е�,��Ϊpmid��unique_ptr���ͣ����Ա���make_unique
	// ���ݼ����е�pmid�����Ķ���x,y,theta,r
	plf = make_unique<Point>(pmid->x - car_width / 2.0, pmid->y - car_length / 2.0, PI - theta0, R0);
	prf = make_unique<Point>(pmid->x + car_width / 2.0, pmid->y - car_length / 2.0, theta0, R0);
	plr = make_unique<Point>(pmid->x - car_width / 2.0, pmid->y + car_length / 2.0, PI + theta0, R0);
	prr = make_unique<Point>(pmid->x + car_width / 2.0, pmid->y + car_length / 2.0, -theta0, R0);

	// ��ʼ���ڷź���ǣ���ת������pmid��ָ�����ͣ�������Ҫ������*pmid
	plf->turnPoint(*pmid, heading_theta);
	plr->turnPoint(*pmid, heading_theta);
	prf->turnPoint(*pmid, heading_theta);
	prr->turnPoint(*pmid, heading_theta);

	// ����ǰ�����е�
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
	else // �״θ��£�������һ��ǰ���е㣬initCar����ʼ��ǰ����
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

// ���Ƴ���
void CarBase::showCar(const COLORREF& color)
{
	setlinestyle(PS_SOLID, 4);
	setlinecolor(color);
	line(plf->x, plf->y, prf->x, prf->x);
	line(prf->x, prf->y, prr->x, prr->y);
	line(prr->x, prr->y, plr->x, plr->y);
	line(plr->x, plr->y, plf->x, plf->y);
}

// ���ƹ켣��
void CarBase::showCircle()
{
	setlinestyle(PS_DOT, 2);
	setlinecolor(MAGENTA);
	circle(p_center->x, p_center->y, Rof);
	circle(p_center->x, p_center->y, Ror);
	circle(p_center->x, p_center->y, Rif);
	circle(p_center->x, p_center->y, Rir);
}

void CarBase::moveStraightStep()	// ��ֱ֡��
{
	plf->movePoint(speed_x, speed_y);
	prf->movePoint(speed_x, speed_y);
	plr->movePoint(speed_x, speed_y);
	prr->movePoint(speed_x, speed_y);
	pmidf->movePoint(speed_x, speed_y);
	pmidr->movePoint(speed_x, speed_y);
	pmid->movePoint(speed_x, speed_y);
}

void CarBase::turnCarStep()		// ��֡ת��,����5���㣬ʣ���������ĵ����update��������
{
	pmidr->turnPoint(*p_center, delta_theta);
	plf->turnPoint(*p_center, delta_theta);
	prf->turnPoint(*p_center, delta_theta);
	plr->turnPoint(*p_center, delta_theta);
	prr->turnPoint(*p_center, delta_theta);
	heading_theta += delta_theta;	// ���º����
}

/*******************һ�㳵*********************/
CarNormal::CarNormal(const double& pos_x, const double& pos_y, const double& heading, const double& width, const double& length)
{
	// ����ע�⣬û��ʹ�ó�ʼ���б����߸�ֵ��ʽ��ʼ��CarNormal�����Ƿ�װ��initCar()����
	// ��Ϊ���������ط�����Ҳ����Ҫ��ʼ��һ�㳵������Ҫ����initCar()����Ȼ��û����ʼ��������
	initCar(pos_x, pos_y, heading, width, length);
}