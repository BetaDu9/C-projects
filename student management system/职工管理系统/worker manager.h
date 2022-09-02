#pragma once  //防止重复包含头文件
#include <iostream>//包含输入输出流函数
#include <string>
#include "worker.h"
using namespace std; //使用标准命名空间
#include <fstream> //包含文件流头文件
#define FILENAME "Employee.txt"//定义所要交互的文件名称

class workerManager{
public:
	//构造函数
	workerManager();
	//显示菜单
	void showMenu();

	//成员属性
	int m_PerNum; //职工人数
	worker** m_PerArr; //记录职工数组指针,数组中记录职工指针worker*

	//添加职工
	void addPerson();
	//保存文件
	void save();
	//判断文件是否为空
	bool m_FileisEmpty;
	//获取现有职工人数
	int getNum();
	//初始化员工
	void init();
	//显示员工
	void showPerson();
	//删除员工
	void deletePer();
	//修改职工
	void modPerson();
	//查找职工
	void search();
	//清空职工列表
	void clear();
	//析构函数
	~workerManager();

};