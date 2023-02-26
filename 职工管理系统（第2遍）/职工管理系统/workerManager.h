#pragma once
#include <iostream>
#include <fstream>
#include "worker.h"
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单
	void showMenu();

	//退出程序
	void exitSystem();

	//增加职工
	void addEmp();

	//保存文件
	void save();

	//统计人数
	int getEmpNum();

	//初始化员工
	void initEmp();

	//显示职工
	void showEmp();

	//删除职工
	void delEmp();

	//公告函数
	//按照职工编号判断职工是否存在，若存在就返回职工在数组的位置，不存在就返回-1
	int isExist(int id);

	//修改职工
	void modEmp();

	//查找职工
	void findEmp();

	//排序职工
	void sortEmp();

	//清空文件
	void cleanFile();

	//析构函数
	~WorkerManager();

public:
	int m_EmpNum;		//记录文件中的人数
	Worker** m_EmpArray;//员工数组的指针
	bool m_FileIsEmpty;	//标志文件是否为空
};