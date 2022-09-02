#include <iostream>
#include"Teacher.h"
#include<fstream>
using namespace std;
#include"Order.h"

Teacher::Teacher(){}

Teacher::Teacher(int ID,string name,int password){

}

void Teacher::Menu(){
    cout<<"---------------------"<<endl;
	cout<<"     欢迎老师登录    "<<endl;
	cout<<"                     "<<endl;
	cout<<"     1.查看预约      "<<endl;
	cout<<"                     "<<endl;
	cout<<"     2.审核预约      "<<endl;
	cout<<"                     "<<endl;
	cout<<"     5.注销登录      "<<endl;
	cout<<"                     "<<endl;
	cout<<"---------------------"<<endl;
}

void Teacher::showOrder(){
	Order od;
	if(od.m_size==0){
	cout<<"无预约信息！"<<endl;
	system("pause");
		system("cls");
	return;
	}

		for(int i=0;i<od.m_size;i++){
		cout<<i+1<<". ";
		cout<<"学生学号："<<od.m_order[i]["studentID"]<<" ";
		cout<<"学生姓名："<<od.m_order[i]["studentName"]<<" ";
		cout<<"预约日期：周"<<od.m_order[i]["date"]<<" ";
		cout<<"预约时间段："<<(od.m_order[i]["interval"]=="1"?"上午":"下午")<<" ";
		cout<<"预约机房："<<od.m_order[i]["comRoom"]<<" ";

		string sta=od.m_order[i]["state"];
		if(sta=="1"){
		cout<<"预约状态："<<"审核中"<<endl;
		}
		else if(sta=="2"){
		cout<<"预约状态："<<"审核通过"<<endl;
		}
		else if(sta=="3"){
		cout<<"预约状态："<<"预约取消"<<endl;
		}
		else if(sta=="-1"){
		cout<<"预约状态："<<"预约失败"<<endl;
		}
		}

system("pause");
		system("cls");
		return;

}

void Teacher::orderCheck(){
	//显示审核中
	Order od;
	if(od.m_size==0){
	cout<<"无预约信息！"<<endl;
	system("pause");
		system("cls");
	return;
	}

	vector<int>v;
	int index=1;
	cout<<"待审核预约信息如下："<<endl;
		for(int i=0;i<od.m_size;i++){
			if(od.m_order[i]["state"]=="1"){
			v.push_back(i);
		cout<<index<<". ";
		cout<<"学生学号："<<od.m_order[i]["studentID"]<<" ";
		cout<<"学生姓名："<<od.m_order[i]["studentName"]<<" ";
		cout<<"预约日期：周"<<od.m_order[i]["date"]<<" ";
		cout<<"预约时间段："<<(od.m_order[i]["interval"]=="1"?"上午":"下午")<<" ";
		cout<<"预约机房："<<od.m_order[i]["comRoom"]<<" ";
		cout<<"预约状态：审核中"<<endl;
	    index++;
			}
     
}
		int select;
		int check;

		if(v.size()==0){
		cout<<"暂无需要审核的预约信息"<<endl;
		cout<<endl;
		system("pause");
		system("cls");
		return;
		}
		else{
		cout<<"请选择审核信息："<<endl;
		cout<<"(输入0返回上一级)"<<endl;
		cin>>select;
		if(select>=0 && select<=v.size()){
		
			if(select!=0){
		cout<<"请选择是否通过："<<endl;
		cout<<"1.通过"<<endl;
		cout<<"2.不通过"<<endl;
		cin>>check;
		if(check==1){
			od.m_order[v[select-1]]["state"]="2";
		
		}
		else{
		    od.m_order[v[select-1]]["state"]="-1";
		}
		od.updateOrder();
		cout<<"审核完成"<<endl;
			}
			else if(select==0){
		
		system("cls");
			return;
			}

		}
		else{
		cout<<"输入错误"<<endl;
		}
		system("pause");
		system("cls");
		return;
		}
}