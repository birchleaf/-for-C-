#include "CheckInput.h"


// string ת int
int strint(string str)
{
	
	return atoi(str.c_str()); //atoi:char-->int;c_str:string-->char;
}

//stringתlong����������ѧ��ѧ��
long strlong(string InPut)
{
	long x;
	istringstream is(InPut); 
	is >> x;
	return x;
}


//�ж�������ַ����Ƿ�Ϊ������,��Ϊ�������������棬���򷵻ؼ�
bool checkint(string InPut)
{
	char* a = new char[InPut.length()];
	strcpy(a, InPut.c_str());
	
	for (int i = 0; i < InPut.length(); i++)
	{
		//�����������
		if (!isdigit(a[i]))
		{
			return false;
		}
	}
	//���ﲻ���ͷ�����a���ڴ�ռ䣬���������֪��Ϊʲô������
	return true;
}



//�ж�������Ƿ�Ϊ�ض���Χ���������ǣ��򷵻�����ֵint
int check(string Select,int a,int b )
{
	int x = strint(Select);

	while (true)
	{
		if (checkint(Select) && x >= a && x <= b)
		{
			return x;
		}
		else
		{
			cout << "��������ȷ������" << endl;
			cin >> Select;
			x = strint(Select);
		}

	}
	return -1;
}


