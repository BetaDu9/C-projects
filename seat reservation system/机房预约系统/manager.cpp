#include <iostream>
#include"Manager.h"
#include<fstream>
using namespace std;
#include"globalFILE.h"

Manager::Manager(){

}

Manager::Manager(string name,int password){
	this->m_name=name;
	this->m_password=password;

}

void Manager::Menu(){
	cout<<"---------------------"<<endl;
	cout<<"    欢迎管理员登录   "<<endl;
	cout<<"                     "<<endl;
	cout<<"     1.添加账号      "<<endl;
	cout<<"                     "<<endl;
	cout<<"     2.查看账号      "<<endl;
	cout<<"                     "<<endl;
	cout<<"     3.查看机房      "<<endl;
	cout<<"                     "<<endl;
	cout<<"     4.清空预约      "<<endl;
	cout<<"                     "<<endl;
	cout<<"     5.注销登录      "<<endl;
	cout<<"                     "<<endl;
	cout<<"---------------------"<<endl;

}

void Manager::addPerson(){
  int select;
  cout<<"请选择添加类型："<<endl;
  cout<<"1.学生"<<endl;
  cout<<"2.老师"<<endl;
  cin>>select;
  if(select==1){
  //添加学生
	int ID;
	string name;
	int password;
	
  cout<<"请输入学号："<<endl;
  
  //查重
  while(true){
  cin>>ID;
 bool ret=this->checkRepeat(ID,1);
  if(ret){
	  cout<<"学号重复，请重新输入"<<endl;
  }
  else{
  break;
  }
  
  }

  cout<<"请输入学生姓名："<<endl;
  cin>>name;
  cout<<"请输入学生密码："<<endl;
  cin>>password;

  ofstream ofs;
  ofs.open(STUDENT,ios::app);
  ofs<<ID<<" "<<name<<" "<<password<<" "<<endl;
  cout<<"添加学生成功！"<<endl;
  system("pause");
		system("cls");
		return;

  }
  else{
  //添加老师
  int ID;
	string name;
	int password;
	
  cout<<"请输入职工号："<<endl;
  
  //查重
  while(true){
  cin>>ID;
 bool ret=this->checkRepeat(ID,2);
  if(ret){
	  cout<<"职工号重复，请重新输入"<<endl;
  }
  else{
  break;
  }
  
  }
  cout<<"请输入老师姓名："<<endl;
  cin>>name;
  cout<<"请输入老师密码："<<endl;
  cin>>password;

  ofstream ofs;
  ofs.open(TEACHER,ios::app);
  ofs<<ID<<" "<<name<<" "<<password<<" "<<endl;
  cout<<"添加老师成功！"<<endl;
  system("pause");
		system("cls");
		return;
  
  }

}

bool Manager::checkRepeat(int id,int type){
	int fID;
	string fname;
	int fpassword;
//检测学生
if(type==1){
  ifstream ifs;
  ifs.open(STUDENT,ios::in);
  if(!ifs.is_open()){
  cout<<"文件打开失败！"<<endl;
  }

  else{
	  while(ifs>>fID&&ifs>>fname&&ifs>>fpassword){
		  if(fID==id){
		  return true;
		  }
	  }	
	}

}
//检测老师
else{
ifstream ifs;
  ifs.open(TEACHER,ios::in);
  if(!ifs.is_open()){
  cout<<"文件打开失败！"<<endl;
  }

  else{
	  while(ifs>>fID&&ifs>>fname&&ifs>>fpassword){
		  if(fID==id){
		  return true;
		  }
	  }	
	}

}

return false;

}


void Manager::showPerson(){
	int select;
  cout<<"请选择查看类型："<<endl;
  cout<<"1.学生"<<endl;
  cout<<"2.老师"<<endl;
  cin>>select;

  int fID;
	string fname;
	int fpassword;

  if(select==1){
  ifstream ifs;
  ifs.open(STUDENT,ios::in);
  if(!ifs.is_open()){
  cout<<"文件打开失败！"<<endl;
  }
  else{
	  while(ifs>>fID&&ifs>>fname&&ifs>>fpassword){
	  
		  cout<<"学生学号："<<fID<<" "<<"学生姓名："<<fname<<" "<<"学生密码："<<fpassword<<endl;
	  }
	  system("pause");
	   system("cls");
	  ifs.close();
	  return;
  }

  }
  else{
  ifstream ifs;
  ifs.open(TEACHER,ios::in);
  if(!ifs.is_open()){
  cout<<"文件打开失败！"<<endl;
  }
  else{
	  while(ifs>>fID&&ifs>>fname&&ifs>>fpassword){
	  
		  cout<<"老师职工号："<<fID<<" "<<"老师姓名："<<fname<<" "<<"老师密码："<<fpassword<<endl;
	  }
	  system("pause");
	   system("cls");
	  ifs.close();
	  return;
  
  }
}
}


void Manager::showCom(){
	  ifstream ifs;
  ifs.open(COMPUTER,ios::in);
  int roomNum;
  int maxComputer;
  while(ifs>>roomNum && ifs>>maxComputer){
  cout<<"机房编号："<<roomNum<<" "<<"电脑数量："<<maxComputer<<endl;
  }
   system("pause");
	   system("cls");
	  ifs.close();
	  return;
}

void Manager::clearOrder(){
  ofstream ofs;
  ofs.open(ORDER,ios::out|ios::trunc);
  cout<<"清空预约成功！"<<endl;
  system("pause");
	   system("cls");
	  ofs.close();
	  return;
}