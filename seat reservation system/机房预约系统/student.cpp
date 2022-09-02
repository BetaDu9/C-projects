#include <iostream>
#include"Student.h"
#include<fstream>
using namespace std;
#include"Computer.h"
#include"globalFILE.h"
#include<algorithm>
#include"Order.h"


Student::Student(){

}

Student::Student(int ID,string name,int password){
	this->m_sID=ID;
	this->m_name=name;
	this->m_password=password;
	
	ifstream ifs;
  ifs.open(COMPUTER,ios::in);
  Computer com;
  while(ifs>>com.m_roomNum && ifs>>com.m_maxComputer){
	  v.push_back(com);
  }
  ifs.close();
}


void Student::Menu(){
	cout<<"---------------------"<<endl;
	cout<<"     欢迎学生登录    "<<endl;
	cout<<"                     "<<endl;
	cout<<"     1.申请预约      "<<endl;
	cout<<"                     "<<endl;
	cout<<"     2.查看我的预约  "<<endl;
	cout<<"                     "<<endl;
	cout<<"     3.查看所有预约  "<<endl;
	cout<<"                     "<<endl;
	cout<<"     4.取消预约      "<<endl;
	cout<<"                     "<<endl;
	cout<<"     5.注销登录      "<<endl;
	cout<<"                     "<<endl;
	cout<<"---------------------"<<endl;

}


void Student::Apply(){
	int date;
	int interval;
	int comRoom;

cout<<"机房周一到周五可用！"<<endl;
cout<<"请选择日期："<<endl;
cout<<"1.周一"<<endl;
cout<<"2.周二"<<endl;
cout<<"3.周三"<<endl;
cout<<"4.周四"<<endl;
cout<<"5.周五"<<endl;

while(true){
cin>>date;
if(0<date<6){
	break;
}
else{
cout<<"请重新输入！"<<endl;
}
}

cout<<"请选择时间段："<<endl;
cout<<"1.上午"<<endl;
cout<<"2.下午"<<endl;

while(true){
cin>>interval;
if(interval==1||interval==2){
	break;
}
else{
cout<<"请重新输入！"<<endl;
}
}

cout<<"请选择机房："<<endl;
for(int i=0;i<v.size();i++)
{
	cout<<"机房号："<<v[i].m_roomNum<<"  "<<"机房容量："<<v[i].m_maxComputer<<endl;
}

while(true){
cin>>comRoom;
if(comRoom==1||comRoom==2||comRoom==3){
	break;
}
else{
cout<<"请重新输入！"<<endl;
}
}

cout<<"预约申请成功！"<<endl;

 ofstream ofs;
  ofs.open(ORDER,ios::app);
  ofs<<"studentID:"<<this->m_sID<<"  "<<"studentName:"<<
	  this->m_name<<"  "<<"date:"<<date<<"  "<<"interval:"
	  <<interval<<"  "<<"comRoom:"<<comRoom<<" "<<"state:"<<"1"<<endl;
  ofs.close();
  system("pause");
		system("cls");
		return;
  
}

void Student::showMy(){
	Order od;
	if(od.m_size==0){
	cout<<"无预约信息！"<<endl;
	system("pause");
		system("cls");
	return;
	}

	for(int i=0;i<od.m_size;i++){
		//string 类型转为char类型再转为c风格的int类型
		if(this->m_sID==atoi(od.m_order[i]["studentID"].c_str())){

		cout<<i+1<<". ";
		
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
		
	}
system("pause");
		system("cls");
		return;	

}

void Student::showAll(){
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

void Student::cancelOrder(){
	vector<int>v1;
	int select;
	
	int check;

	Order od;
	if(od.m_size==0){
	cout<<"无预约信息！"<<endl;
	system("pause");
		system("cls");
	return;
	}
	int index=1;
	for(int i=0;i<od.m_size;i++){
		
		if(od.m_order[i]["state"]=="1"||od.m_order[i]["state"]=="2"){

		v1.push_back(i);
		cout<<index<<". ";
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
		index++;
		}
	
	}
	
	if(v1.size()==0){
	
	cout<<"无可以取消的预约记录!"<<endl;
	cout<<endl;
	system("pause");
	 system("cls");
		   return;
	}
	else{
	cout<<"请选择要取消的预约："<<endl;
	cin>>select;
	if(select>0 && select<=v1.size()){
		
		cout<<"是否确认取消预约？"<<endl;
		cout<<"1.是"<<endl;
		cout<<"2.否"<<endl;
		cin>>check;
		if(check==1){
			od.m_order[v1[select-1]]["state"]="3";
		od.updateOrder();
		cout<<"取消预约完成"<<endl;
		}
		else if(check==2){
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