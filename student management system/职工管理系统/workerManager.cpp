#include <iostream>
#include <string>
using namespace std;
#include "worker manager.h"
#include "manager.h"
#include "Employee.h"
#include "boss.h"

workerManager::workerManager(){
	//��ʼ����Ա����
	//1.δ�����ļ�
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if(!ifs.is_open()){

	cout<<"�ļ�������"<<endl;
	this->m_FileisEmpty=true;
	this->m_PerNum=0;//��ʼ��ְ����
	this->m_PerArr=NULL;//��ʼ��ְ������ָ��
	ifs.close();
	return;
	}

	//2.�ļ�Ϊ��
	char c;
	ifs>>c;
	   //����Ϊ�ļ�β��end of file
	if(ifs.eof()){
	
	cout<<"�ļ�Ϊ��"<<endl;
	this->m_FileisEmpty=true;
	this->m_PerNum=0;//��ʼ��ְ����
	this->m_PerArr=NULL;//��ʼ��ְ������ָ��
	ifs.close();
	return;
	}

//3.�ļ���Ϊ��
	int num=this->getNum();
	cout<<"ְ��������"<<num<<endl;
	this->m_PerNum=num;
	this->m_FileisEmpty=false;
	//��ʼ��ְ������
	   //�����¿ռ�
	this->m_PerArr=new worker*[this->m_PerNum];
	   //���ļ��е����ݴ浽������
	this->init();
	   //��������е�����
	for(int i=0;i<this->m_PerNum;i++){
		cout<<"Ա����ţ�"<<this->m_PerArr[i]->m_id  <<" "
		   <<"Ա��������"<<this->m_PerArr[i]->m_name<<" "
		   <<"���ű�ţ�"<<this->m_PerArr[i]->m_dId <<endl;
	}

}

//��ʼ��Ա��
	void workerManager::init(){
	   ifstream ifs;
	   ifs.open(FILENAME,ios::in);
	   
	   int id;
	   string name;
	   int dId;

	   worker* worker=NULL;
	  int index=0;
	  while(ifs>>id && ifs>>name && ifs>>dId){
		  if(dId==1){
		    worker=new Employee(id,name,dId);
		  }
		  else if(dId==2){
		    worker=new Manager(id,name,dId);
		  }
		  else if (dId==3){
		    worker=new Boss(id,name,dId);
		  }   
		  //���ļ��б�������ݷŵ�������������ʼ������
		  this->m_PerArr[index]=worker;
		  index++;
	  }
	ifs.close();
	
	}



//��ȡ����ְ������
	int workerManager::getNum(){
//�����ļ���
	  ifstream ifs;
	//���ļ�
	  ifs.open(FILENAME,ios::in);
	  int id;
	  string name;
	  int dId;

	  int num=0;
	     while(ifs>>id&&ifs>>name&&ifs>>dId){
			 //��һ�м�¼һ������
	        num++;
	        }
		 ifs.close();
	return num;
	}


//�˵���ʾʵ��
	//����ʵ�������������ĺ���
	void workerManager::showMenu(){       
	cout<<"****��ӭʹ��ְ������ϵͳ****"<<endl;
	cout<<"****************************"<<endl;
	cout<<"*****0.�˳�ְ������ϵͳ*****"<<endl;
	cout<<"*******1.���ְ����Ϣ*******"<<endl;
	cout<<"*******2.��ʾְ����Ϣ*******"<<endl;
	cout<<"*******3.ɾ��ְ����Ϣ*******"<<endl;
	cout<<"*******4.�޸�ְ����Ϣ*******"<<endl;
	cout<<"*******5.����ְ����Ϣ*******"<<endl;
	cout<<"*******6.���ձ������*******"<<endl;
	cout<<"*******7.���ְ����Ϣ*******"<<endl;
	cout<<"****************************"<<endl;
	}


//���ְ��ʵ��
	void workerManager::addPerson(){
   //��������������ж������ǹ���ȷ
		int addNum=0;
	     cout<<"���������������"<<endl;
		cin>>addNum;
		if(addNum>0){
	//��дְ��ָ������
		//�����¿ռ��С
			int arrSize=this->m_PerNum+addNum;
        //�����¿ռ� 
			worker** Space= new worker*[arrSize];//������������
	//��ԭ���鲻Ϊ�գ�������ԭ�����ݿ������¿ռ�
			if(this->m_PerNum !=0){
			   for(int i=0;i<this->m_PerNum;i++){
				 Space[i]=this->m_PerArr[i];
			   }
			}
	//�������������
		for(int i=0;i<addNum;i++){
			int id;
			string name;
			int dId;

		 //��ʾ�û�������ְ��
			cout<<"�������"<<i+1<<"��ְ����ţ�"<<endl;
			cin>>id;
			cout<<"�������"<<i+1<<"��ְ��������"<<endl;
			cin>>name;
			cout<<"��ѡ����ְ�����ű�ţ�"<<endl;
			cout<<"1. Ա��"<<endl;
			cout<<"2. ����"<<endl;
			cout<<"3. �ϰ�"<<endl;
			cin>>dId;
			
			//���ݲ�ͬѡ�����ͬworker*
			worker* worker=NULL;
			switch(dId){
			case 1: worker= new Employee(id,name,dId);
				  break;
			case 2: worker= new Manager(id,name,dId);
				 break;
			case 3: worker= new Boss(id,name,dId);
				 break;
			default:
				break;
			}
			//����ְ��ָ������¿ռ���	
			Space[i+this->m_PerNum]=worker;
			//�����ļ�Ϊ��ָ��Ϊ��
			this->m_FileisEmpty=false;
			
			}
		//�ͷ�ԭ������ռ�
		delete[] this->m_PerArr;

		//�޸��¿ռ�ָ��ָ��
		this->m_PerArr=Space;

		//����ְ������
		this->m_PerNum=arrSize;
        this->save();
		cout<<"�ɹ����"<<addNum<<"����ְ����"<<endl;
		
		}

		else{
		cout<<"�������"<<endl;
		}		
system("pause");
system("cls");
	}


//�����ļ���ʵ��
	void workerManager::save(){
	ofstream ofs;
	//�������ʽ���ļ���д����
	ofs.open(FILENAME,ios::out);
	//д��
	for(int i=0;i<this->m_PerNum;i++){
		ofs<<this->m_PerArr[i]->m_id  <<" "
		  <<this->m_PerArr[i]->m_name<<" "
		  <<this->m_PerArr[i]->m_dId <<endl;
	}
	//�ر��ļ�
	ofs.close();
	
	}

//��ʾԱ��
	void workerManager::showPerson(){
		if(this->m_FileisEmpty){
		  cout<<"��ְ�����ݣ�"<<endl;
		
		}
		else{
			for(int i=0;i<this->m_PerNum;i++){
			//���ö�̬���ýӿ�
	    	this->m_PerArr[i]->showInfo();
			}
		}
		system("pause");
        system("cls");
	}


//ɾ��Ա��
	void workerManager::deletePer(){
	    if(this->m_FileisEmpty){
		  cout<<"��ְ�����ݣ�"<<endl;
		
		}
		else {
		int ID;
		cout<<"������Ҫɾ����Ա����ţ�"<<endl;
		cin>>ID;
		for(int i=0;i<this->m_PerNum;i++){
			if(ID==this->m_PerArr[i]->m_id){
		            for(int j=i;j<this->m_PerNum-1;j++){
					this->m_PerArr[j]=this->m_PerArr[j+1];
			     }
				this->m_PerNum--;
				this->save();
				cout<<"ɾ���ɹ���"<<endl;
				if(this->m_PerNum==0){
				   this->m_FileisEmpty=true;
				}
				break;
			}
			else{
				cout<<"�����ڸ�Ա����"<<endl;
			}
		
		}
		}
system("pause");
system("cls");
	}


//�޸�ְ��
	void workerManager::modPerson(){
	    if(this->m_FileisEmpty){
		  cout<<"��ְ�����ݣ�"<<endl;
		
		}
		else {
			int mod;
	       cout<<"������Ҫ�޸ĵ�Ա����ţ�"<<endl;
		   cin>>mod;
		   for(int i=0;i<this->m_PerNum;i++){
		     if(mod==this->m_PerArr[i]->m_id){
				 //��ʾ�û������޸�
				 string mod_name;
				 int mod_dId;
				cout<<"�������޸ĺ��Ա��������"<<endl; 
				cin>>mod_name;
				cout<<"�������޸ĺ��Ա�����ű�ţ�"<<endl; 
				cin>>mod_dId;
			  //���޸ĺ�Ա����Ϣ����
			  worker* worker=NULL;
			if(mod_dId==1){
		        worker=new Employee(mod,mod_name,mod_dId);
		         }
		    else if(mod_dId==2){
		        worker=new Manager(mod,mod_name,2);
		         }
		    else if (mod_dId==3){
		        worker=new Boss(mod,mod_name,3);
		         }   
		  
		  this->m_PerArr[mod]=worker;
				this->save();
				cout<<"�޸�Ա��"<<mod<<"�ųɹ���"<<endl;
				break;

		   }
			 else{
			   cout<<"�����ڸ�Ա����"<<endl;
			 }

		   }
		}
		system("pause");
system("cls");
	}


//����ְ��
	void workerManager::search(){
	   
		 if(this->m_FileisEmpty){
		   cout<<"��ְ�����ݣ�"<<endl;
		
		}
		else {
			int sel;
			cout<<"��ѡ����ҷ�ʽ��"<<endl;
			cout<<"1.��������ʽ����"<<endl;
			cout<<"2.��Ա����Ų���"<<endl;
			cin>>sel;
		switch(sel){
		//����������
		case 1:
		{
			string name;
		cout<<"������Ҫ���ҵ�Ա��������"<<endl;
		cin>>name;
		bool flag=false;//�ж��Ƿ��ҵ���Ա��

		for(int i=0;i<this->m_PerNum;i++){
			if(name==this->m_PerArr[i]->m_name){
				this->m_PerArr[i]->showInfo();
				flag=true;	
			}
		}
				//����flag����ʹ��if else�ظ����δ�ҵ���Ա��
				if(flag==false){ 
				cout<<"δ�ҵ���Ա����"<<endl;	
		               }
				break;
		}
		case 2://��Ա����Ų���
			{
			int id;
		cout<<"������Ҫ���ҵ�Ա����ţ�"<<endl;
		cin>>id;
		bool flag=false;

		for(int i=0;i<this->m_PerNum;i++){
			if(id==this->m_PerArr[i]->m_id){
				this->m_PerArr[i]->showInfo();
				flag=true;	
			}
		}
				
				if(flag==false){ 
				cout<<"δ�ҵ���Ա����"<<endl;	
		               }
			
			break;
			}
	}
		}
system("pause");
system("cls");
}


//���ְ���б�
	void workerManager::clear(){
		 if(this->m_FileisEmpty){
		   cout<<"��ְ�����ݣ�"<<endl;
		
		}
		else {
	int cl_sel;
    cout<<"�Ƿ�ȷ����գ�"<<endl;
	cout<<"1.��"<<endl;
	cout<<"2.��"<<endl;
	cin>>cl_sel;
	switch(cl_sel){
	case 1:this->m_PerNum=0;
		   this->m_PerArr=NULL;
		   this->m_FileisEmpty=true;
		   save();
		   cout<<"�����ְ���б�"<<endl;
		break;
	case 2:
		break;
	default:
		break;
	
	}
		}

	system("pause");
		   system("cls");
	
	
	
	}

//��������ʵ��,�ֶ��ͷŶ�������
workerManager::~workerManager(){
	if(this->m_PerArr !=NULL){
		delete[] this->m_PerArr;//ɾ��������Ҫ��[]
		//this->m_PerArr=NULL;
	}
}






