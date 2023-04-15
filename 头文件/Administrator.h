#pragma once
#include <iostream>
#include "Course.h"
#include <fstream>
#include <string>
#include <list>
#include "CheckInput.h"
#include "CompulsoryCourse.h"
#include "OptionalCourse.h"
#define FILE "Course.txt"
using namespace std;
 
class Administrator
{	


public:
	int Count ;						//ϵͳ���ܿγ�������ʼ��Ϊ0
	int PeoCou;						//ϵͳ��ѧ��������
	Course** COURSE;				//����һ��ָ��ָ������ĸ���ָ��COURSE,����ά������
	list <STUDENT> StuList;			//������������ѧ����Ϣ
	Administrator();				//���캯��
	int CourseCount();				//��ʼ����ȡ�γ�����
	void ReadFile();				//��ʼ����ȡ�ļ�
	void PrintAll();				//����γ���Ϣ��ѧ��ѧ��
	int ReadStuList();				//��ȡѧ����Ϣ
	void ShowStudent(const list <STUDENT>&StuList); //���ѧ����Ϣ
	long Search(int num);			//��ѯ�γ�
	void Search(long StuID, const list <STUDENT>& StuList); //��ѯѧ����Ϣ
	void Add();						//��ӿγ�
	void Add(int num, long StuID);	//���ѧ��
	void Change(int x);			//�޸Ŀγ���Ϣ
	void Change(long StuID);  //�޸�ѧ��
	void del(int x);				//ɾ���γ�
	void del(int num, long StuID);		//ɾ��ѧ��
	void SaveFile();				//�����ļ�
	void Opration();				//����Ա����
	~Administrator();				//��������
};

