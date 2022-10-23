#define _CRT_SECURE_NO_WARNINGS

#include"sub.h"

//通讯录功能
//1.添加联系人（姓名、性别、年龄、联系电话、家庭住址）做多1000人
//2.显示联系人
//3.删除联系人
//4.查找联系人
//5.修改联系人
//6.清空联系人
//7.退出通讯录

int main()
{
	AddressBook book;
	book.B_size = 0;

	while (true)
	{
		menu();
		cout << "请选择：";
		int select = Select();

		switch (select)
		{
		case 1:
			Addperson(&book);
			break;
		case 2:
			Showperson(&book);
			break;
		case 3:
			Deleteperson(&book);
			break;
		case 4:
			Checkperson(&book);
			break;
		case 5:
			Modifyperson(&book);
			break;
		case 6:
			Clearperson(&book);
			break;
		case 0:
			cout << "退出通讯录,欢迎下次使用"<<endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入无效，请重新选择：";
			select = Select();
			break;
		}
	}

	system("pause");
	return 0;
}