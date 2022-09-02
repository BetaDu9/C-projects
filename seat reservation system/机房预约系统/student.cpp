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
	cout<<"     ��ӭѧ����¼    "<<endl;
	cout<<"                     "<<endl;
	cout<<"     1.����ԤԼ      "<<endl;
	cout<<"                     "<<endl;
	cout<<"     2.�鿴�ҵ�ԤԼ  "<<endl;
	cout<<"                     "<<endl;
	cout<<"     3.�鿴����ԤԼ  "<<endl;
	cout<<"                     "<<endl;
	cout<<"     4.ȡ��ԤԼ      "<<endl;
	cout<<"                     "<<endl;
	cout<<"     5.ע����¼      "<<endl;
	cout<<"                     "<<endl;
	cout<<"---------------------"<<endl;

}


void Student::Apply(){
	int date;
	int interval;
	int comRoom;

cout<<"������һ��������ã�"<<endl;
cout<<"��ѡ�����ڣ�"<<endl;
cout<<"1.��һ"<<endl;
cout<<"2.�ܶ�"<<endl;
cout<<"3.����"<<endl;
cout<<"4.����"<<endl;
cout<<"5.����"<<endl;

while(true){
cin>>date;
if(0<date<6){
	break;
}
else{
cout<<"���������룡"<<endl;
}
}

cout<<"��ѡ��ʱ��Σ�"<<endl;
cout<<"1.����"<<endl;
cout<<"2.����"<<endl;

while(true){
cin>>interval;
if(interval==1||interval==2){
	break;
}
else{
cout<<"���������룡"<<endl;
}
}

cout<<"��ѡ�������"<<endl;
for(int i=0;i<v.size();i++)
{
	cout<<"�����ţ�"<<v[i].m_roomNum<<"  "<<"����������"<<v[i].m_maxComputer<<endl;
}

while(true){
cin>>comRoom;
if(comRoom==1||comRoom==2||comRoom==3){
	break;
}
else{
cout<<"���������룡"<<endl;
}
}

cout<<"ԤԼ����ɹ���"<<endl;

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
	cout<<"��ԤԼ��Ϣ��"<<endl;
	system("pause");
		system("cls");
	return;
	}

	for(int i=0;i<od.m_size;i++){
		//string ����תΪchar������תΪc����int����
		if(this->m_sID==atoi(od.m_order[i]["studentID"].c_str())){

		cout<<i+1<<". ";
		
		cout<<"ԤԼ���ڣ���"<<od.m_order[i]["date"]<<" ";
		cout<<"ԤԼʱ��Σ�"<<(od.m_order[i]["interval"]=="1"?"����":"����")<<" ";
		cout<<"ԤԼ������"<<od.m_order[i]["comRoom"]<<" ";

		string sta=od.m_order[i]["state"];
		if(sta=="1"){
		cout<<"ԤԼ״̬��"<<"�����"<<endl;
		}
		else if(sta=="2"){
		cout<<"ԤԼ״̬��"<<"���ͨ��"<<endl;
		}
		else if(sta=="3"){
		cout<<"ԤԼ״̬��"<<"ԤԼȡ��"<<endl;
		}
		else if(sta=="-1"){
		cout<<"ԤԼ״̬��"<<"ԤԼʧ��"<<endl;
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
	cout<<"��ԤԼ��Ϣ��"<<endl;
	system("pause");
		system("cls");
	return;
	}

		for(int i=0;i<od.m_size;i++){
		cout<<i+1<<". ";
		cout<<"ѧ��ѧ�ţ�"<<od.m_order[i]["studentID"]<<" ";
		cout<<"ѧ��������"<<od.m_order[i]["studentName"]<<" ";
		cout<<"ԤԼ���ڣ���"<<od.m_order[i]["date"]<<" ";
		cout<<"ԤԼʱ��Σ�"<<(od.m_order[i]["interval"]=="1"?"����":"����")<<" ";
		cout<<"ԤԼ������"<<od.m_order[i]["comRoom"]<<" ";

		string sta=od.m_order[i]["state"];
		if(sta=="1"){
		cout<<"ԤԼ״̬��"<<"�����"<<endl;
		}
		else if(sta=="2"){
		cout<<"ԤԼ״̬��"<<"���ͨ��"<<endl;
		}
		else if(sta=="3"){
		cout<<"ԤԼ״̬��"<<"ԤԼȡ��"<<endl;
		}
		else if(sta=="-1"){
		cout<<"ԤԼ״̬��"<<"ԤԼʧ��"<<endl;
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
	cout<<"��ԤԼ��Ϣ��"<<endl;
	system("pause");
		system("cls");
	return;
	}
	int index=1;
	for(int i=0;i<od.m_size;i++){
		
		if(od.m_order[i]["state"]=="1"||od.m_order[i]["state"]=="2"){

		v1.push_back(i);
		cout<<index<<". ";
		cout<<"ԤԼ���ڣ���"<<od.m_order[i]["date"]<<" ";
		cout<<"ԤԼʱ��Σ�"<<(od.m_order[i]["interval"]=="1"?"����":"����")<<" ";
		cout<<"ԤԼ������"<<od.m_order[i]["comRoom"]<<" ";

		string sta=od.m_order[i]["state"];
		if(sta=="1"){
		cout<<"ԤԼ״̬��"<<"�����"<<endl;
		}
		else if(sta=="2"){
		cout<<"ԤԼ״̬��"<<"���ͨ��"<<endl;
		}
		else if(sta=="3"){
		cout<<"ԤԼ״̬��"<<"ԤԼȡ��"<<endl;
		}
		else if(sta=="-1"){
		cout<<"ԤԼ״̬��"<<"ԤԼʧ��"<<endl;
		}
		index++;
		}
	
	}
	
	if(v1.size()==0){
	
	cout<<"�޿���ȡ����ԤԼ��¼!"<<endl;
	cout<<endl;
	system("pause");
	 system("cls");
		   return;
	}
	else{
	cout<<"��ѡ��Ҫȡ����ԤԼ��"<<endl;
	cin>>select;
	if(select>0 && select<=v1.size()){
		
		cout<<"�Ƿ�ȷ��ȡ��ԤԼ��"<<endl;
		cout<<"1.��"<<endl;
		cout<<"2.��"<<endl;
		cin>>check;
		if(check==1){
			od.m_order[v1[select-1]]["state"]="3";
		od.updateOrder();
		cout<<"ȡ��ԤԼ���"<<endl;
		}
		else if(check==2){
		  system("cls");
		   return;
		}

		}
		else{
		cout<<"�������"<<endl;
		}
		system("pause");
		system("cls");
		return;
	}
}