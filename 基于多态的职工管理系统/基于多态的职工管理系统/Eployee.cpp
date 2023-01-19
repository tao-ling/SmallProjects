#define _CRT_SECURE_NO_WARNINGS 1
#include "Employee.h"
using namespace std;

Employee::Employee(int id, string name, int deptid)
{
	m_id = id;
	m_name = name;
	m_deptid = deptid;
}

void Employee::ShowInfo()
{
	cout << "员工的编号为：\t" << this->m_id
		<< "\t职工的名字：" << this->m_name
		<< "\t岗位：" << this->GetDeptName()
		<< "\t岗位职责：完成经理交给的任务" << endl;
}

string Employee::GetDeptName()
{
	return string("员工");
}