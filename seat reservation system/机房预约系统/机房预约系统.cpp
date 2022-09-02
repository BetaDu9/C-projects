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
	cout<<"    欢迎使用机房预约系统       "<<endl;
	cout<<"        请选择身份             "<<endl;
	cout<<"*******************************"<<endl;
	cout<<"            1.学生             "<<endl;
	cout<<"                               "<<endl;
	cout<<"            2.老师             "<<endl;
	cout<<"                               "<<endl;
	cout<<"           3.管理员            "<<endl;
	cout<<"                               "<<endl;
	cout<<"         0.退出预约系统        "<<endl;
	cout<<"*******************************"<<endl;

}

//学生端入口
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
	//退出登录
	else{
		delete student;
		cout<<"退出登录成功！"<<endl;
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
	
	//退出登录
	else{
		delete teacher;
		cout<<"退出登录成功！"<<endl;
		system("pause");
		system("cls");
		return;
	}
	}

}

void manMenu(Identity* &manager){
	while(true){
	manager->Menu();
	//父类指针manager强转为子类指针方便调用子类成员函数
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
	//清空预约
		man->clearOrder();
	}
	//退出登录
	else{
		delete manager;
		cout<<"退出登录成功！"<<endl;
		system("pause");
		system("cls");
		return;
	}
	}
}


//登录函数，身份验证
void logIn(string filename,int type){
	Identity* person=NULL; 
	int ID;

	if(type==1){
	//学生身份
		cout<<"请输入学号："<<endl;
		cin>>ID;
	}

	else if(type==2){
	//老师身份
	    cout<<"请输入职工编号："<<endl;
		cin>>ID;   
	
	}
	//共同部分
	string name;
	int password;
	 cout<<"请输入姓名："<<endl;
	cin>>name;
	cout<<"请输入密码："<<endl;
	cin>>password;

	ifstream ifs;
	ifs.open(filename,ios::in);
	if(!ifs.is_open()){
	cout<<"文件打开失败！"<<endl;
	ifs.close();
	return;
	}

	if(type==1){
	//学生身份验证
	int fid;
	string fname;
	int fpw;
	
	while(ifs>>fid&& ifs>>fname && ifs>>fpw){
		if(fid==ID && fname==name && fpw==password){
	//学生身份验证成功
		cout<<"学生端身份验证成功！"<<endl;
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
	//老师身份验证
    int fid;
	string fname;
	int fpw;
	
	while(ifs>>fid&& ifs>>fname && ifs>>fpw){
		if(fid==ID && fname==name && fpw==password){
	//老师身份验证成功
		cout<<"老师端身份验证成功！"<<endl;
		system("pause");
		system("cls");

		person =new Teacher(ID,name,password);
		teaMenu(person);
		   return ;
		}
	}
	}
	else if(type==3){
		//管理员身份验证
	string fname;
	int fpw;
	
	while(ifs>>fname && ifs>>fpw){
		if(fname==name && fpw==password){
	//管理员身份验证成功
		cout<<"管理员端身份验证成功！"<<endl;
		system("pause");
		system("cls");
		person =new Manager(name,password);

		//进入管理员界面
        manMenu(person);
		   return ;
		}
	}
	}

	cout<<"登录失败！"<<endl;
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
		   cout<<"欢迎下次使用！"<<endl;
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