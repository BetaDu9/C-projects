#pragma once  //��ֹ�ظ�����ͷ�ļ�
#include <iostream>//�����������������
#include <string>
using namespace std;
#include "worker.h"

class Manager:public worker{
public:
	//��ʼ������
	Manager(int id, string name, int dId);
	//Ա����Ϣ
	void showInfo();
	//��λ��Ϣ
	string departmentInfo();


};