#include "Student.h"


Student::Student()
{
	ifstream ifs;	//����������
	ifs.open(FILE, ios::in);	//���ļ�����

	//���򲻿��ļ�����δ���ҵ��ļ�
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->Count = 0;		//�γ���Ϊ0
		this->COURSE = NULL;	//Course����ָ��Ϊ��
		ifs.close();	//�ر��ļ�
		return;		//�����˺���
	}
	//���ļ����ڣ��ж��ļ����Ƿ�������
	char buf;
	ifs >> buf;
	//������
	if (ifs.eof())
	{
		cout << "�ļ����ڣ�������Ϊ��" << endl;
		this->Count = 0;
		this->COURSE = NULL;
		ifs.close();
		return;
	}
	//������
	else
	{
		this->Count = StuCourseCount();	 //��ȡ�γ�����
		//����һ��ָ�����飬���鳤��Ϊ�γ�����������COURSEָ�����ָ������
		this->COURSE = new Course * [this->Count];
		this->StuReadFile();		//��ȡ�ļ�
		ifs.close();			//�ر��ļ�
		cout << "�γ���Ϊ: " << Count << endl;
		cout << "ѧ��ϵͳ���ݶ�ȡ�ɹ���" << endl;
	}

}


void Student::StuReadFile()
{

	ifstream ifs;
	ifs.open(FILE, ios::in);
	long num;               //�γ̱�� 
	string name;			//�γ�����   
	string kind;			//�γ�����   
	string stime;              //��ѧʱ   
	string score;				//ѧ��    
	string term;				//����ѧ��   
	int PeopleCount;		//�ѱ�������
	int ReadCourse = 0;		//�Ѷ�ȡ�Ŀγ��������������λ����������е�λ��

	//ѧ����Ϣ
	long StuID;				//ѧ��
	string StuName;
	string StuSex;
	string StuYear;
	string StuDepartment;
	string StuClass;
	string StuContact;

	//�����ȡ�γ�����,�����ո������һ������
	while (ifs >> num && ifs >> name && ifs >> kind && ifs >> stime && ifs >> score
		&& ifs >> term && ifs >> PeopleCount)
	{
		Course* Cour = NULL;	//����һ��ָ�����Cour
		//������ȡ�Ŀγ�����Ϊ���޿�
		if (kind == "���޿�")
		{

			/*newһ�����޿ζ��󣬲����ù��캯�����г�ʼ��������ȡ�����ݸ�ֵΪ���캯���Ĳ���ֵ
			* ��Courָ������������
			*/
			Cour = new Compulsory(num, name, stime, score, term, PeopleCount);
			//��ȡѧ����Ϣ

			int ReadPeople = 0;	//�Ѷ�ȡ��ѧ���������÷�ͬ��
			if (ReadPeople == Cour->PeopleCount)
			{
				goto loop;
			}
			while (ifs >> StuID && ifs >> StuName && ifs >> StuSex && ifs >> StuYear && ifs >> StuDepartment && ifs >> StuClass
				&& ifs >> StuContact)
			{
				
				Cour->Student[ReadPeople].StuID = StuID;	//¼��ѧ��
				Cour->Student[ReadPeople].StuName = StuName;
				Cour->Student[ReadPeople].StuSex = StuSex;
				Cour->Student[ReadPeople].StuYear = StuYear;
				Cour->Student[ReadPeople].StuDepartment = StuDepartment;
				Cour->Student[ReadPeople].StuClass = StuClass;
				Cour->Student[ReadPeople].StuContact = StuContact;
				ReadPeople++;
				if (ReadPeople == Cour->PeopleCount)
				{
					break;
				}



			}
		}
		//������ȡ�Ŀγ�����Ϊѡ�޿�
		else
		{
			Cour = new Optional(num, name, stime, score, term, PeopleCount);

			int ReadPeople = 0;
			if (ReadPeople == Cour->PeopleCount)
			{
				goto loop;
			}
			while (ifs >> StuID && ifs >> StuName && ifs >> StuSex && ifs >> StuYear && ifs >> StuDepartment && ifs >> StuClass
				&& ifs >> StuContact)
			{
				
				
				Cour->Student[ReadPeople].StuID = StuID;	//¼��ѧ��
				Cour->Student[ReadPeople].StuName = StuName;
				Cour->Student[ReadPeople].StuSex = StuSex;
				Cour->Student[ReadPeople].StuYear = StuYear;
				Cour->Student[ReadPeople].StuDepartment = StuDepartment;
				Cour->Student[ReadPeople].StuClass = StuClass;
				Cour->Student[ReadPeople].StuContact = StuContact;
				ReadPeople++;
				if (ReadPeople == Cour->PeopleCount)
				{
					break;
				}
			}


		}

		loop:this->COURSE[ReadCourse] = Cour;

		ReadCourse++;
	}
	ifs.close();
}



int Student::StuCourseCount()
{
	ifstream ifs;
	ifs.open(FILE, ios::in);
	int Count = 0;	//��¼�γ�����
	string buf;
	while (getline(ifs, buf))	//���ж�ȡ��ÿ��ȡһ�У�count+1
	{
		Count++;
	}
	return Count;	//���ؿγ�����
}



void Student::StuPrintCourse()
{


	for (int i = 0; i < this->Count; i++)
	{
		this->COURSE[i]->PrintCourse();
		cout << "-------------------------------------------------------------------------" << endl;
	}


}



void Student::HaveCourse(long StuID)	//����ѧ��
{
	for (int i = 0; i < this->Count; i++)

	{
		for (int j = 0; j < this->COURSE[i]->PeopleCount; j++)
		{
			if (this->COURSE[i]->Student[j].StuID == StuID)
			{
				this->COURSE[i]->PrintCourse();
				cout << "-------------------------------------------------------------------------" << endl;
			}
		}

	}
}


void Student::StuAdd(int num, long StuID, string StuName, string StuSex, string StuYear, string StuDepartment, string StuClass, string StuContact)	//�����š�ѧ��
{
	int x = -1;
	for (int i = 0; i < this->Count; i++)
	{
		if (this->COURSE[i]->num == num)
		{
			x = i;
			this->COURSE[x]->PrintCourse();
			cout << "-------------------------------------------------------------------------" << endl;
			for (int j = 0; j < this->COURSE[i]->PeopleCount; j++)
			{
				if (this->COURSE[i]->Student[j].StuID == StuID)
				{
					cout << "����ѡ�ÿ�" << endl;
					return;
				}
			}
		}
	}
	if (x == -1)
	{
		cout << "�γ̱�Ų�����" << endl;
		
	}
	else
	{
		//KECH�����б��Ϊnum�Ŀγ��е�StuID���������һλѧ����
		this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuID = StuID;
		this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuName = StuName;
		this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuSex = StuSex;
		this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuYear = StuYear;
		this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuDepartment = StuDepartment;
		this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuClass = StuClass;
		this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuContact = StuContact;
		this->COURSE[x]->PeopleCount++;
		cout << "ѡ�γɹ�" << endl;
	}

	
}


bool Student::CheckStudent(long StuID)
{
	
	for (int i = 0; i < this->Count; i++)
	{
		for (int j = 0; j < COURSE[i]->PeopleCount; j++)
		{
			if (this->COURSE[i]->Student[j].StuID == StuID)
			{
				StuID = this->COURSE[i]->Student[j].StuID;
				
				return true;
			}
				
		}
		
	}
	return false;
}


struct STUDENT* Student::GetTheStudent(long StuID)
{
	STUDENT* Info =new STUDENT;
	for (int i = 0; i < this->Count; i++)
	{
		for (int j = 0; j < COURSE[i]->PeopleCount; j++)
		{
			if (this->COURSE[i]->Student[j].StuID == StuID)
			{
				Info->StuID = this->COURSE[i]->Student[j].StuID;
				Info->StuName = this->COURSE[i]->Student[j].StuName;
				Info->StuSex = this->COURSE[i]->Student[j].StuSex;
				Info->StuYear = this->COURSE[i]->Student[j].StuYear;
				Info->StuDepartment = this->COURSE[i]->Student[j].StuDepartment;
				Info->StuClass = this->COURSE[i]->Student[j].StuClass;
				Info->StuContact = this->COURSE[i]->Student[j].StuContact;
				return Info;
			}
		}
	}


}





//��ѯ�γ���Ϣ�����ظÿγ��������еĶ�λ
long Student::StuSearch(int num)	//������
{
	for (int i = 0; i < this->Count; i++)
	{
		if (this->COURSE[i]->num == num)
		{
			this->COURSE[i]->PrintCourse();
			cout << "-------------------------------------------------------------------------" << endl;
			return i;
		}
	}
	return -1;
}



void Student::Studel(int num, long StuID)	//�����š�ѧ��
{

	int x = -1;
	for (int i = 0; i < this->Count; i++)
	{
		if (this->COURSE[i]->num == num)
		{
			x = i;
			break;
		}

	}
	if (x == -1)
	{
		cout << "�γ̱�Ų�����" << endl;
		return;
	}
	for (int j = 0; j < this->COURSE[x]->PeopleCount; j++)
	{
		this->COURSE[x]->PrintCourse();
		cout << "-------------------------------------------------------------------------" << endl;
		if (this->COURSE[x]->Student[j].StuID == StuID)
		{
			for (int k = j; k < MAX - 1; k++)
			{
				this->COURSE[x]->Student[k] = this->COURSE[x]->Student[k + 1];
			}
			this->COURSE[x]->PeopleCount--;
			cout << "�˿γɹ�" << endl;
			return;
		}
	}

}

void Student::StuSaveFile()
{
	ofstream ofs;
	ofs.open(FILE, ios::out);
	for (int i = 0; i < this->Count; i++)
	{
		//��ȡ�γ���Ϣ
		ofs << this->COURSE[i]->num << " "
			<< this->COURSE[i]->name << " "
			<< this->COURSE[i]->kind << " "
			<< this->COURSE[i]->stime << " "
			<< this->COURSE[i]->score << " "
			<< this->COURSE[i]->term << " "
			<< this->COURSE[i]->PeopleCount << " ";
		//��ȡѧ����Ϣ
		for (int j = 0; j < this->COURSE[i]->PeopleCount; j++)
		{
			ofs << this->COURSE[i]->Student[j].StuID << " ";
			ofs << this->COURSE[i]->Student[j].StuName << " ";
			ofs << this->COURSE[i]->Student[j].StuSex << " ";
			ofs << this->COURSE[i]->Student[j].StuYear << " ";
			ofs << this->COURSE[i]->Student[j].StuDepartment << " ";
			ofs << this->COURSE[i]->Student[j].StuClass << " ";
			ofs << this->COURSE[i]->Student[j].StuContact << " ";
		}
		ofs << endl;
	}
	ofs.close();
}


//����
void Student::StuOpration(long StuID, string StuName, string StuSex, string StuYear, string StuDepartment, string StuClass, string StuContact)
{

	int x = -1;


loop:	cin >> x;
	switch (x)
	{
	case 1:	//���
		system("cls");
		cout << "***��ѡ���ˣ�1.������пγ���Ϣ***" << endl << endl;
		this->StuPrintCourse();
		system("pause");
		system("cls");
		break;
	case 2:	//��ѯ
	{
		system("cls");
		cout << "***��ѡ���ˣ�2.��ѯָ���γ���Ϣ***" << endl << endl;
		cout << "����������ѯ�γ̵ı��: ";
		cin >> x;
		this->StuSearch(x);
		system("pause");
		system("cls");
	}
	break;
	case 3://�鿴��ѡ
		system("cls");
		cout << "***��ѡ���ˣ�3.�鿴��ѡ***" << endl << endl;
		this->HaveCourse(StuID);
		system("pause");
		system("cls");

		break;
	case 4:	//ѡ��
	{
		system("cls");
		cout << "***��ѡ���ˣ�4.ѡ��***" << endl << endl;
		cout << "������γ̱��: ";
		cin >> x;
		this->StuAdd(x, StuID, StuName, StuSex, StuYear, StuDepartment, StuClass, StuContact);
		this->StuSaveFile();
		system("pause");
		system("cls");
	}
	break;
	case 5:	//�˿�
	{
		system("cls");
		cout << "***��ѡ���ˣ�5.�˿�***" << endl << endl;
		cout << "������γ̱��: ";
		cin >> x;
		this->Studel(x, StuID);

		this->StuSaveFile();
		system("pause");
		system("cls");
	}
	break;
	case 6:	//����
		system("cls");
		cout << "***��ѡ���ˣ�6.�ֶ�����***" << endl << endl;
		this->StuSaveFile();
		system("pause");
		system("cls");
		break;
	case 0:
		if (!CheckStudent(StuID))
		{
			cout << "����δѡ�Σ����˳�ϵͳ���������ݽ���գ�ȷ���˳���" << endl;
			cout << "1->ȷ��" << endl;
			cout << "2->ȡ��" << endl;
			cin >> x;
		}
		if (x == 2)
		{
			cout << "��ȡ��" << endl;
			goto loop;
		}
		cout << "��ӭ���´�ʹ�ã��ټ���" << endl;
		this->StuSaveFile();
		system("pause");
		exit(0);
	default:
		cout << "��������ȷ��������ѡ��ѡ��" << endl;
		goto loop;
		break;

	}


}


Student::~Student()
{
	this->Count = 0;
	delete[] this->COURSE;
}



