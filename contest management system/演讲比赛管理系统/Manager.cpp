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

//���캯��
Manager::Manager(){
	//��ʼ������
	this->init();
	//����ѡ��
	this->creatSpeaker();
	//���������������
	this->loadScore();
}



void Manager::init(){
	//��ʼ������
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();
	//��ʼ����¼����
	this->m_Contest.clear();

	this->index=1;

	
}


void Manager::creatSpeaker(){
 Speaker sp;
  string nameSeed="ABCDEFGHIJKL";

  for(int i=0;i<12;i++){
	string name="ѡ��";
    name+=nameSeed[i];
	sp.m_name=name;

	for(int j=0;j<2;j++){
	sp.m_score[j]=0;
	}
	//ѡ�ֱ�ŷ���v1����
	this->v1.push_back(i+10000);
	this->m_Speaker.insert(make_pair(i+10000,sp));

  }
}

//��ѡ�ֳ�ǩ
void Manager::drawSpeaker(){
	cout<<"ѡ�����ڳ�ǩ....."<<endl;
	cout<<"-----------------"<<endl;
	system("pause");
	cout<<"����˳�����£�"<<endl;
	if(this->index==1){
		random_shuffle(v1.begin(),v1.end());
		
		for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
		  cout<<*it<<" ";
	
		}
	cout<<endl;
	}

	//�ڶ��ֱ���
	else {
	random_shuffle(v2.begin(),v2.end());
		for(vector<int>::iterator it=v2.begin();it!=v2.end();it++){
		  cout<<*it<<" ";
	
	}
		cout<<endl;
	}
	system("pause");
}



//��ѡ�ִ��
void Manager::getScore(){
	multimap<double,int,greater<double>>group;

	//��һ�ֱ���
	if(this->index==1){
		int num=0;
		//׼����ʱ�������з�����������
	   //��ί���
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
		//ʮ����ѡ�ַ���������ʱ����

		//��һ������ɼ�
        if(num==6){
		cout<<"��һ��ɼ����£�"<<endl;
		int count=0;
		for(multimap<double,int,greater<double>>::iterator it=group.begin();it!=group.end();it++){
			cout<<"ѡ�ֱ�ţ�"<<it->second<<" "<<"ѡ��������"<<this->m_Speaker[it->second].m_name<<
				" "<<"ѡ�ֵ÷֣�"<<this->m_Speaker[it->second].m_score[0]<<endl;
			
			if(count<3){
			v2.push_back(it->second);
			}
		count++;	
			
		}
		group.clear();
		}
		//�ڶ���ɼ����
		if(num==12){
			int count=0;
		cout<<endl;
		cout<<"�ڶ���ɼ����£�"<<endl;
		for(multimap<double,int,greater<double>>::iterator it=group.begin();it!=group.end();it++){
			cout<<"ѡ�ֱ�ţ�"<<it->second<<" "<<"ѡ��������"<<this->m_Speaker[it->second].m_name
				<<" "<<"ѡ�ֵ÷֣�"<<this->m_Speaker[it->second].m_score[0]<<endl;

		//��һ�ֽ���
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


	//�ڶ��ֱ���
	if(this->index==2){
	
	cout<<"�ڶ��ֱ����ɼ����£�"<<endl;
	for(vector<int>::iterator it=v2.begin();it!=v2.end();it++){
		deque<double>d;

		//��ί�����ƽ����
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

		//��ʾ�ɼ�
		int count=0;
		for(multimap<double,int,greater<double>>::iterator it=group.begin();it!=group.end();it++){
			cout<<"ѡ�ֱ�ţ�"<<it->second<<" "<<"ѡ��������"<<this->m_Speaker[it->second].m_name<<
				" "<<"ѡ�ֵ÷֣�"<<this->m_Speaker[it->second].m_score[1]<<endl;
			
			if(count<3){
			v3.push_back(it->second);
			}
			count++;
			
		}
		group.clear();
	}
	
	system("pause");
}


//��ʾ�������
void Manager::showResult(){
	if(this->index==1){
	//���ݴ�ֽ������
		for(vector<int>::iterator it=v2.begin();it!=v2.end();it++){
			cout<<"ѡ�ֱ�ţ�"<<*it<<"  "<<"ѡ��������"<<this->m_Speaker[*it].m_name
				<<"  "<<"ѡ�ַ�����"<<this->m_Speaker[*it].m_score[0]<<endl;
		}
	}
	//�ڶ��ֱ���
	else if(this->index==2){
	for(vector<int>::iterator it=v3.begin();it!=v3.end();it++){

	cout<<"ѡ�ֱ�ţ�"<<*it<<"  "<<"ѡ��������"<<this->m_Speaker[*it].m_name
				<<"  "<<"ѡ�ַ�����"<<this->m_Speaker[*it].m_score[1]<<endl;
		}
	}
	system("pause");
}




//���������¼
void Manager::saveScore(){
	ofstream ofs;
	ofs.open("speech.csv",ios::out|ios::app);
	for(vector<int>::iterator it=v3.begin();it!=v3.end();it++){
		ofs<<*it<<","<<this->m_Speaker[*it].m_score[1]<<",";
	}
	ofs<<endl;
	cout<<"��������ѱ���"<<endl;
	this->emptyFile=0;
	
}

//��ʼ�������¼�����Է����ӡ�鿴
void Manager::loadScore(){
	vector<string>v;
	ifstream ifs;
	ifs.open("speech.csv",ios::in);
	if(!ifs.is_open()){
		cout<<"�ļ���ʧ��"<<endl;
		this->emptyFile=1;
		ifs.close();
		return;
	}
	char ch;
	ifs>>ch;
	if(ifs.eof()){
	//cout<<"�ļ�Ϊ��"<<endl;
	this->emptyFile=1;
	ifs.close();
		return;
	}

	this->emptyFile=0;
	ifs.putback(ch);

	int index=0;
	string data;
	string value;

	//һ��һ�еض������ݣ�һ��һ�죩
	while(ifs>>data){
	int pos=-1;
	int start=0;
	//����һ���������������
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
   //��ס�����������Ȼÿһ����ʾ�����һ��
   v.clear();
   index++;
	
	}
	ifs.close();
}


Manager::~Manager(){


}