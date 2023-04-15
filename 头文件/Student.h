#pragma once
#include <iostream>
#include "Course.h"
#include <fstream>
#include <string>
#include "CompulsoryCourse.h"
#include "OptionalCourse.h"
#include "CheckInput.h"
#define FILE "Course.txt"
using namespace std;

class Student
{
public:
	int Count;								//�γ�����
	Course** COURSE;						//����һ��ָ��ָ������ĸ���ָ��COURSE,����ά������
	Student();
	int StuCourseCount();					//��ȡ�γ�����
	void StuPrintCourse();					//������пγ���Ϣ
	void StuReadFile();						//��ȡ�ļ�
	long StuSearch(int num);	//��ѯ�γ���Ϣ
	void StuAdd(int num, long StuID, string StuName, string StuSex, string StuYear, string StuDepartment, string StuClass, string StuContact);	//ѡ�Σ����ѧ����
	void Studel(int num, long StuID);			//�˿Σ�ɾ��ѧ����
	void HaveCourse(long StuID);		//��ѯ��ѡ�Ŀγ�
	void StuSaveFile();						//����
	void StuOpration(long StuID,string StuName , string StuSex, string StuYear ,string StuDepartment ,string StuClass , string StuContact);	//����
	bool CheckStudent(long StuID);
	struct STUDENT* GetTheStudent(long StuID);	//����������ѧ����Ϣ�ṹ��
	~Student();
};
