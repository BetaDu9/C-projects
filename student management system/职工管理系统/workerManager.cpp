#include <iostream>
#include <string>
using namespace std;
#include "worker manager.h"
#include "manager.h"
#include "Employee.h"
#include "boss.h"

workerManager::workerManager(){
	//初始化成员属性
	//1.未创建文件
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if(!ifs.is_open()){

	cout<<"文件不存在"<<endl;
	this->m_FileisEmpty=true;
	this->m_PerNum=0;//初始化职工数
	this->m_PerArr=NULL;//初始化职工数组指针
	ifs.close();
	return;
	}

	//2.文件为空
	char c;
	ifs>>c;
	   //读入为文件尾，end of file
	if(ifs.eof()){
	
	cout<<"文件为空"<<endl;
	this->m_FileisEmpty=true;
	this->m_PerNum=0;//初始化职工数
	this->m_PerArr=NULL;//初始化职工数组指针
	ifs.close();
	return;
	}

//3.文件不为空
	int num=this->getNum();
	cout<<"职工人数："<<num<<endl;
	this->m_PerNum=num;
	this->m_FileisEmpty=false;
	//初始化职工数组
	   //开辟新空间
	this->m_PerArr=new worker*[this->m_PerNum];
	   //将文件中的数据存到数组中
	this->init();
	   //输出数组中的数据
	for(int i=0;i<this->m_PerNum;i++){
		cout<<"员工编号："<<this->m_PerArr[i]->m_id  <<" "
		   <<"员工姓名："<<this->m_PerArr[i]->m_name<<" "
		   <<"部门编号："<<this->m_PerArr[i]->m_dId <<endl;
	}

}

//初始化员工
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
		  //将文件中保存的数据放到数组中来，初始化数组
		  this->m_PerArr[index]=worker;
		  index++;
	  }
	ifs.close();
	
	}



//获取现有职工人数
	int workerManager::getNum(){
//创建文件流
	  ifstream ifs;
	//打开文件
	  ifs.open(FILENAME,ios::in);
	  int id;
	  string name;
	  int dId;

	  int num=0;
	     while(ifs>>id&&ifs>>name&&ifs>>dId){
			 //读一行记录一次人数
	        num++;
	        }
		 ifs.close();
	return num;
	}


//菜单显示实现
	//类外实现类中所声明的函数
	void workerManager::showMenu(){       
	cout<<"****欢迎使用职工管理系统****"<<endl;
	cout<<"****************************"<<endl;
	cout<<"*****0.退出职工管理系统*****"<<endl;
	cout<<"*******1.添加职工信息*******"<<endl;
	cout<<"*******2.显示职工信息*******"<<endl;
	cout<<"*******3.删除职工信息*******"<<endl;
	cout<<"*******4.修改职工信息*******"<<endl;
	cout<<"*******5.查找职工信息*******"<<endl;
	cout<<"*******6.按照编号排序*******"<<endl;
	cout<<"*******7.清空职工信息*******"<<endl;
	cout<<"****************************"<<endl;
	}


//添加职工实现
	void workerManager::addPerson(){
   //输入添加人数，判断输入是够正确
		int addNum=0;
	     cout<<"请输入添加人数："<<endl;
		cin>>addNum;
		if(addNum>0){
	//重写职工指针数组
		//计算新空间大小
			int arrSize=this->m_PerNum+addNum;
        //创造新空间 
			worker** Space= new worker*[arrSize];//堆区创建数组
	//若原数组不为空，将数组原有数据拷贝入新空间
			if(this->m_PerNum !=0){
			   for(int i=0;i<this->m_PerNum;i++){
				 Space[i]=this->m_PerArr[i];
			   }
			}
	//批量添加新数据
		for(int i=0;i<addNum;i++){
			int id;
			string name;
			int dId;

		 //提示用户输入新职工
			cout<<"请输入第"<<i+1<<"名职工编号："<<endl;
			cin>>id;
			cout<<"请输入第"<<i+1<<"名职工姓名："<<endl;
			cin>>name;
			cout<<"请选择新职工部门编号："<<endl;
			cout<<"1. 员工"<<endl;
			cout<<"2. 经理"<<endl;
			cout<<"3. 老板"<<endl;
			cin>>dId;
			
			//根据不同选项创建不同worker*
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
			//将新职工指针放入新空间中	
			Space[i+this->m_PerNum]=worker;
			//更新文件为空指针为假
			this->m_FileisEmpty=false;
			
			}
		//释放原有数组空间
		delete[] this->m_PerArr;

		//修改新空间指针指向
		this->m_PerArr=Space;

		//更新职工人数
		this->m_PerNum=arrSize;
        this->save();
		cout<<"成功添加"<<addNum<<"名新职工！"<<endl;
		
		}

		else{
		cout<<"输入错误！"<<endl;
		}		
system("pause");
system("cls");
	}


//保存文件的实现
	void workerManager::save(){
	ofstream ofs;
	//以输出方式打开文件，写操作
	ofs.open(FILENAME,ios::out);
	//写入
	for(int i=0;i<this->m_PerNum;i++){
		ofs<<this->m_PerArr[i]->m_id  <<" "
		  <<this->m_PerArr[i]->m_name<<" "
		  <<this->m_PerArr[i]->m_dId <<endl;
	}
	//关闭文件
	ofs.close();
	
	}

//显示员工
	void workerManager::showPerson(){
		if(this->m_FileisEmpty){
		  cout<<"无职工数据！"<<endl;
		
		}
		else{
			for(int i=0;i<this->m_PerNum;i++){
			//利用多态调用接口
	    	this->m_PerArr[i]->showInfo();
			}
		}
		system("pause");
        system("cls");
	}


//删除员工
	void workerManager::deletePer(){
	    if(this->m_FileisEmpty){
		  cout<<"无职工数据！"<<endl;
		
		}
		else {
		int ID;
		cout<<"请输入要删除的员工编号："<<endl;
		cin>>ID;
		for(int i=0;i<this->m_PerNum;i++){
			if(ID==this->m_PerArr[i]->m_id){
		            for(int j=i;j<this->m_PerNum-1;j++){
					this->m_PerArr[j]=this->m_PerArr[j+1];
			     }
				this->m_PerNum--;
				this->save();
				cout<<"删除成功！"<<endl;
				if(this->m_PerNum==0){
				   this->m_FileisEmpty=true;
				}
				break;
			}
			else{
				cout<<"不存在该员工！"<<endl;
			}
		
		}
		}
system("pause");
system("cls");
	}


//修改职工
	void workerManager::modPerson(){
	    if(this->m_FileisEmpty){
		  cout<<"无职工数据！"<<endl;
		
		}
		else {
			int mod;
	       cout<<"请输入要修改的员工编号："<<endl;
		   cin>>mod;
		   for(int i=0;i<this->m_PerNum;i++){
		     if(mod==this->m_PerArr[i]->m_id){
				 //提示用户进行修改
				 string mod_name;
				 int mod_dId;
				cout<<"请输入修改后的员工姓名："<<endl; 
				cin>>mod_name;
				cout<<"请输入修改后的员工部门编号："<<endl; 
				cin>>mod_dId;
			  //将修改后员工信息放入
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
				cout<<"修改员工"<<mod<<"号成功！"<<endl;
				break;

		   }
			 else{
			   cout<<"不存在该员工！"<<endl;
			 }

		   }
		}
		system("pause");
system("cls");
	}


//查找职工
	void workerManager::search(){
	   
		 if(this->m_FileisEmpty){
		   cout<<"无职工数据！"<<endl;
		
		}
		else {
			int sel;
			cout<<"请选择查找方式："<<endl;
			cout<<"1.按姓名方式查找"<<endl;
			cout<<"2.按员工编号查找"<<endl;
			cin>>sel;
		switch(sel){
		//按姓名查找
		case 1:
		{
			string name;
		cout<<"请输入要查找的员工姓名："<<endl;
		cin>>name;
		bool flag=false;//判断是否找到该员工

		for(int i=0;i<this->m_PerNum;i++){
			if(name==this->m_PerArr[i]->m_name){
				this->m_PerArr[i]->showInfo();
				flag=true;	
			}
		}
				//利用flag避免使用if else重复输出未找到该员工
				if(flag==false){ 
				cout<<"未找到该员工！"<<endl;	
		               }
				break;
		}
		case 2://按员工编号查找
			{
			int id;
		cout<<"请输入要查找的员工编号："<<endl;
		cin>>id;
		bool flag=false;

		for(int i=0;i<this->m_PerNum;i++){
			if(id==this->m_PerArr[i]->m_id){
				this->m_PerArr[i]->showInfo();
				flag=true;	
			}
		}
				
				if(flag==false){ 
				cout<<"未找到该员工！"<<endl;	
		               }
			
			break;
			}
	}
		}
system("pause");
system("cls");
}


//清空职工列表
	void workerManager::clear(){
		 if(this->m_FileisEmpty){
		   cout<<"无职工数据！"<<endl;
		
		}
		else {
	int cl_sel;
    cout<<"是否确认清空？"<<endl;
	cout<<"1.是"<<endl;
	cout<<"2.否"<<endl;
	cin>>cl_sel;
	switch(cl_sel){
	case 1:this->m_PerNum=0;
		   this->m_PerArr=NULL;
		   this->m_FileisEmpty=true;
		   save();
		   cout<<"已清空职工列表！"<<endl;
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

//析构函数实现,手动释放堆区数据
workerManager::~workerManager(){
	if(this->m_PerArr !=NULL){
		delete[] this->m_PerArr;//删除数组需要加[]
		//this->m_PerArr=NULL;
	}
}






