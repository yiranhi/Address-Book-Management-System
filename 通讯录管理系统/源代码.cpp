#define _CRT_SECURE_NO_WARNINGS

#include"sub.h"

//ͨѶ¼����
//1.�����ϵ�ˣ��������Ա����䡢��ϵ�绰����ͥסַ������1000��
//2.��ʾ��ϵ��
//3.ɾ����ϵ��
//4.������ϵ��
//5.�޸���ϵ��
//6.�����ϵ��
//7.�˳�ͨѶ¼

int main()
{
	AddressBook book;
	book.B_size = 0;

	while (true)
	{
		menu();
		cout << "��ѡ��";
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
			cout << "�˳�ͨѶ¼,��ӭ�´�ʹ��"<<endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "������Ч��������ѡ��";
			select = Select();
			break;
		}
	}

	system("pause");
	return 0;
}