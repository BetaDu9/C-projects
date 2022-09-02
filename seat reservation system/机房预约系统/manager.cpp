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
	cout<<"    ��ӭ����Ա��¼   "<<endl;
	cout<<"                     "<<endl;
	cout<<"     1.����˺�      "<<endl;
	cout<<"                     "<<endl;
	cout<<"     2.�鿴�˺�      "<<endl;
	cout<<"                     "<<endl;
	cout<<"     3.�鿴����      "<<endl;
	cout<<"                     "<<endl;
	cout<<"     4.���ԤԼ      "<<endl;
	cout<<"                     "<<endl;
	cout<<"     5.ע����¼      "<<endl;
	cout<<"                     "<<endl;
	cout<<"---------------------"<<endl;

}

void Manager::addPerson(){
  int select;
  cout<<"��ѡ��������ͣ�"<<endl;
  cout<<"1.ѧ��"<<endl;
  cout<<"2.��ʦ"<<endl;
  cin>>select;
  if(select==1){
  //���ѧ��
	int ID;
	string name;
	int password;
	
  cout<<"������ѧ�ţ�"<<endl;
  
  //����
  while(true){
  cin>>ID;
 bool ret=this->checkRepeat(ID,1);
  if(ret){
	  cout<<"ѧ���ظ�������������"<<endl;
  }
  else{
  break;
  }
  
  }

  cout<<"������ѧ��������"<<endl;
  cin>>name;
  cout<<"������ѧ�����룺"<<endl;
  cin>>password;

  ofstream ofs;
  ofs.open(STUDENT,ios::app);
  ofs<<ID<<" "<<name<<" "<<password<<" "<<endl;
  cout<<"���ѧ���ɹ���"<<endl;
  system("pause");
		system("cls");
		return;

  }
  else{
  //�����ʦ
  int ID;
	string name;
	int password;
	
  cout<<"������ְ���ţ�"<<endl;
  
  //����
  while(true){
  cin>>ID;
 bool ret=this->checkRepeat(ID,2);
  if(ret){
	  cout<<"ְ�����ظ�������������"<<endl;
  }
  else{
  break;
  }
  
  }
  cout<<"��������ʦ������"<<endl;
  cin>>name;
  cout<<"��������ʦ���룺"<<endl;
  cin>>password;

  ofstream ofs;
  ofs.open(TEACHER,ios::app);
  ofs<<ID<<" "<<name<<" "<<password<<" "<<endl;
  cout<<"�����ʦ�ɹ���"<<endl;
  system("pause");
		system("cls");
		return;
  
  }

}

bool Manager::checkRepeat(int id,int type){
	int fID;
	string fname;
	int fpassword;
//���ѧ��
if(type==1){
  ifstream ifs;
  ifs.open(STUDENT,ios::in);
  if(!ifs.is_open()){
  cout<<"�ļ���ʧ�ܣ�"<<endl;
  }

  else{
	  while(ifs>>fID&&ifs>>fname&&ifs>>fpassword){
		  if(fID==id){
		  return true;
		  }
	  }	
	}

}
//�����ʦ
else{
ifstream ifs;
  ifs.open(TEACHER,ios::in);
  if(!ifs.is_open()){
  cout<<"�ļ���ʧ�ܣ�"<<endl;
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
  cout<<"��ѡ��鿴���ͣ�"<<endl;
  cout<<"1.ѧ��"<<endl;
  cout<<"2.��ʦ"<<endl;
  cin>>select;

  int fID;
	string fname;
	int fpassword;

  if(select==1){
  ifstream ifs;
  ifs.open(STUDENT,ios::in);
  if(!ifs.is_open()){
  cout<<"�ļ���ʧ�ܣ�"<<endl;
  }
  else{
	  while(ifs>>fID&&ifs>>fname&&ifs>>fpassword){
	  
		  cout<<"ѧ��ѧ�ţ�"<<fID<<" "<<"ѧ��������"<<fname<<" "<<"ѧ�����룺"<<fpassword<<endl;
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
  cout<<"�ļ���ʧ�ܣ�"<<endl;
  }
  else{
	  while(ifs>>fID&&ifs>>fname&&ifs>>fpassword){
	  
		  cout<<"��ʦְ���ţ�"<<fID<<" "<<"��ʦ������"<<fname<<" "<<"��ʦ���룺"<<fpassword<<endl;
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
  cout<<"������ţ�"<<roomNum<<" "<<"����������"<<maxComputer<<endl;
  }
   system("pause");
	   system("cls");
	  ifs.close();
	  return;
}

void Manager::clearOrder(){
  ofstream ofs;
  ofs.open(ORDER,ios::out|ios::trunc);
  cout<<"���ԤԼ�ɹ���"<<endl;
  system("pause");
	   system("cls");
	  ofs.close();
	  return;
}