#pragma once
#include <iostream>
using namespace std;
#include "Course.h"

//�̳г�����Course
class Compulsory : public Course
{
public:
	//���캯����ʵ�ֶ���ĳ�ʼ����������ӻ��ȡ�γ���Ϣ��
	Compulsory(long num , string name, string stime, string score, string term,  int PeopleCount = 0,string kind = "���޿�");
	//��д�麯��
	virtual void PrintCourse();		//��ʾ�γ���Ϣ
	
private:
	//˽�У���ֹ������������
	virtual void PrintStudent();	//����ѱ���ѧ����Ϣ
};