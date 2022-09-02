#include <iostream>
#include<fstream>
#include <ctime>
using namespace std;
#include"globalFILE.h"
#include<string>
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"


void showMenu(){
	cout<<"    ��ӭʹ�û���ԤԼϵͳ       "<<endl;
	cout<<"        ��ѡ�����             "<<endl;
	cout<<"*******************************"<<endl;
	cout<<"            1.ѧ��             "<<endl;
	cout<<"                               "<<endl;
	cout<<"            2.��ʦ             "<<endl;
	cout<<"                               "<<endl;
	cout<<"           3.����Ա            "<<endl;
	cout<<"                               "<<endl;
	cout<<"         0.�˳�ԤԼϵͳ        "<<endl;
	cout<<"*******************************"<<endl;

}

//ѧ�������
void stuMenu(Identity* &student){
	while(true){
	student->Menu();
	Student* stu=(Student*)student;
	
	int select;
	cin>>select;
	if(select==1){
		stu->Apply();
	}
	else if(select==2){
		stu->showMy();
	}
	else if(select==3){
		stu->showAll();
	}
	else if(select==4){
	
		stu->cancelOrder();
	}
	//�˳���¼
	else{
		delete student;
		cout<<"�˳���¼�ɹ���"<<endl;
		system("pause");
		system("cls");
		return;
	}
	}

}

void teaMenu(Identity* &teacher){
while(true){
	teacher->Menu();
	Teacher* tea=(Teacher*)teacher;
	
	int select;
	cin>>select;
	if(select==1){
		tea->showOrder();
	}
	else if(select==2){
		tea->orderCheck();
	}
	
	//�˳���¼
	else{
		delete teacher;
		cout<<"�˳���¼�ɹ���"<<endl;
		system("pause");
		system("cls");
		return;
	}
	}

}

void manMenu(Identity* &manager){
	while(true){
	manager->Menu();
	//����ָ��managerǿתΪ����ָ�뷽����������Ա����
	Manager* man=(Manager*)manager;
	
	int select;
	cin>>select;
	if(select==1){
		man->addPerson();
	}
	else if(select==2){
		man->showPerson();
	}
	else if(select==3){
		man->showCom();
	}
	else if(select==4){
	//���ԤԼ
		man->clearOrder();
	}
	//�˳���¼
	else{
		delete manager;
		cout<<"�˳���¼�ɹ���"<<endl;
		system("pause");
		system("cls");
		return;
	}
	}
}


//��¼�����������֤
void logIn(string filename,int type){
	Identity* person=NULL; 
	int ID;

	if(type==1){
	//ѧ�����
		cout<<"������ѧ�ţ�"<<endl;
		cin>>ID;
	}

	else if(type==2){
	//��ʦ���
	    cout<<"������ְ����ţ�"<<endl;
		cin>>ID;   
	
	}
	//��ͬ����
	string name;
	int password;
	 cout<<"������������"<<endl;
	cin>>name;
	cout<<"���������룺"<<endl;
	cin>>password;

	ifstream ifs;
	ifs.open(filename,ios::in);
	if(!ifs.is_open()){
	cout<<"�ļ���ʧ�ܣ�"<<endl;
	ifs.close();
	return;
	}

	if(type==1){
	//ѧ�������֤
	int fid;
	string fname;
	int fpw;
	
	while(ifs>>fid&& ifs>>fname && ifs>>fpw){
		if(fid==ID && fname==name && fpw==password){
	//ѧ�������֤�ɹ�
		cout<<"ѧ���������֤�ɹ���"<<endl;
		system("pause");
		system("cls");
		ifs.close();

		person =new Student(ID,name,password);
		stuMenu(person);
		   return ;
		}
	}
	}

	else if(type==2){
	//��ʦ�����֤
    int fid;
	string fname;
	int fpw;
	
	while(ifs>>fid&& ifs>>fname && ifs>>fpw){
		if(fid==ID && fname==name && fpw==password){
	//��ʦ�����֤�ɹ�
		cout<<"��ʦ�������֤�ɹ���"<<endl;
		system("pause");
		system("cls");

		person =new Teacher(ID,name,password);
		teaMenu(person);
		   return ;
		}
	}
	}
	else if(type==3){
		//����Ա�����֤
	string fname;
	int fpw;
	
	while(ifs>>fname && ifs>>fpw){
		if(fname==name && fpw==password){
	//����Ա�����֤�ɹ�
		cout<<"����Ա�������֤�ɹ���"<<endl;
		system("pause");
		system("cls");
		person =new Manager(name,password);

		//�������Ա����
        manMenu(person);
		   return ;
		}
	}
	}

	cout<<"��¼ʧ�ܣ�"<<endl;
	system("pause");
	system("cls");
	return;
}


int main(){
	int select;
	while(true){
		showMenu();
	cin>>select;

	switch(select){
	case 1:logIn(STUDENT,1);
		break;
	case 2:logIn(TEACHER,2);
		break;
	case 3:logIn(MANAGER,3);
		break;
	case 0:
		   cout<<"��ӭ�´�ʹ�ã�"<<endl;
		   system("pause");
		   return 0;
		break;
	default:
		system("cls");
		break;
	
	}
	}
	


system("pause");
return 0;

}