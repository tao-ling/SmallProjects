#pragma once
#include "Worker.h"

class Manager :public Worker
{
public:
	Manager(int id, string name, int deptid);
	virtual void ShowInfo();
	virtual string GetDeptName();
};