#pragma once  //��ֹ�ظ�����ͷ�ļ�
#include <iostream>//�����������������
using namespace std;
#include "worker.h"

class Boss:public worker{
public:
	//��ʼ������
	Boss(int id, string name, int dId);
	//Ա����Ϣ
	void showInfo();
	//��λ��Ϣ
	string departmentInfo();


};
