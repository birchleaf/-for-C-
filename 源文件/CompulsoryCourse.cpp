#include "CompulsoryCourse.h"

//���캯��
Compulsory::Compulsory(long num, string name,string stime, string score, string term,int PeopleCount,string kind )
{
	this->num=num;						//�γ̱��   
	this->name=name;					//�γ�����   
	this->kind = "���޿�";				//�γ�����   
	this->stime=stime;					//��ѧʱ   
	this->score=score;					//ѧ��    
	this->term=term;					//����ѧ��   
	this->PeopleCount = PeopleCount;	//�ѱ���������Ĭ�ϲ���Ϊ0
	this->Student[MAX];					//ѧ��
}

//����γ̻�����Ϣ
void Compulsory::PrintCourse()
{
	cout << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "�γ���Ϣ: "<<endl;
	cout << "���" << '\t';
	cout << "����" << '\t';
	cout << "����" << '\t';
	cout << "ѧʱ" << '\t';
	cout << "ѧ��" << '\t';
	cout << "ѧ��" << '\t'<<'\t';
	cout << "����" << endl;
	cout << this->num << '\t';
	cout << this->name << '\t';
	cout << this->kind << '\t';
	cout << this->stime << '\t';
	cout << this->score << '\t';
	cout << this->term << '\t';
	cout << this->PeopleCount <<endl;
	
}

//����γ���ѧ����Ϣ
void Compulsory::PrintStudent()
{
	
	for (int i = 0; i < this->PeopleCount; i++)
	{
		cout << endl;
		cout << "ѧ����Ϣ: " << endl;
		cout << "ѧ��" << '\t';
		cout << "����" << '\t';
		cout << "�Ա�" << '\t';
		cout << "����" << '\t';
		cout << "ϵ��" << '\t';
		cout << "�༶" << '\t';
		cout << "��ϵ��ʽ" <<endl;
		cout << this->Student[i].StuID<< '\t';
		cout << this->Student[i].StuName<< '\t';
		cout << this->Student[i].StuSex<< '\t';
		cout << this->Student[i].StuYear<< '\t';
		cout << this->Student[i].StuDepartment<< '\t';
		cout << this->Student[i].StuClass<< '\t';
		cout << this->Student[i].StuContact << endl;
	}

	cout << "-------------------------------------------------------------------------" << endl;
}
