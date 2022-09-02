#include<iostream>
#include <string>
using namespace std;
#define MAX 1000

//�˵�����ʾ����
void showMenu(){
   cout<<"**********************"<<endl;
   cout<<"*****1.������ϵ��*****"<<endl;
   cout<<"*****2.��ʾ��ϵ��*****"<<endl;
   cout<<"*****3.ɾ����ϵ��*****"<<endl;
   cout<<"*****4.������ϵ��*****"<<endl;
   cout<<"*****5.�޸���ϵ��*****"<<endl;
   cout<<"*****6.���ͨѶ¼*****"<<endl;
   cout<<"*****0.�˳�ͨѶ¼*****"<<endl;
   cout<<"**********************"<<endl;
}



//����ͨѶ¼�ṹ��
struct Person{
string m_name;
int m_sex;
int m_age;
string m_phone;
string m_address;
};
 
struct Addressbook{
  struct Person personArray[MAX];//ͨѶ¼��ϵ������
  int size_m;//ͨѶ¼����

};

//�����ϵ�˹���
void addPerson(Addressbook *abs){
	if(abs->size_m==MAX){        //�жϷ���Ϊ==
	cout<<"ͨѶ¼������"<<endl;
	}
	else{
	cout<<"��������ϵ�������� "<<endl;
	string name;
	cin>>name;
	abs->personArray[abs->size_m].m_name=name;
	cout<<"�Ա� "<<endl;
	int sex;
	cin>>sex;
	abs->personArray[abs->size_m].m_sex=sex;
	cout<<"���䣺 "<<endl;
	int age;
	cin>>age;
	abs->personArray[abs->size_m].m_age=age;
	cout<<"�绰���룺  "<<endl;
	int phone;
	cin>>phone;
	abs->personArray[abs->size_m].m_phone=phone;
	cout<<"��ͥסַ��  "<<endl;
	string add;
	cin>>add;
	abs->personArray[abs->size_m].m_address=add;
	abs->size_m ++;
	cout<<"����ɹ���"<<endl;
	}
	system ("pause");
	system("cls");
}

//��ʾ��ϵ��
void showPerson (Addressbook *abs){
	if( abs->size_m==0){
	cout<<"����ϵ�ˣ�"<<endl;
	}
	else{
	for (int i=0;i<abs->size_m;i++ ){
		cout<<"��ϵ�������� "<<abs->personArray[i].m_name<<"\t";
		cout<<"�Ա� "<<(abs->personArray[i].m_sex==1?"��":"Ů")<<"\t"; //��Ŀ�������ע���������ȼ�
		cout<<"���䣺 "<<abs->personArray[i].m_age<<"\t";
        cout<<"��ϵ�绰�� "<<abs->personArray[i].m_phone<<"\t";
        cout<<"��ͥסַ�� "<<abs->personArray[i].m_address<<endl;
		
}
	}
	system("pause");
	system("cls");
}

//ɾ����ϵ�ˣ�
//������ϵ�������������Ƿ��д���
int Exist(Addressbook *abs,string name){
	for (int i=0;i<abs->size_m;i++){
		if(abs->personArray[i].m_name==name){
		 return i;
		}
	}
		return -1;

}

//ɾ����ϵ��
void DeletePerson(Addressbook *abs){
  string Name;
	cout<<"������ɾ����ϵ�������� "<<endl;
	cin>>Name;
	int del=Exist(abs,Name);
	if ( del==(-1))
	{
	cout<<"�޴���ϵ��"<<endl;
	}
	else{
		for (int i=del;i<abs->size_m;i++)
		{
		 abs->personArray[i]=abs->personArray[i+1];
		}
		abs->size_m--;
		cout<<"��ɾ����ϵ��"<<endl;
	}
system ("pause");
system("cls");
}

//������ϵ��
void findPerson(Addressbook *abs){
	string name;
	cout<<"�����������ϵ�������� "<<endl;
	cin>>name;
	int find=Exist(abs,name);
	if (find==-1){
	cout<<"�޴���ϵ��"<<endl;
	}
	else{
	    cout<<"��ϵ�������� "<<abs->personArray[find].m_name<<"\t";
		cout<<"�Ա� "<<(abs->personArray[find].m_sex==1?"��":"Ů")<<"\t"; 
		cout<<"���䣺 "<<abs->personArray[find].m_age<<"\t";
        cout<<"��ϵ�绰�� "<<abs->personArray[find].m_phone<<"\t";
        cout<<"��ͥסַ�� "<<abs->personArray[find].m_address<<endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyPerson(Addressbook *abs){
string name;
	cout<<"�������޸���ϵ�������� "<<endl;
	cin>>name;
	int mod=Exist(abs,name);
	if (mod==-1){
	cout<<"�޴���ϵ��"<<endl;
	}
	else{
	cout<<"�Ա� "<<endl;
	int sex;
	cin>>sex;
	abs->personArray[mod].m_sex=sex;
	cout<<"���䣺 "<<endl;
	int age;
	cin>>age;
	abs->personArray[mod].m_age=age;
	cout<<"�绰���룺  "<<endl;
	int phone;
	cin>>phone;
	abs->personArray[mod].m_phone=phone;
	cout<<"��ͥסַ��  "<<endl;
	string add;
	cin>>add;
	abs->personArray[mod].m_address=add;
	
	cout<<"�޸ĳɹ���"<<endl;

	}
system("pause");
	system("cls");
}

//�����ϵ�ˣ��������������߼��ϵ����
void cleanPerson(Addressbook *abs){
    cout<<"ȷ����գ�"<<endl;
	cout<<"1. ��" <<endl;
	cout<<"2. ��"<<endl;
	int con=0;
	cin>>con;
	if(con==1){
		abs->size_m=0;
		cout<<"�����ͨѶ¼"<<endl;
	}
	system("pause");
	system("cls");
}

int main(){
//��ʾ�˵�
	int select=0;
	struct Addressbook abs;
	abs.size_m=0;
//�û����룬ѭ��ʹ��ֱ���û��˳�	
	
	while(true){
		showMenu();
		cin>>select;
	switch(select){
case 1:addPerson( &abs);//��ַ���ݷ����Ա��޸�ʵ�Σ��޸�abs�Լ�����ϵ��

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
case 0:  cout<<"��ӭ�´�ʹ��"<<endl;
		system("pause");
		return 0;
default:
		break;
	}
}
system("pause");
		
		return 0;	

}

