#define _CRT_SECURE_NO_WARNINGS 1
#include "Boss.h"

Boss::Boss(int id, string name, int deptid)
{
	m_id = id;
	m_name = name;
	m_deptid = deptid;
}

void Boss::ShowInfo()
{
	cout << "员工的编号为：\t" << this->m_id
		<< "\t职工的名字：" << this->m_name
		<< "\t岗位：" << this->GetDeptName()
		<< "\t岗位职责：完成公司内的各种大小问题" << endl;
}

string Boss::GetDeptName()
{
	return string("总裁");
}