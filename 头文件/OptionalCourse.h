#pragma once
#include <iostream>
using namespace std;
#include "Course.h"

//�̳г�����Course
class Optional : public Course
{
public:
	//���캯����ʵ�ֶ���ĳ�ʼ����������ӻ��ȡ�γ���Ϣ��
	Optional(long num, string name, string stime, string score, string term,  int PeopleCount = 0,string kind = "ѡ�޿�");
	//��д�麯��
	virtual void PrintCourse();
	
private:
	//˽�У���ֹ������������
	virtual void PrintStudent();
};