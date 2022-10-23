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
	cout << "*****1.�����ϵ��*****" << endl;
	cout << "*****2.��ʾ��ϵ��*****" << endl;
	cout << "*****3.ɾ����ϵ��*****" << endl;
	cout << "*****4.������ϵ��*****" << endl;
	cout << "*****5.�޸���ϵ��*****" << endl;
	cout << "*****6.�����ϵ��*****" << endl;
	cout << "*****0.�˳�ͨѶ¼*****" << endl;
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
	cout << "��������ϵ��������";
	cin >> name;
	for (i = 0; i < book->B_size; i++)
	{
		if (book->P_Arr[i].Name == name)
		{
			cout << "����:" << book->P_Arr[i].Name << "\t";
			cout << "�Ա�:" << (book->P_Arr[i].Sex == 1 ? "��" : "Ů") << "\t";
			cout << "����:" << book->P_Arr[i].Age << "\t";
			cout << "�绰:" << book->P_Arr[i].Number << "\t";
			cout << "��ַ:" << book->P_Arr[i].Address << endl;
			return i;
		}
	}
			cout << "���޴���" << endl;
			return -1;
}

void add(AddressBook* book)
{
	string name;
	cout << "������������";
	cin >> name;
	book->P_Arr[book->B_size].Name = name;

	int sex;
	cout << "��ѡ���Ա�(1.�� 2.Ů)��";
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			book->P_Arr[book->B_size].Sex = sex;
			break;
		}
		cout << "������Ч��������ѡ���Ա�";
	}

	int age;
	cout << "���������䣺";
	cin >> age;
	book->P_Arr[book->B_size].Age = age;

	string number;
	cout << "������绰���룺";
	cin >> number;
	book->P_Arr[book->B_size].Number = number;

	string address;
	cout << "�������ͥסַ��";
	cin >> address;
	book->P_Arr[book->B_size].Address = address;

}

void Showall(AddressBook* book)
{
	int i = 0;
	if (book->B_size == 0)
		cout << "��ǰͨѶ¼������ϵ��" << endl;
	else
	{
		for (i = 0; i < book->B_size; i++)
		{
			cout << "����:" << book->P_Arr[i].Name << "\t";
			cout << "�Ա�:" << (book->P_Arr[i].Sex == 1 ? "��" : "Ů") << "\t";
			cout << "����:" << book->P_Arr[i].Age << "\t";
			cout << "�绰:" << book->P_Arr[i].Number << "\t";
			cout << "��ַ:" << book->P_Arr[i].Address << endl;
		}
	}
}

void Addperson(AddressBook* book)
{
	if (book->B_size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		add(book);
		book->B_size++;
		cout << "��ӳɹ�" << endl;
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

	cout << "��ѡ���Ƿ�ɾ������ϵ�ˣ�1.ɾ�� 2.ȡ������";
	cin >> select;
	if (select == 1)
	{
		for (i = result; i < book->B_size+1; i++)
		{
			book->P_Arr[i] = book->P_Arr[i + 1];	//ɾ�� ���ú�һ�����ݸ���ǰһ������
		}
		book->B_size--;
		cout << "�ɹ�ɾ��" << endl;
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
	cout << "��ѡ���Ա�(1.�� 2.Ů)��";
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			book->P_Arr[result].Sex = sex;
			break;
		}
		cout << "������Ч��������ѡ���Ա�";
	}

	int age;
	cout << "���������䣺";
	cin >> age;
	book->P_Arr[result].Age = age;

	string number;
	cout << "������绰���룺";
	cin >> number;
	book->P_Arr[result].Number = number;

	string address;
	cout << "�������ͥסַ��";
	cin >> address;
	book->P_Arr[result].Address = address;
	system("pause");
	system("cls");
}

void Clearperson(AddressBook* book)	//ʵ��˼·����ͨѶ¼��ϵ�˵�������Ϊ0��ʵ���߼����
{
	int select = 0;
	cout << "�Ƿ�ȷ�����ͨѶ¼��1.��� 2.ȡ������";
	cin >> select;
	if (select == 1)
	{
		book->B_size = 0;
		cout << "ͨѶ¼�����" << endl;
	}
	system("pause");
	system("cls");
}

