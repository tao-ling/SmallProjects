#define _CRT_SECURE_NO_WARNINGS 1
#include "WorkManager.h"
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

int main()
{	//测试代码
	//	Worker* worker = new Employee(1, "张三", 1);
	//	worker->ShowInfo();
	//	delete worker;
	//	worker = NULL;
	//
	//	worker = new Manager(1, "张三", 1);
	//	worker->ShowInfo();
	//	delete worker;
	//	worker = NULL;
	//
	//	worker = new Boss(1, "张三", 1);
	//	worker->ShowInfo();
	//	delete worker;
	//	worker = NULL;

	WorkManager wm;
	int num;//接收用户的选项
	while (true)
	{
		wm.ShowMenu();
		cout << "请输入你的选项：" << endl;
		cin >> num;
		switch (num)
		{
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			wm.AddEmp();
			break;
		case 2:
			wm.ShowEmp();
			break;
		case 3:
			//cout << wm.IsExist(1) << endl;//测试代码
			wm.DelEmp();
			break;
		case 4:
			wm.ModEmp();
			break;
		case 5:
			wm.FindEmp();
			break;
		case 6:
			wm.SortEmp();
			break;
		case 7:
			wm.CleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}