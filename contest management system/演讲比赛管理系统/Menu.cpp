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
	cout<<"   欢迎使用演讲比赛管理系统   "<<endl;
	cout<<"                              "<<endl;
	cout<<"        1.开始演讲比赛        "<<endl;
	cout<<"                              "<<endl;
	cout<<"        2.查看往届比赛信息    "<<endl;
	cout<<"                              "<<endl;
	cout<<"        3.清空比赛信息        "<<endl;
	cout<<"                              "<<endl;
	cout<<"        0.退出管理系统        "<<endl;
	cout<<"------------------------------"<<endl;

}