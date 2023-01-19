#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:
	virtual void ShowInfo() = 0;//显示职工信息
	virtual string GetDeptName() = 0;//获取职工部门信息

	int m_id;//职工编号
	string m_name;//职工名字
	int m_deptid;//职工所在部门的编号
};