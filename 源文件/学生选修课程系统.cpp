#include <iostream>
#include <string>
#include "CheckInput.h"
#include "Administrator.h"
//#include "Course.h"
#include "Student.h"
#include "Menu.h"           //������Ҫͷ�ļ�
using namespace std;       //ʹ�������ռ�


//����ʵ��
int main()
{
	Menu Meu;          //����һ���˵�����   
	string ISelect = "-1";	//�����ַ�������ISelect��������ж�	
	Meu.IndentityMenu();	//��ʾ���ѡ�����
loop:cout << "�����롰1������2����0����ѡ��������: ";		//loop���������������������
	cin >> ISelect;		//����
	//���û�ѡ�񡰹���Ա�����
	if (ISelect == "1")
	{
		system("cls");
		cout << "***��ѡ���ˣ�1.����Ա***" << endl;
		cout << "����������" << endl;
		string PassWard;
		cin >> PassWard;		//�������Ա���룬Ĭ�������趨Ϊ��admin
		//������Ա���������������������
		while (PassWard != "admin")
		{
			cout << "����������������룡" << endl;
			cin >> PassWard;
		}
		//������ȷ���������Ա����
		Meu.ShowWelcome("����Ա");	//�������ӭ����Ա������
		system("pause");
		system("cls");
		Administrator Admin;		//����Admin������Ա�����󲢵��ù��캯�����г�ʼ��
		while (true)
		{

			Meu.ShowWelcome("����Ա");	//�������ӭ����Ա������
			Meu.AdmMenu();			//��ʾ����Ա�˵�����
			//����ѡ����
			Admin.Opration();		//���ù���Ա����

		}

	}
	//ѡ��ѧ�������
	else if (ISelect == "2")
	{
		system("cls");
		cout << "***��ѡ���ˣ�2.ѧ��***" << endl;
		long StuID;			//����ѧ��ѧ�ű���
		string StuName;
		string StuSex;
		string StuYear;
		string StuDepartment;
		string StuClass;
		string StuContact;
		string InPut;		//����string�࣬���ڽ���������
		cout << "����������ѧ��" << endl;
		cin >> InPut;
		//�����벻Ϊ����������������
		while (!checkint(InPut))
		{
			cout << "��������ȷ��ѧ�ţ�" << endl;
			cin >> InPut;
		}

		StuID = strlong(InPut);		//����ɹ���stringתΪlong������ֵ��StuID��
		//������ȷ������ѧ������
		Meu.ShowWelcome(StuID);
		system("pause");
		system("cls");
		Student Stu;
		//�����Ƿ����и�ѧ��
		if (!Stu.CheckStudent(StuID)) //����
		{
			cout << endl;
			cout << "����δѡ�Σ���������Ϣ����ѡ��һ�ſγ��Ա�����������" << endl;
			cout << "������������";
			cin >> StuName;
			cout << "�������Ա�";
			cin >> StuSex;
			cout << "���������䣺";
			cin >> StuYear;
			cout << "������ϵ��";
			cin >> StuDepartment;
			cout << "������༶��";
			cin >> StuClass;
			cout << "��������ϵ��ʽ��";
			cin >> StuContact;
		}
		//����
		else
		{
			
			STUDENT* Info = new STUDENT;	//��̬����ṹ��ָ��
			Info = Stu.GetTheStudent(StuID);	//���ú������ú����᷵��ѧ����Ϣ�ṹ��
			StuID = Info->StuID;
			StuName = Info->StuName;
			StuSex = Info->StuSex;
			StuYear = Info->StuYear;
			StuDepartment = Info->StuDepartment;
			StuClass = Info->StuClass;
			StuContact = Info->StuContact;
			delete Info;	//�ͷ�


		}
		system("pause");
		system("cls");
		while (true)
		{
			Meu.ShowWelcome(StuID);	//��ӭ����
			//��ʾѧ���˵�����
			Meu.StuMenu();
			//����ѡ����
			Stu.StuOpration(StuID, StuName, StuSex, StuYear, StuDepartment, StuClass, StuContact);
		}

	}
	//ѡ���˳�ϵͳ
	else if (ISelect == "0")
	{

		cout << "��ӭ���´�ʹ�ã��ټ���" << endl;
		system("pause");
	}
	else //���������������
	{
		cout << "������������롰1������2����0��" << endl;
		cout << endl;
		goto loop;
	}
	return 0;
}
