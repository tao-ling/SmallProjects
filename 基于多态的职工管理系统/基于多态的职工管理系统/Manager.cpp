#define _CRT_SECURE_NO_WARNINGS 1
#include "Manager.h"

Manager::Manager(int id, string name, int deptid)
{
	m_id = id;
	m_name = name;
	m_deptid = deptid;
}
void Manager::ShowInfo()
{
	cout << "员工的编号为：\t" << this->m_id
		<< "\t职工的名字：" << this->m_name
		<< "\t岗位：" << this->GetDeptName()
		<< "\t岗位职责：完成老板交给的任务，并将任务分配给下面的员工" << endl;
}
string Manager::GetDeptName()
{
	return string("经理");
}