#pragma once	
#include <iostream>
#include <fstream>
#include "Worker.h"
#define FILENAME "EmpFile.txt"
using namespace std;

class WorkManager
{
public:
	WorkManager();
	void ShowMenu();//菜单展示
	void ExitSystem();//退出程序
	void AddEmp();//添加成员
	void save();//保存文件
	int GetEmpNum();//统计人数
	void InitEmp();//初始化职工
	void ShowEmp();//显示职工信息
	void DelEmp();//删除职工
	int IsExist(int deptid);//按照编号判断职工是否存在；如果存在，返回职工在数组中的编号；如果不存在，返回-1
	void ModEmp();//修改职工信息
	void FindEmp();//查找职工
	void SortEmp();//排序职工
	void CleanFile();//清空文件
	~WorkManager();

	int m_empnum;//记录文件中的人数
	Worker** m_emparray;//员工数组指针
	bool m_FileIsEmpty;//标志文件是否为空
};