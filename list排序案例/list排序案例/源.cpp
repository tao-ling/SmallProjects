#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <list>

class Person
{
public:
	Person(string name, int age, int height)
	{
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}
	string m_Name;
	int m_Age;
	int m_Height;
};

//按照年龄进行升序，如果年龄相同按照身高进行降序
int MyCompare(Person& p1, Person& p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	return p1.m_Age < p2.m_Age;
}

void PrintList(const list<Person>& L)
{
	for (list<Person>::const_iterator it = L.begin(); 
		it != L.end(); 
		it++)
	{
		cout << "姓名：" << it->m_Name 
			<< " 年龄：" << it->m_Age 
			<< " 身高：" << it->m_Height << endl;
	}
}

void test()
{
	list<Person> L;
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	
	cout << "排序前：" << endl;
	PrintList(L);
	cout << "--------------------" << endl;

	L.sort(MyCompare);
	PrintList(L);
}

int main()
{
	test();
	system("pause");
	return 0;
}