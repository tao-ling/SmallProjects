#define _CRT_SECURE_NO_WARNINGS 1
#include "WorkManager.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

WorkManager::WorkManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	//文件不存在的情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_FileIsEmpty = true;
		this->m_empnum = 0;//初始化人数
		this->m_emparray = NULL;//初始化数组指针
		ifs.close();
		return;
	}

	//文件存在但为空的情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_FileIsEmpty = true;
		this->m_empnum = 0;//初始化人数
		this->m_emparray = NULL;//初始化数组指针
		ifs.close();
		return;
	}

	//文件存在且有数据
	this->m_empnum = this->GetEmpNum();
	//cout << "职工人数为：" << this->m_empnum << endl;//测试代码
	this->m_emparray = new Worker * [this->m_empnum];
	this->InitEmp();

	////测试代码
	//for (int i = 0; i < this->m_empnum; i++)
	//{
	//	cout << "职工号为：" << this->m_emparray[i]->m_id
	//		<< "职工姓名为：" << this->m_emparray[i]->m_name
	//		<< "部门编号为：" << this->m_emparray[i]->m_deptid << endl;
	//}
}

void WorkManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkManager::ExitSystem()
{
	cout << "欢迎你的下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkManager::AddEmp()
{
	cout << "请输入增加员工数量：" << endl;
	int add_num = 0;
	cin >> add_num;
	if (add_num > 0)
	{
		//计算新空间的大小
		int new_size = this->m_empnum + add_num;

		//开辟新空间
		Worker** new_space = new Worker*[new_size];

		//将原来空间下的内容存放到新的空间中
		if (this->m_emparray != NULL)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				new_space[i] = this->m_emparray[i];
			}
		}

		//输入数据
		for (int i = 0; i < add_num; i++)
		{
			int id = 0;
			string name;
			int deptid = 0;
			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个新职工岗位" << endl;
			cout << "1 普通职工" << endl;
			cout << "2 经理" << endl;
			cout << "3 老板" << endl;
			cin >> deptid;

			Worker* worker = NULL;
			switch (deptid)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			new_space[this->m_empnum + i] = worker;
		}
		delete[] this->m_emparray;//释放原有空间
		this->m_emparray = new_space;//更新新的空间指向
		this->m_empnum = new_size;//更新新的个数
		this->m_FileIsEmpty = false;//更新职工不为空标志
		cout << "成功添加" << add_num << " 名新职工" << endl;
		this->save();
	}
	else
	{
		cout << "输入的数字有误" << endl;
	}
	system("pause");
	system("cls");
}

void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); // 用输出的方式打开文件  -- 写文件

	//将每个人数据写入到文件中
	for (int i = 0; i < this->m_empnum; i++)
	{
		ofs << this->m_emparray[i]->m_id << " "
			<< this->m_emparray[i]->m_name << " "
			<< this->m_emparray[i]->m_deptid << endl;
	}

	//关闭文件
	ofs.close();

}

int WorkManager::GetEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int deptid;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		num++;
	}
	ifs.close();
	return num;
}

void WorkManager::InitEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int deptid;
	int idex = 0;
	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		Worker* worker = NULL;
		//根据不同的部门id创建不同的对象
		if (deptid == 1)
		{
			worker = new Employee(id, name, deptid);
		}
		else if (deptid == 2)
		{
			worker = new Manager(id, name, deptid);
		}
		else
		{
			worker = new Boss(id, name, deptid);
		}
		//存放到数组中
		this->m_emparray[idex] = worker;
		idex++;
	}
}

void WorkManager::ShowEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_empnum; i++)
		{
			//利用多态调用接口
			this->m_emparray[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}

int WorkManager::IsExist(int deptid)
{
	int index = -1;
	for (int i = 0; i < this->m_empnum; i++)
	{
		if (this->m_emparray[i]->m_id == deptid)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkManager::DelEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入你想删掉的职工号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_empnum - 1; i++)
			{
				this->m_emparray[i] = this->m_emparray[i + 1];
			}
			this->m_empnum--;
			if (this->m_empnum == 0)
			{
				this->m_FileIsEmpty = true;
			}
			this->save();//删除时候同步数据到文件中
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未能找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkManager::ModEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//查找到编号的职工
			delete this->m_emparray[ret];
			int new_id = 0;
			string new_name = "";
			int new_deptid = 0;
			cout << "查到： " << id << "号职工，请输入新职工号：" << endl;
			cin >> new_id;
			cout << "请输入新名字： " << endl;
			cin >> new_name;
			cout << "请输入岗位：" << endl;
			cout << "1 普通职工" << endl;
			cout << "2 经理" << endl;
			cout << "3 老板" << endl;
			cin >> new_deptid;
			Worker* worker = NULL;
			switch (new_deptid)
			{
			case 1:
				worker = new Employee(new_id, new_name, new_deptid);
				break;
			case 2:
				worker = new Manager(new_id, new_name, new_deptid);
				break;
			case 3:
				worker = new Boss(new_id, new_name, new_deptid);
				break;
			default:
				break;
			}
			//更改数据到数组中
			this->m_emparray[ret] = worker;
			cout << "修改成功" << endl;
			//保存到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkManager::FindEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式" << endl;
		cout << "1 按照职工的编号查找" << endl;
		cout << "2 按照姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)//按照职工号查找
		{
			int id;
			cout << "请输入你想查找的职工编号： " << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功，该职工的信息如下：" << endl;
				this->m_emparray[ret]->ShowInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入你想查找的职工姓名：" << endl;
			cin >> name;
			bool flag = false;//查找到的标志
			for (int i = 0; i < this->m_empnum; i++)
			{
				if (m_emparray[i]->m_name == name)
				{
					cout << "查找成功，职工编号为" << m_emparray[i]->m_id << "号的信息如下：" << endl;
					flag = true;
					this->m_emparray[i]->ShowInfo();
				}
			}
			if (flag == false)
			{
				//查无此人
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkManager::SortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		//分布排序
		cout << "请选择排序方式：" << endl;
		cout << "1 按照职工号进行升序" << endl;
		cout << "2 按照职工号进行降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_empnum; i++)
		{
			int min_or_max = i;
			for (int j = i + 1; j < m_empnum; j++)
			{
				if (select == 1)//升序
				{
					if (m_emparray[min_or_max]->m_id > m_emparray[j]->m_id)
					{
						min_or_max = j;
					}
				}
				else//降序
				{
					if (m_emparray[min_or_max]->m_id < m_emparray[j]->m_id)
					{
						min_or_max = j;
					}
				}
			}
			if (i != min_or_max)
			{
				Worker* temp = m_emparray[i];
				m_emparray[i] = m_emparray[min_or_max];
				m_emparray[min_or_max] = temp;
			}
		}
		cout << "排序成功，排序后的结果：" << endl;
		this->save();
		this->ShowEmp();
	}
}

void WorkManager::CleanFile()
{
	cout << "确定清空文件？" << endl;
	cout << "1 确定" << endl;
	cout << "2 返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//打开模式：ios::trunc如果存在则删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_emparray != NULL)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				if (this->m_emparray[i] != NULL)
				{
					delete this->m_emparray[i];
					this->m_emparray[i] = NULL;
				}
			}
			this->m_empnum = 0;
			delete[] this->m_emparray;
			this->m_emparray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

WorkManager::~WorkManager()
{
	if (this->m_emparray != NULL)
	{
		for (int i = 0; i < this->m_empnum; i++)
		{
			if (this->m_emparray[i] != NULL)
			{
				delete this->m_emparray[i];
				this->m_emparray[i] = NULL;
			}
		}
		this->m_empnum = 0;
		delete[] this->m_emparray;
		this->m_emparray = NULL;
		this->m_FileIsEmpty = true;
	}
}