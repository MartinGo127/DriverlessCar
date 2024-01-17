#pragma once
#include "planning_base.h"

/**********************状态机*********************/
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

/**********************车基类*********************/
class CarBase
{
public:
	virtual ~CarBase() = default;
	void initCar(const double& pos_x, const double& pos_y, const double& heading, const double& width, const double& length);	// 初始化车辆
	void updatePmidF();		// 更新前中点xy值
	void updatePmidR();		// 更新后中点xy值
	void updatePmid();		// 更新几何中点xy值
	void showCar(const COLORREF& color);	// 绘制车辆
	void showCircle();	// 绘制轨迹线
	void coutInfo();	// 打印信息

	void moveStraightStep();	// 单帧前进，车辆4/7个点的坐标值更新
	void turnCarStep();			// 单帧转向

public:
	// 车长
	double car_length = 160.0;
	double car_width = 80.0;

	// 车辆姿态点
	unique_ptr<Point> plf;	// 左前点
	unique_ptr<Point> prf;	// 右前点
	unique_ptr<Point> plr;	// 左后点
	unique_ptr<Point> prr;	// 右后点
	unique_ptr<Point> p_center;	 // 转向中心点

	unique_ptr<Point> pmidf;	// 前轴中点
	unique_ptr<Point> pmidr;	// 后轴中点
	unique_ptr<Point> pmid;		// 几何中点

	// 转弯半径
	// 优化点：写入配置文件(车参)，根据不同车辆配置不同转弯半径
	double Rmin = 100.0;	// 最小转弯半径，人为规定
	double Rof = 0.0;	// 外前半径
	double Ror = 0.0;	// 外后半径
	double Rif = 0.0;	// 内前半径
	double Rir = 0.0;	// 内后半径

	double R0;	// 半斜长，自转半径，漂移工况使用
	double theta0;	// atan(car_leight/car_width)

	// 速度
	// x,y分速度由speed通过航向角计算得到
	double speed = 0.0;  // 合速度，车辆实际速度，负：前进，正：后退
	double speed_x = 0.0;	// x方向分速度，负：向左，正：向右
	double speed_y = 0.0;	// y方向分速度，负：向上，正：向下

	// 加速度
	double acc = 0.0;  // 合加速度，车辆实际加速度，负：加速，正：减速
	double acc_x = 0.0;	// x方向分加速度，负：向左，正：向右
	double acc_y = 0.0;	// y方向分加速度，负：向上，正：向下

	// 姿态角度
	double delta_theta = 0.0;		// 角速度，负：顺时针，正：逆时针
	double delta_theta_rot = 0.0;	// 自转角速度，负：顺时针，正：逆时针
	double heading_theta = 0.0;		// 航向角，为0：竖直向上，负：左偏航，正：右偏航

};

/**********************一般车*********************/
class CarNormal : public CarBase
{
public:
	CarNormal(const double& pos_x, const double& pos_y, const double& heading, const double& width, const double& length);
};