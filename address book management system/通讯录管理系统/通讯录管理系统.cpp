#include<iostream>
#include <string>
using namespace std;
#define MAX 1000

//菜单，显示界面
void showMenu(){
   cout<<"**********************"<<endl;
   cout<<"*****1.创建联系人*****"<<endl;
   cout<<"*****2.显示联系人*****"<<endl;
   cout<<"*****3.删除联系人*****"<<endl;
   cout<<"*****4.查找联系人*****"<<endl;
   cout<<"*****5.修改联系人*****"<<endl;
   cout<<"*****6.清空通讯录*****"<<endl;
   cout<<"*****0.退出通讯录*****"<<endl;
   cout<<"**********************"<<endl;
}



//创建通讯录结构体
struct Person{
string m_name;
int m_sex;
int m_age;
string m_phone;
string m_address;
};
 
struct Addressbook{
  struct Person personArray[MAX];//通讯录联系人数组
  int size_m;//通讯录人数

};

//添加联系人功能
void addPerson(Addressbook *abs){
	if(abs->size_m==MAX){        //判断符号为==
	cout<<"通讯录已满！"<<endl;
	}
	else{
	cout<<"请输入联系人姓名： "<<endl;
	string name;
	cin>>name;
	abs->personArray[abs->size_m].m_name=name;
	cout<<"性别： "<<endl;
	int sex;
	cin>>sex;
	abs->personArray[abs->size_m].m_sex=sex;
	cout<<"年龄： "<<endl;
	int age;
	cin>>age;
	abs->personArray[abs->size_m].m_age=age;
	cout<<"电话号码：  "<<endl;
	int phone;
	cin>>phone;
	abs->personArray[abs->size_m].m_phone=phone;
	cout<<"家庭住址：  "<<endl;
	string add;
	cin>>add;
	abs->personArray[abs->size_m].m_address=add;
	abs->size_m ++;
	cout<<"保存成功！"<<endl;
	}
	system ("pause");
	system("cls");
}

//显示联系人
void showPerson (Addressbook *abs){
	if( abs->size_m==0){
	cout<<"无联系人！"<<endl;
	}
	else{
	for (int i=0;i<abs->size_m;i++ ){
		cout<<"联系人姓名： "<<abs->personArray[i].m_name<<"\t";
		cout<<"性别： "<<(abs->personArray[i].m_sex==1?"男":"女")<<"\t"; //三目运算符，注意运算优先级
		cout<<"年龄： "<<abs->personArray[i].m_age<<"\t";
        cout<<"联系电话： "<<abs->personArray[i].m_phone<<"\t";
        cout<<"家庭住址： "<<abs->personArray[i].m_address<<endl;
		
}
	}
	system("pause");
	system("cls");
}

//删除联系人：
//输入联系人姓名，遍历是否有此人
int Exist(Addressbook *abs,string name){
	for (int i=0;i<abs->size_m;i++){
		if(abs->personArray[i].m_name==name){
		 return i;
		}
	}
		return -1;

}

//删除联系人
void DeletePerson(Addressbook *abs){
  string Name;
	cout<<"请输入删除联系人姓名： "<<endl;
	cin>>Name;
	int del=Exist(abs,Name);
	if ( del==(-1))
	{
	cout<<"无此联系人"<<endl;
	}
	else{
		for (int i=del;i<abs->size_m;i++)
		{
		 abs->personArray[i]=abs->personArray[i+1];
		}
		abs->size_m--;
		cout<<"已删除联系人"<<endl;
	}
system ("pause");
system("cls");
}

//查找联系人
void findPerson(Addressbook *abs){
	string name;
	cout<<"请输入查找联系人姓名： "<<endl;
	cin>>name;
	int find=Exist(abs,name);
	if (find==-1){
	cout<<"无此联系人"<<endl;
	}
	else{
	    cout<<"联系人姓名： "<<abs->personArray[find].m_name<<"\t";
		cout<<"性别： "<<(abs->personArray[find].m_sex==1?"男":"女")<<"\t"; 
		cout<<"年龄： "<<abs->personArray[find].m_age<<"\t";
        cout<<"联系电话： "<<abs->personArray[find].m_phone<<"\t";
        cout<<"家庭住址： "<<abs->personArray[find].m_address<<endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(Addressbook *abs){
string name;
	cout<<"请输入修改联系人姓名： "<<endl;
	cin>>name;
	int mod=Exist(abs,name);
	if (mod==-1){
	cout<<"无此联系人"<<endl;
	}
	else{
	cout<<"性别： "<<endl;
	int sex;
	cin>>sex;
	abs->personArray[mod].m_sex=sex;
	cout<<"年龄： "<<endl;
	int age;
	cin>>age;
	abs->personArray[mod].m_age=age;
	cout<<"电话号码：  "<<endl;
	int phone;
	cin>>phone;
	abs->personArray[mod].m_phone=phone;
	cout<<"家庭住址：  "<<endl;
	string add;
	cin>>add;
	abs->personArray[mod].m_address=add;
	
	cout<<"修改成功！"<<endl;

	}
system("pause");
	system("cls");
}

//清空联系人，将人数置零做逻辑上的清空
void cleanPerson(Addressbook *abs){
    cout<<"确认清空？"<<endl;
	cout<<"1. 是" <<endl;
	cout<<"2. 否"<<endl;
	int con=0;
	cin>>con;
	if(con==1){
		abs->size_m=0;
		cout<<"已清空通讯录"<<endl;
	}
	system("pause");
	system("cls");
}

int main(){
//显示菜单
	int select=0;
	struct Addressbook abs;
	abs.size_m=0;
//用户输入，循环使用直到用户退出	
	
	while(true){
		showMenu();
		cin>>select;
	switch(select){
case 1:addPerson( &abs);//地址传递方法以便修改实参，修改abs以加入联系人

		break;
case 2:showPerson(&abs);
		break;
case 3:DeletePerson(&abs);
	
		break;
case 4:findPerson(&abs);
		break;
case 5:modifyPerson(&abs);
		break;
case 6:cleanPerson(&abs);
	
	       break;
case 0:  cout<<"欢迎下次使用"<<endl;
		system("pause");
		return 0;
default:
		break;
	}
}
system("pause");
		
		return 0;	

}

