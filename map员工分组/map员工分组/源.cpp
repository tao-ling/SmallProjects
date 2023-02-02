#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <ctime>
#include <map>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Person
{
public:
	string m_Name;
	int m_Salary;
};

void CreateWorker(vector<Person> &vWorker)
{
	string NameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Person worker;
		worker.m_Name = "员工";
		worker.m_Name += NameSeed[i];
		worker.m_Salary = rand() % 10000 + 10000;
		vWorker.push_back(worker);
	}
}

void SetGroup(vector<Person>& vWorker, multimap<int, Person>& mWorker)
{
	for (vector<Person>::iterator it = vWorker.begin();
		it != vWorker.end();
		it++)
	{
		mWorker.insert(make_pair(rand() % 3, *it));
	}
}

void ShowGroup(const multimap<int, Person>& mWorker)
{
	//策划部门
	cout << "策划部门：" << endl;
	int count = mWorker.count(CEHUA);
	int num = 0;
	for (multimap<int, Person>::const_iterator pos = mWorker.find(CEHUA);
		pos != mWorker.end()&&num < count;
		num++, pos++)
	{
		cout << "name:" << pos->second.m_Name <<
			"  salary:" << pos->second.m_Salary << endl;
	}
	cout << endl;

	//美术部门
	cout << "美术部门：" << endl;
	count = mWorker.count(MEISHU);
	num = 0;
	for (multimap<int, Person>::const_iterator pos = mWorker.find(MEISHU);
		pos != mWorker.end()&&num < count;
		num++, pos++)
	{
		cout << "name:" << pos->second.m_Name <<
			"  salary:" << pos->second.m_Salary << endl;
	}
	cout << endl;

	//研发部门
	cout << "研发部门：" << endl;
	count = mWorker.count(YANFA);
	num = 0;
	for (multimap<int, Person>::const_iterator pos = mWorker.find(YANFA);
		pos != mWorker.end()&&num < count;
		num++, pos++)
	{
		cout << "name:" << pos->second.m_Name <<
			"  salary:" << pos->second.m_Salary << endl;
	}
	cout << endl;
}

int main()
{
	srand((unsigned int)time(NULL));
	//创建职工
	vector<Person> vWorker;
	CreateWorker(vWorker);
	//测试代码
	/*for (vector<Person>::iterator it = vWorker.begin();
		it != vWorker.end();
		it++)
	{
		cout << "name:" << it->m_Name << "    age:" << it->m_Salary <<endl;
	}*/

	//给员工分组
	multimap<int, Person> mWorker;
	SetGroup(vWorker, mWorker);

	//展示员工的分组及信息
	ShowGroup(mWorker);

	system("pause");
	return 0;
}