#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

#include<iostream>
#include<string>

using namespace std;

struct Person
{
	string Name;
	int Sex;
	int Age;
	string Number;
	string Address;
};

struct AddressBook
{
	struct Person P_Arr[MAX];
	int B_size;
};

void menu()
{
	cout << "**********************" << endl;
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****0.退出通讯录*****" << endl;
	cout << "**********************" << endl;
}

int Select()
{
	int select = 0;
	cin >> select;
	return select;
}

int Search(AddressBook* book)
{
	int i = 0;
	string name;
	cout << "请输入联系人姓名：";
	cin >> name;
	for (i = 0; i < book->B_size; i++)
	{
		if (book->P_Arr[i].Name == name)
		{
			cout << "姓名:" << book->P_Arr[i].Name << "\t";
			cout << "性别:" << (book->P_Arr[i].Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄:" << book->P_Arr[i].Age << "\t";
			cout << "电话:" << book->P_Arr[i].Number << "\t";
			cout << "地址:" << book->P_Arr[i].Address << endl;
			return i;
		}
	}
			cout << "查无此人" << endl;
			return -1;
}

void add(AddressBook* book)
{
	string name;
	cout << "请输入姓名：";
	cin >> name;
	book->P_Arr[book->B_size].Name = name;

	int sex;
	cout << "请选择性别(1.男 2.女)：";
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			book->P_Arr[book->B_size].Sex = sex;
			break;
		}
		cout << "输入无效，请重新选择性别：";
	}

	int age;
	cout << "请输入年龄：";
	cin >> age;
	book->P_Arr[book->B_size].Age = age;

	string number;
	cout << "请输入电话号码：";
	cin >> number;
	book->P_Arr[book->B_size].Number = number;

	string address;
	cout << "请输入家庭住址：";
	cin >> address;
	book->P_Arr[book->B_size].Address = address;

}

void Showall(AddressBook* book)
{
	int i = 0;
	if (book->B_size == 0)
		cout << "当前通讯录中无联系人" << endl;
	else
	{
		for (i = 0; i < book->B_size; i++)
		{
			cout << "姓名:" << book->P_Arr[i].Name << "\t";
			cout << "性别:" << (book->P_Arr[i].Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄:" << book->P_Arr[i].Age << "\t";
			cout << "电话:" << book->P_Arr[i].Number << "\t";
			cout << "地址:" << book->P_Arr[i].Address << endl;
		}
	}
}

void Addperson(AddressBook* book)
{
	if (book->B_size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		add(book);
		book->B_size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}

void Showperson(AddressBook* book)
{
	Showall(book);
	system("pause");
	system("cls");
}

void Deleteperson(AddressBook* book)
{
	int i = 0;
	int select = 0;
	
	int result = Search(book);

	cout << "请选择是否删除该联系人（1.删除 2.取消）：";
	cin >> select;
	if (select == 1)
	{
		for (i = result; i < book->B_size+1; i++)
		{
			book->P_Arr[i] = book->P_Arr[i + 1];	//删除 即用后一个数据覆盖前一个数据
		}
		book->B_size--;
		cout << "成功删除" << endl;
	}
	system("pause");
	system("cls");
}

void Checkperson(AddressBook* book)
{
	int result = Search(book);
	system("pause");
	system("cls");
}

void Modifyperson(AddressBook* book)
{
	int result = Search(book);

	int sex;
	cout << "请选择性别(1.男 2.女)：";
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			book->P_Arr[result].Sex = sex;
			break;
		}
		cout << "输入无效，请重新选择性别：";
	}

	int age;
	cout << "请输入年龄：";
	cin >> age;
	book->P_Arr[result].Age = age;

	string number;
	cout << "请输入电话号码：";
	cin >> number;
	book->P_Arr[result].Number = number;

	string address;
	cout << "请输入家庭住址：";
	cin >> address;
	book->P_Arr[result].Address = address;
	system("pause");
	system("cls");
}

void Clearperson(AddressBook* book)	//实现思路：将通讯录联系人的数量置为0，实现逻辑清空
{
	int select = 0;
	cout << "是否确认清空通讯录（1.清空 2.取消）：";
	cin >> select;
	if (select == 1)
	{
		book->B_size = 0;
		cout << "通讯录已清空" << endl;
	}
	system("pause");
	system("cls");
}

