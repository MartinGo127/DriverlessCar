#pragma once
#include "car.h"
#include "road.h"

// ���ڳ����Ƚ϶࣬���಻д��ÿһ�����������ˣ�����дһ���ļ�ȥ�̳�
// ÿ�����峡��������Ҳ��С
class SceneBase
{
public:
	virtual ~SceneBase();
	// �麯�������Ƴ����������������д���͵������︸��ĺ���
	// ����ͨ�ó�������ֱ���ø����麯�������������⴦����������д�����麯���ٵ���
	virtual void showScene();	
	virtual void obsMoveStep();		// �麯����obs��֡�ƶ��������ϰ���ļ���Ϊ��ͨ��������дʵ������������Ϊ
	virtual void planning_base() = 0;	// ���麯������������

	/*********************ֱ��*******************/
	void uniformStraight(const double& total_s);	// ֱ�У���ʻָ������
	void uniformAccBySpeed(const double& target_speed_y);	// ��֪���ٶȣ���ʻ��ָ���ٶȣ��ȼӣ�������ֱ���˶�
	void uniformAccByDis(const double& dis, const double& target_speed_y);	// ��ʻ��ָ������ʱ���ﵽָ���ٶ�
	void uniformAccByTime(const double& target_time, const double& target_speed);	// ֱ�У���ʻ��ָ��ʱ��ʱ���ﵽָ���ٶ�


public:
	unique_ptr<RoadBase> road0;	// ��·����ָ�룬ָ���������ʵ�ֶ�̬
	unique_ptr<CarBase> car0;	// ��������ָ��
	double speedlimit = -6.0;

};
