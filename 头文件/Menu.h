#pragma once
#include <iostream>
using namespace std;
class Menu
{
public:
	void IndentityMenu();		//�����֤����
	void AdmMenu();				//����Աѡ�����
	void StuMenu();				//ѧ������
	
	/*����������һ�������ӭ���ֺ���ģ�壬��Ϊ����Ա���������ӭ�㣬����Ա����string�ͣ�������
	*�������ӭ�㡱�������ѧ��ѧ�ţ�long��)
	*/
	template<typename T>
	void ShowWelcome(T Welcome)
	{
		cout << endl;
		cout << "��ӭ�㣬"<<Welcome<<endl;
	}
};
	


