#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <time.h>
#include <algorithm>

class Person
{
public:
	Person(string name, int score)
	{
		m_Name = name;
		m_Score = score;
	}
	string m_Name;
	int m_Score;
};

void ShowScore(const vector<Person>& v)
{
	for (vector<Person>::const_iterator it = v.begin();
		it != v.end();
		it++)
	{
		cout << it->m_Name << " 的平均成绩：" << it->m_Score << endl;
	}
}

//创建Person的类
void CreatePerson(vector<Person>& v)
{
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		string letter = "ABCDE";
		name += letter[i];
		int score = 0;
		Person person(name, score);
		v.push_back(person);
	}
	//测试代码
	//ShowScore(v);
}

void SetScore(vector<Person>& v)
{
	for (int i = 0; i < 5; i++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			d.push_back(rand() % 41 + 60);
		}
		////测试代码
		//for (deque<int>::iterator it = d.begin();
		//	it != d.end();
		//	it++)
		//{
		//	cout << *it << " ";
		//}
		//cout << endl;
		sort(d.begin(), d.end());
		d.pop_front();
		d.pop_back();
		////测试代码
		//for (deque<int>::iterator it = d.begin(); 
		//		it != d.end(); 
		//		it++)
		//{
		//	cout << *it << " ";
		//}
		//cout << endl;
		int sum = 0;
		for (deque<int>::iterator it = d.begin();
			it != d.end();
			it++)
		{
			sum += *it;
		}
		int score = sum / d.size();
		v[i].m_Score = score;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	//1、创建选手的vector数组
	vector<Person> v;
	CreatePerson(v);
	//2、创建选手得分的deque数组
	SetScore(v);
	//3、显示最后得分
	ShowScore(v);

	system("pause");
	return 0;
}