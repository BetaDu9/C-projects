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

//比赛过程函数
void Manager::StartSpeech(){
//第一轮比赛
	cout<<"<第一轮比赛开始！>"<<endl;
	//抽签
	this->drawSpeaker();
	//第一轮比赛进行
	cout<<"----------------------"<<endl;
	cout<<"第一轮比赛进行中..."<<endl;
	cout<<"----------------------"<<endl;
	system("pause");
	this->getScore();
	cout<<"----------------------"<<endl;
	cout<<"第一轮比赛结束！"<<endl;
	cout<<"----------------------"<<endl;
	
	//显示晋级结果
	cout<<"晋级结果："<<endl;
	this->showResult();

//第二轮比赛
	this->index++;
	cout<<"------------------"<<endl;
	cout<<"<第二轮比赛开始！>"<<endl;
	cout<<"------------------"<<endl;
	//抽签
	drawSpeaker();
	//进行第二轮比赛
	cout<<"----------------------"<<endl;
	cout<<"第二轮比赛进行中..."<<endl;
	cout<<"----------------------"<<endl;
	system("pause");
	this->getScore();
	cout<<"----------------------"<<endl;
	cout<<"第二轮比赛结束！"<<endl;
	cout<<"----------------------"<<endl;
	
	//显示最终结果
	cout<<"晋级结果："<<endl;
	this->showResult();
	cout<<"----------------------"<<endl;
	cout<<"演讲比赛结束"<<endl;
	cout<<"----------------------"<<endl;
	this->saveScore();

	//重置比赛
	this->init();
	this->creatSpeaker();
	this->loadScore();

	system("pause");
	system("cls");
	return;
}