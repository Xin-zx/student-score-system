#include <iostream>
#include <vector>

using namespace  std;
//添加学生信息
struct student
{
	string name;
	int num;
	double math;
	double English;
	double c;
	double sum;
};

vector <student> stu;

//菜单
void showMenu()
{
	cout << "1. 添加学生" << endl;
	cout << "2. 展示所有学生" << endl;
	cout << "3. 查询学生" << endl;
	cout << "4. 修改学生成绩" << endl;
	cout << "5. 删除学生" << endl;
	cout << "6. 计算班级平均分学生" << endl;
	cout << "0. 退出" << endl;
}

void addStudent()
{
	student temp; //临时学生变量
	cout << "\n======成绩管理系统======\n";

	cout << "请输入该学生的姓名：" << endl;
	cin >> temp.name;
	cout << "请输入该学生的学号：" << endl;
	cin >> temp.num;
	cout << "请输入该学生的数学成绩：" << endl;
	cin >> temp.math;
	cout << "请输入该学生的英语成绩：" << endl;
	cin >> temp.English;
	cout << "请输入该学生的c++成绩：" << endl;
	cin >> temp.c;
	temp.sum = temp.c + temp.English + temp.math + temp.math;
	stu.push_back(temp);
	system("pause");
}
//展示所有学生
void showAllStudent()
{
	if (stu.empty())
	{
		cout << "当前没有学生信息，请先添加学生!" << endl;
		system("pause");
		return ;
	}

	for (int i = 0; i < stu.size(); i++)
	{
		cout << "第" << i + 1 << "名学生的姓名为" << stu[i].name
			<< "\t学号为：" << stu[i].num
			<< "\t数学成绩为：" << stu[i].math
			<< "\t英语成绩为：" << stu[i].English
			<< "\tc++成绩为：" << stu[i].c
			<< "\t总成绩为：" << stu[i].sum << endl;
	}
	system("pause");
}

void searchStudent()
{
	if (stu.empty())
	{
		cout << "当前没有学生信息，请先添加学生!" << endl;
		system("pause");
		return;
	}

	int num;
	cout << "请输入您要查找学生的学号：";
	cin >> num;

	bool found = false;

	for (int i = 0; i < stu.size(); i++)
	{
		if (num == stu[i].num)
		{
			cout << "该学生的姓名为" << stu[i].name
				<< "\t学号为：" << stu[i].num
				<< "\t数学成绩为：" << stu[i].math
				<< "\t英语成绩为：" << stu[i].English
				<< "\tc++成绩为：" << stu[i].c
				<< "\t总成绩为：" << stu[i].sum << endl;
				found = true;
				break;
		}
	}

	if (!found)
	{
		cout << "没有找到该学生，请检查是否输入有误！" << endl;
		system("pause");
		return;
	}
	
	system("pause");
	return;
}

//编辑学生
void editStudemt()
{
	if (stu.empty())
	{
		cout << "当前没有学生信息，请先添加学生!" << endl;
		system("pause");
		return;
	}

	int num;
	cout << "请输入您要编辑学生的学号：";
	cin >> num;

	bool found = false;

	for (int i = 0; i < stu.size(); i++)
	{
		if (num == stu[i].num)
		{
			cout << "请输入该学生的姓名：" << endl;
			cin >> stu[i].name;
			cout << "请输入该学生的学号：" << endl;
			cin >> stu[i].num;
			cout << "请输入该学生的数学成绩：" << endl;
			cin >> stu[i].math;
			cout << "请输入该学生的英语成绩：" << endl;
			cin >> stu[i].English;
			cout << "请输入该学生的c++成绩：" << endl;
			cin >> stu[i].c;
			stu[i].sum = stu[i].c + stu[i].English + stu[i].math + stu[i].math;
			cout << "修改成功" << endl;
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "没有找到该学生，请检查是否输入有误！" << endl;
		system("pause");
		return;
	}

	system("pause");
	return;
}

//删除学生
void deleteStudent()
{
	if (stu.empty())
	{
		cout << "当前没有学生信息，请先添加学生!" << endl;
		system("pause");
		return;
	}

	int num;
	cout << "请输入您要删除学生的学号：";
	cin >> num;

	bool found = false;

	for (int i = 0; i < stu.size(); i++)
	{
		if (num == stu[i].num)
		{
			stu.erase(stu.begin() + i);
			cout << "删除成功 !" << endl;
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "没有找到该学生，请检查是否输入有误！" << endl;
		system("pause");
		return;
	}

	system("pause");
	return;
}

void calcAverageScore()
{
	if (stu.empty())
	{
		cout << "当前没有学生信息，请先添加学生!" << endl;
		system("pause");
		return;
	}

	double math_Avg;
	double English_Avg;
	double c_Avg;
	
	double sum_Avg = 0.0;
	double sum_math = 0.0;
	double sum_English = 0.0;
	double sum_c = 0.0;

	for (int i = 0; i < stu.size(); i++)
	{
		sum_math += stu[i].math;
		sum_English += stu[i].English;
		sum_c += stu[i].c;
	}

	math_Avg = sum_math / stu.size();
	English_Avg = sum_English / stu.size();
	c_Avg = sum_c / stu.size();
	sum_Avg = (sum_c + sum_English + sum_math) / stu.size();

	cout << "数学平均分为：" << math_Avg << endl;
	cout << "英语平均分为：" << English_Avg << endl;
	cout << "c++平均分为：" << c_Avg << endl;
	cout << "班级总平均分为：" <<sum_Avg << endl;
	system("pause");
	return;
}

int main()
{
	int choice;
	while (true)
	{
		 showMenu();
		cin >> choice;

		switch (choice)
		{
		case 1:
			addStudent();
			break;
		case 2:
			showAllStudent();
			break;
		case 3:
			searchStudent();
			break;
		case 4:
			editStudemt();
			break;
		case 5:
			deleteStudent();
			break;
		case 6:
			calcAverageScore();
			break;
		case 0:
			return 0;

		}
		system("cls");
	}
	return 0;
}