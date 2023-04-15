#pragma once
#include <iostream>
#define MAX 50 //ÿ�ſ�ѧ���������

using namespace std;



struct STUDENT
{
	long StuID;		//ѧ��
	string StuName;	//����
	string StuSex;	//�Ա�
	string StuYear;	//����
	string StuDepartment;	//ϵ��
	string StuClass;	//�༶
	string StuContact;	//��ϵ��ʽ
};


class Course	//�����γ̳�����
{
	//������Ԫ������ʹ��ֻ�й���Ա�����ѧ����Ϣ
	friend class Administrator;
	friend class Compulsory;
	friend class Optional;

public:
		//����һ��������Course�����������޿Σ�Compulsory����ѡ�޿Σ�Optional�������࣬���϶�̬������
		virtual void PrintCourse()=0;		//��������γ���Ϣ
		long num;							//�γ̱��   
		string name;						//�γ�����   
		string kind;						//�γ�����:���޻�ѡ��  
		string stime;							//��ѧʱ   
		string score;							//ѧ��    
		string term;							//����ѧ��   
		int PeopleCount;					//�ѱ�������						
		STUDENT Student[MAX];				//�ѱ����ÿγ̵�ѧ����Ϣ
private:		
	//˽�У���ֹ������������
	virtual void PrintStudent() = 0;
};