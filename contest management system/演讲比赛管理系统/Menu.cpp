#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <fstream>
using namespace std;
#include "Manager.h"
#include "Speaker.h"
#include<algorithm>
#include<numeric>
#include<functional>

void Manager::showMenu(){
	cout<<"------------------------------"<<endl;
	cout<<"   ��ӭʹ���ݽ���������ϵͳ   "<<endl;
	cout<<"                              "<<endl;
	cout<<"        1.��ʼ�ݽ�����        "<<endl;
	cout<<"                              "<<endl;
	cout<<"        2.�鿴���������Ϣ    "<<endl;
	cout<<"                              "<<endl;
	cout<<"        3.��ձ�����Ϣ        "<<endl;
	cout<<"                              "<<endl;
	cout<<"        0.�˳�����ϵͳ        "<<endl;
	cout<<"------------------------------"<<endl;

}