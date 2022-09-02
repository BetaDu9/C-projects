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

//构造函数
Manager::Manager(){
	//初始化容器
	this->init();
	//创建选手
	this->creatSpeaker();
	//读出往届比赛数据
	this->loadScore();
}



void Manager::init(){
	//初始化容器
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();
	//初始化记录容器
	this->m_Contest.clear();

	this->index=1;

	
}


void Manager::creatSpeaker(){
 Speaker sp;
  string nameSeed="ABCDEFGHIJKL";

  for(int i=0;i<12;i++){
	string name="选手";
    name+=nameSeed[i];
	sp.m_name=name;

	for(int j=0;j<2;j++){
	sp.m_score[j]=0;
	}
	//选手编号放入v1容器
	this->v1.push_back(i+10000);
	this->m_Speaker.insert(make_pair(i+10000,sp));

  }
}

//给选手抽签
void Manager::drawSpeaker(){
	cout<<"选手正在抽签....."<<endl;
	cout<<"-----------------"<<endl;
	system("pause");
	cout<<"比赛顺序如下："<<endl;
	if(this->index==1){
		random_shuffle(v1.begin(),v1.end());
		
		for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
		  cout<<*it<<" ";
	
		}
	cout<<endl;
	}

	//第二轮比赛
	else {
	random_shuffle(v2.begin(),v2.end());
		for(vector<int>::iterator it=v2.begin();it!=v2.end();it++){
		  cout<<*it<<" ";
	
	}
		cout<<endl;
	}
	system("pause");
}



//给选手打分
void Manager::getScore(){
	multimap<double,int,greater<double>>group;

	//第一轮比赛
	if(this->index==1){
		int num=0;
		//准备临时容器进行分数降序排序
	   //评委打分
	for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
		deque<double>d;
		num++;

		for(int i=0;i<10;i++){
		double score=(rand()%401+600)/10.f;
		d.push_back(score);
		}
		
		sort(d.begin(),d.end(),greater<double>());
		d.pop_back();
		d.pop_front();
		double sum=accumulate(d.begin(),d.end(),0.0f);
		
		double ave=sum/(double)d.size();
		this->m_Speaker[*it].m_score[0]=ave;
		group.insert(make_pair(ave,*it));
		//十二个选手分数存入临时容器

		//第一组输出成绩
        if(num==6){
		cout<<"第一组成绩如下："<<endl;
		int count=0;
		for(multimap<double,int,greater<double>>::iterator it=group.begin();it!=group.end();it++){
			cout<<"选手编号："<<it->second<<" "<<"选手姓名："<<this->m_Speaker[it->second].m_name<<
				" "<<"选手得分："<<this->m_Speaker[it->second].m_score[0]<<endl;
			
			if(count<3){
			v2.push_back(it->second);
			}
		count++;	
			
		}
		group.clear();
		}
		//第二组成绩输出
		if(num==12){
			int count=0;
		cout<<endl;
		cout<<"第二组成绩如下："<<endl;
		for(multimap<double,int,greater<double>>::iterator it=group.begin();it!=group.end();it++){
			cout<<"选手编号："<<it->second<<" "<<"选手姓名："<<this->m_Speaker[it->second].m_name
				<<" "<<"选手得分："<<this->m_Speaker[it->second].m_score[0]<<endl;

		//第一轮晋级
			if(count<3){
			v2.push_back(it->second);
			}
			count++;
			
		}
		group.clear();

		}	
	}
	num=0;
	}


	//第二轮比赛
	if(this->index==2){
	
	cout<<"第二轮比赛成绩如下："<<endl;
	for(vector<int>::iterator it=v2.begin();it!=v2.end();it++){
		deque<double>d;

		//评委打分求平均分
		for(int i=0;i<10;i++){
		double score=(rand()%401+600)/10.f;
		d.push_back(score);
		}
		
		sort(d.begin(),d.end(),greater<double>());
		d.pop_back();
		d.pop_front();
		double sum=accumulate(d.begin(),d.end(),0.0f);
		double ave=sum/(double)d.size();

		this->m_Speaker[*it].m_score[1]=ave;
		
		group.insert(make_pair(ave,*it));
	}

		//显示成绩
		int count=0;
		for(multimap<double,int,greater<double>>::iterator it=group.begin();it!=group.end();it++){
			cout<<"选手编号："<<it->second<<" "<<"选手姓名："<<this->m_Speaker[it->second].m_name<<
				" "<<"选手得分："<<this->m_Speaker[it->second].m_score[1]<<endl;
			
			if(count<3){
			v3.push_back(it->second);
			}
			count++;
			
		}
		group.clear();
	}
	
	system("pause");
}


//显示晋级结果
void Manager::showResult(){
	if(this->index==1){
	//根据打分结果排序
		for(vector<int>::iterator it=v2.begin();it!=v2.end();it++){
			cout<<"选手编号："<<*it<<"  "<<"选手姓名："<<this->m_Speaker[*it].m_name
				<<"  "<<"选手分数："<<this->m_Speaker[*it].m_score[0]<<endl;
		}
	}
	//第二轮比赛
	else if(this->index==2){
	for(vector<int>::iterator it=v3.begin();it!=v3.end();it++){

	cout<<"选手编号："<<*it<<"  "<<"选手姓名："<<this->m_Speaker[*it].m_name
				<<"  "<<"选手分数："<<this->m_Speaker[*it].m_score[1]<<endl;
		}
	}
	system("pause");
}




//保存比赛记录
void Manager::saveScore(){
	ofstream ofs;
	ofs.open("speech.csv",ios::out|ios::app);
	for(vector<int>::iterator it=v3.begin();it!=v3.end();it++){
		ofs<<*it<<","<<this->m_Speaker[*it].m_score[1]<<",";
	}
	ofs<<endl;
	cout<<"比赛结果已保存"<<endl;
	this->emptyFile=0;
	
}

//初始化往届记录容器以方便打印查看
void Manager::loadScore(){
	vector<string>v;
	ifstream ifs;
	ifs.open("speech.csv",ios::in);
	if(!ifs.is_open()){
		cout<<"文件打开失败"<<endl;
		this->emptyFile=1;
		ifs.close();
		return;
	}
	char ch;
	ifs>>ch;
	if(ifs.eof()){
	//cout<<"文件为空"<<endl;
	this->emptyFile=1;
	ifs.close();
		return;
	}

	this->emptyFile=0;
	ifs.putback(ch);

	int index=0;
	string data;
	string value;

	//一行一行地读出数据（一届一届）
	while(ifs>>data){
	int pos=-1;
	int start=0;
	//读出一届比赛的六个数据
  while(true){

	pos= data.find(",",start);
	  if(pos==-1){
	  break;
	             }
	value=data.substr(start,pos-start);
	v.push_back(value);
	start=pos+1;
	       }
   this->m_Contest.insert(make_pair(index+1,v));
   //记住清空容器！不然每一届显示结果都一样
   v.clear();
   index++;
	
	}
	ifs.close();
}


Manager::~Manager(){


}