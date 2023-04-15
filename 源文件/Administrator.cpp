#include "Administrator.h"

//���캯������ʼ��������ȡ�ļ�����
Administrator::Administrator()
{
	ifstream ifs;	//����������
	ifs.open(FILE, ios::in);	//���ļ�����

	//���򲻿��ļ�����δ���ҵ��ļ�
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->Count = 0;		//�γ���Ϊ0
		this->PeoCou = 0;
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
		this->PeoCou = 0;
		this->COURSE = NULL;
		ifs.close();
		return;
	}
	//������
	else
	{
		this->Count = CourseCount();	 //��ȡ�γ�����
		//����һ��ָ�����飬���鳤��Ϊ�γ�����������COURSEָ�����ָ������
		this->COURSE = new Course * [this->Count];
		this->ReadFile();		//��ȡ�ļ�
		PeoCou = ReadStuList(); //��ȡѧ��
		ifs.close();			//�ر��ļ�
		cout << "�γ���Ϊ: " << Count << endl;
		cout << "����Աϵͳ���ݶ�ȡ�ɹ���" << endl;
	}

}

//��ȡ�������ļ��ڿγ�����
int Administrator::CourseCount()
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


//��ȡ�ļ�
void Administrator::ReadFile()
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
			
			int ReadPeople = 0;	//�Ѷ�ȡ��ѧ���������÷�ͬ��
			//���γ�����ѧ�����򲻶�ȡѧ��
			if (ReadPeople == Cour->PeopleCount)
			{
				goto loop;
			}
			//��ȡѧ����Ϣ
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
				//���Ѷ�ȡ��ѧ����ֹͣ��ȡ
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

//��ӿγ̣�����һ������Ϊ����Ϊ�γ�����+1��ָ�����飬����ӵĿγ��ô��������
void Administrator::Add()
{
	//����һ��ָ������NewCour������Ϊ�γ�����+1
	Course** NewCour = new Course * [this->Count + 1];
	string name;          //�γ�����   
	string stime;            //��ѧʱ   
	string score;            //ѧ��    
	string term;             //����ѧ��   
	string kind;
	Course* Cour = NULL;
	//����γ�������Ϊ0����ԭ�γ�����¼�뵽NewCour��
	if (Count != 0)
	{
		for (int i = 0; i < this->Count; i++)
		{
			NewCour[i] = COURSE[i];
		}
	}
	cout << "����������ӿγ̵�����: ";
	cin >> name;
	cout << "����������ӿγ̵����� " << endl;;
	cout << "a->���޿�" << endl;
	cout << "b->ѡ�޿�" << endl;
	cin >> kind;
	cout << "����������ӿγ̵���ѧʱ: ";
	cin >> stime;
	cout << "����������ӿγ̵�ѧ��: ";
	cin >> score;
	cout << "����������ӿγ̵Ŀ���ѧ��: ";
	cin >> term;
	if (kind == "a")
	{
		if (Count == 0)
		{
			Cour = new Compulsory(1, name, stime, score, term);
		}
		else
		{
			Cour = new Compulsory(this->COURSE[this->Count - 1]->num + 1, name, stime, score, term);
		}

	}
	else
	{
		if (Count == 0)		//��Count==0ʱ
		{
			Cour = new Optional(1, name, stime, score, term);
		}

		/*�������ĵ��жϣ�Count == 0ʱ�������arr�� - 1�������ʳ�ͻ*/

		else
		{	//��ȡ������������һ���γ̵Ĵ��룬��+1������ɾ��ĳ�γ̺�����ӿγ̵��µķ��ʳ�ͻ
			Cour = new Optional(this->COURSE[this->Count - 1]->num + 1, name, stime, score, term);
		}

	}
	NewCour[this->Count] = Cour;	//����ĩβ����Cour
	delete[] this->COURSE;			//�ͷŶ�̬�ռ�
	this->COURSE = NewCour;			//ָ��������
	this->Count++;		//�γ���+1
	cout << "��ӳɹ�" << endl;


}


//����γ���Ϣ��ѧ��
void Administrator::PrintAll()
{

	for (int i = 0; i < this->Count; i++)
	{
		this->COURSE[i]->PrintCourse();
		this->COURSE[i]->PrintStudent();
		
	}

}



//const���η�ֹ���޸���Ϣ
void Administrator::ShowStudent(const list <STUDENT>& StuList)
{
	
	
	list<STUDENT>::iterator Print;
	if (this->PeoCou == 0)
	{
		//delete[] Stu;
		cout << "��¼Ϊ�գ�" << endl;
		return;
	}
	else
	{
		cout << "����ѧ��������Ϣ: " << endl;
		for (list<STUDENT>::const_iterator Print = StuList.begin(); Print != StuList.end(); Print++)
		{
			cout << "-------------------------------------------------------------------------" << endl;
			cout << "ѧ��" << '\t';
			cout << "����" << '\t';
			cout << "�Ա�" << '\t';
			cout << "����" << '\t';
			cout << "ѧ��" << '\t';
			cout << "ϵ��" << '\t';
			cout << "��ϵ��ʽ" << endl;
			cout << (*Print).StuID << '\t';
			cout << (*Print).StuName << '\t';
			cout << (*Print).StuSex << '\t';
			cout << (*Print).StuYear << '\t';
			cout << (*Print).StuDepartment << '\t';
			cout << (*Print).StuClass << '\t';
			cout << (*Print).StuContact << endl;
			cout << "-------------------------------------------------------------------------" << endl;
			cout << endl;
		}
	}




}


int Administrator::ReadStuList()
{

	
	StuList.clear();
	list<STUDENT>::iterator Read;
	int PeoCou = 0;
	int x = 0;
	//�γ̱���
	for (int i = 0; i < this->Count; i++)
	{
		//�����γ�i��ѧ����Ϣ
		for (int j = 0; j < this->COURSE[i]->PeopleCount; j++)
		{
			x = 0;
			//����Stu���Ѵ����ѧ����Ϣ
			for (list<STUDENT>::const_iterator Read = StuList.begin(); Read != StuList.end(); Read++)
			{
				//�ȶ�
				
				if ((*Read).StuID == this->COURSE[i]->Student[j].StuID)
				{
					x = -1;
					break;
				}


			}
			if (x == 0)
			{
			
				StuList.push_back(this->COURSE[i]->Student[j]);

				PeoCou++;
			}

		}

	}
	return PeoCou;
}







void Administrator::Search(long StuID, const list <STUDENT>& StuList)
{

	list<STUDENT>::iterator PrintOne;

	for (list<STUDENT>::const_iterator PrintOne = StuList.begin(); PrintOne != StuList.end(); PrintOne++)
	{
		if ((*PrintOne).StuID == StuID)
		{
			cout << "-------------------------------------------------------------------------" << endl;
			cout << "��ѧ��������Ϣ: " << endl;
			cout << "ѧ��" << '\t';
			cout << "����" << '\t';
			cout << "�Ա�" << '\t';
			cout << "����" << '\t';
			cout << "ϵ��" << '\t';
			cout << "�༶" << '\t';
			cout << "��ϵ��ʽ" << endl;
			cout << (*PrintOne).StuID << '\t';
			cout << (*PrintOne).StuName << '\t';
			cout << (*PrintOne).StuSex << '\t';
			cout << (*PrintOne).StuYear << '\t';
			cout << (*PrintOne).StuDepartment << '\t';
			cout << (*PrintOne).StuClass << '\t';
			cout << (*PrintOne).StuContact << endl;
			cout << endl;
			cout << "��ѧ����ѡ��Ŀγ�Ϊ��";
			for (int i = 0; i < this->Count; i++)
			{
				for (int j = 0; j < this->COURSE[i]->PeopleCount; j++)
				{
					if (this->COURSE[i]->Student[j].StuID == StuID)
					{
						cout<<this->COURSE[i]->name<<" ";
					}
				}
			}
			cout << endl;
			cout << "-------------------------------------------------------------------------" << endl;
			return;
		}
	}
	cout << "��ѧ�������� " << endl;
}


//��ѯ�γ���Ϣ�����ظÿγ��������еĶ�λ
long Administrator::Search(int num)	//������
{

	for (int i = 0; i < this->Count; i++)
	{
		if (this->COURSE[i]->num == num)
		{
			this->COURSE[i]->PrintCourse();
			this->COURSE[i]->PrintStudent();
			return i;
		}
	}
	cout << "��¼Ϊ��!" << endl;
	return -1;
}

//���ѧ��
void Administrator::Add(int num, long StuID)//�����š�ѧ��
{
	string StuName;
	string StuSex;
	string StuYear;
	string StuDepartment;
	string StuClass;
	string StuContact;
	int x = -1;
	//�������пγ�
	for (int i = 0; i < this->Count; i++)
	{
		//�����ڴ˱�ŵĿγ�
		if (this->COURSE[i]->num == num)
		{
			x = i;	//��¼�γ��������е�λ��
			//�����ÿγ���ѧ��ѧ��
			for (int j = 0; j < this->COURSE[i]->PeopleCount; j++)
			{
				//���Ѵ��ڸ�ѧ��
				if (this->COURSE[i]->Student[j].StuID == StuID)
				{
					cout << "��ѧ���Ѵ���" << endl;
					return;
				}
			}
		}

	}
	//�������ڴ˱�ŵĿγ�
	if (x == -1)
	{
		cout << "�γ̱�Ų�����" << endl;
		return;
	}
	//����
	else
	{
		//�������пγ���Ϣ
		for (int i = 0; i < this->Count; i++)
		{
			//��������ѧ����Ϣ�����������γ��Ƿ����и�ѧ��
			for (int j = 0; j < this->COURSE[i]->PeopleCount; j++)
			{
				//���ҵ���ѧ��
				if (this->COURSE[i]->Student[j].StuID == StuID)
				{
					StuName = this->COURSE[i]->Student[j].StuName;
					StuSex = this->COURSE[i]->Student[j].StuSex;
					StuYear = this->COURSE[i]->Student[j].StuYear;
					StuDepartment = this->COURSE[i]->Student[j].StuDepartment;
					StuClass = this->COURSE[i]->Student[j].StuClass;
					StuContact = this->COURSE[i]->Student[j].StuContact;
					this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuID = StuID;
					this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuName = StuName;
					this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuSex = StuSex;
					this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuYear = StuYear;
					this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuDepartment = StuDepartment;
					this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuClass = StuClass;
					this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuContact = StuContact;
					this->COURSE[x]->PeopleCount++;
					cout << "���ѧ���ɹ�" << endl;
					return;
				}
			}

		}


		//COURSE������λ��Ϊx�Ķ����е�ѧ���ṹ�����������һλѧ����
		this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuID = StuID;
		cout << "ѧ����¼�룬�������дѧ����������Ϣ" << endl;
		cout << "������";
		cin >> StuName;
		cout << "�ձ�";
		cin >> StuSex;
		cout << "���䣺";
		cin >> StuYear;
		cout << "ϵ��";
		cin >> StuDepartment;
		cout << "�༶��";
		cin >> StuClass;
		cout << "��ϵ��ʽ��";
		cin >> StuContact;
		this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuName = StuName;
		this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuSex = StuSex;
		this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuYear = StuYear;
		this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuDepartment = StuDepartment;
		this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuClass = StuClass;
		this->COURSE[x]->Student[this->COURSE[x]->PeopleCount].StuContact = StuContact;


		this->COURSE[x]->PeopleCount++;
		cout << "���ѧ���ɹ�" << endl;
	}

};

//ɾ���γ�
void Administrator::del(int x)	//��������λ��
{
	//ѡ��Count-2����Count-1����Ϊ�˱�������Խ��
	//��ɾ���Ŀγ�����������һλ�������踲�ǣ�ֱ���ÿγ�����Count���Լ���ʹ��ȡ�����ÿγ���Ϣ����
	for (int i = x; i < this->Count - 2; i++)	
	{
		COURSE[i] = COURSE[i + 1];
	}
	this->Count--;
	cout << "ɾ���γ̳ɹ�" << endl;
}

//ɾ��ѧ��
void Administrator::del(int num, long StuID)//�����š�ѧ��
{

	int x = -1;

	for (int i = 0; i < this->Count; i++)
	{
		//�γ̱�Ŵ���
		if (this->COURSE[i]->num == num)
		{
			x = i;	//��¼�������е�λ��
			break;
		}

	}

	if (x == -1)
	{
		cout << "�ÿγ̲�����" << endl;
		return ;
	}
	for (int j = 0; j < this->COURSE[x]->PeopleCount; j++)
	{
		//���ҵ���ѧ��
		if (this->COURSE[x]->Student[j].StuID == StuID)
		{
			//����ɾ��
			for (int k = j; k < MAX - 2; k++)
			{
				this->COURSE[x]->Student[k] = this->COURSE[x]->Student[k + 1];
			}
			this->COURSE[x]->PeopleCount--;
			cout << "ɾ���ɹ�" << endl;
			return ;
		}
	}
	//�γ̱�Ŵ��ڡ����鲻����ѧ��
	//��������λ��
	cout << "��¼Ϊ�գ�" << endl;
	return ;
}


//�޸Ŀγ���Ϣ���γ̱�Ų��ɸ�!!!��
void Administrator::Change(int x)	//��������λ��
{


	if (x == -1)
	{
		cout << "�γ̱�Ų�����" << endl;
		return;
	}
	cout << "���������޸Ŀγ̵�����: ";
	cin >> this->COURSE[x]->name;
	cout << "����������ӿγ̵����� " << endl;;
	cout << "a->���޿�" << endl;
	cout << "����->ѡ�޿�" << endl;
	string kind;
	cin >> kind;
	if (kind == "a")
	{
		this->COURSE[x]->kind = "���޿�";
	}
	else
	{
		this->COURSE[x]->kind = "ѡ�޿�";
	}
	cout << "���������޸Ŀγ̵���ѧʱ: ";
	cin >> this->COURSE[x]->stime;
	cout << "���������޸Ŀγ̵�ѧ��: ";
	cin >> this->COURSE[x]->score;
	cout << "���������޸Ŀγ̵Ŀ���ѧ��: ";
	cin >> this->COURSE[x]->term;
	cout << "�޸ĳɹ���" << endl;
}

//��������
void Administrator::SaveFile()
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
		ofs << endl;	//������һ�ſγ���Ϣ������ѧ����Ϣ���󣬻���
						//һ�ſγ���Ϣ������ѧ����Ϣ��ռһ��
	}
	ofs.close();
}


//ѧ�Ų��ɸģ�����
void Administrator::Change(long StuID)	//����ѧ��
{
	string StuName;
	string StuSex;
	string StuYear;
	string StuDepartment;
	string StuClass;
	string StuContact;
	int x = -1;
	cout << "������";
	cin >> StuName;
	cout << "�ձ�";
	cin >> StuSex;
	cout << "���䣺";
	cin >> StuYear;
	cout << "ϵ��";
	cin >> StuDepartment;
	cout << "�༶��";
	cin >> StuClass;
	cout << "��ϵ��ʽ��";
	cin >> StuContact;

	for (int i = 0; i < this->Count; i++)
	{
		for (int j = 0; j < this->COURSE[i]->PeopleCount; j++)
		{
			if (this->COURSE[i]->Student[j].StuID == StuID)
			{
				x = 1;

				this->COURSE[i]->Student[j].StuName = StuName;
				this->COURSE[i]->Student[j].StuSex = StuSex;
				this->COURSE[i]->Student[j].StuYear = StuYear;
				this->COURSE[i]->Student[j].StuDepartment = StuDepartment;
				this->COURSE[i]->Student[j].StuClass = StuClass;
				this->COURSE[i]->Student[j].StuContact = StuContact;
			}
		}


	}
	cout << "�޸�ѧ����Ϣ�ɹ�" << endl;
	return;

	if (x == -1)
	{
		cout << "ѧ��������" << endl;
		return;
	}


}

void Administrator::Opration()
{
	long x = -1;
loop:  cin >> x;
	switch (x)
	{
	case 1:		//�����������
		system("cls");
		cout << "***��ѡ���ˣ�1.���������Ϣ***" << endl << endl;
		cout << "������пγ���Ϣ����ѧ����Ϣ��" << endl;
		cout << "1->�γ�" << endl;
		cout << "2->ѧ��" << endl;
		cin >> x;
		if (x == 1)
		{
			this->PrintAll();
		}
		else
		{
			this->ShowStudent(StuList);
		}
		system("pause");
		system("cls");


		break;
	case 2:		//��ѯĳ�γ�
	{
		system("cls");
		cout << "***��ѡ���ˣ�2.��ѯָ����Ϣ***" << endl << endl;
		cout << "��ѯָ���γ���Ϣ����ѧ����Ϣ��" << endl;
		cout << "1->�γ�" << endl;
		cout << "2->ѧ��" << endl;
		cin >> x;
		if (x == 1)
		{
			cout << "����������ѯ�γ̵ı��: ";
			int num;
			cin >> num;
			this->Search(num);

		}
		else
		{
			cout << "����������ѯѧ����ѧ��: ";
			cin >> x;
			this->Search(x, StuList);
			//this->ReadSStu();
		}
		system("pause");
		system("cls");
	}

	break;
	case 3:		//��ӿγ�
		system("cls");
		cout << "***��ѡ���ˣ�3.��ӿγ�***" << endl << endl;
		this->Add();
		this->SaveFile();
		system("pause");
		system("cls");
		break;
	case 4:
		system("cls");
		cout << "***��ѡ���ˣ�4.��γ������ѧ��***" << endl << endl;

		long StuID;
		cout << "������γ̱��: ";
		cin >> x;
		cout << "������ѧ��ѧ��: ";

		cin >> StuID;
		this->Add(x, StuID);
		this->SaveFile();
		this->PeoCou = ReadStuList();
		system("pause");
		system("cls");


		break;
	case 5:		//�޸Ŀγ̻�ѧ��
		system("cls");
		cout << "***��ѡ���ˣ�5.�޸Ŀγ̻�ѧ����Ϣ***" << endl << endl;
		cout << "�޸Ŀγ̻���ѧ����" << endl;
		cout << "1->�γ�" << endl;
		cout << "2->ѧ��" << endl;
		cin >> x;
		if (x == 1)
		{
			cout << "������γ̱��: ";
			int num;
			cin >> num;
			num = this->Search(num);
			this->Change(num);

		}
		else
		{
			long StuID;
			cout << "������ѧ��ѧ��: ";
			cin >> StuID;
			this->Change(StuID);
		}
		this->SaveFile();
		this->PeoCou = ReadStuList();
		system("pause");
		system("cls");
		break;
	case 6:
		system("cls");
		cout << "***��ѡ���ˣ�6.ɾ���γ̻�ѧ����Ϣ***" << endl << endl;
		cout << "ɾ���γ̻���ѧ����" << endl;
		cout << "1->�γ�" << endl;
		cout << "2->ѧ��" << endl;
		cin >> x;
		if (x == 1)
		{
			cout << "������γ̱��: ";
			int num;
			cin >> num;
			int Location;
			Location = this->Search(num);	//��ȡ����λ��
			this->del(Location);

		}
		else
		{
			int num;
			long StuID;
			cout << "������γ̱��: ";
			cin >> num;

			cout << "������ѧ��ѧ��: ";
			cin >> StuID;
			this->del(num, StuID);

		}
		this->SaveFile();
		this->PeoCou=ReadStuList();
		system("pause");
		system("cls");
		break;
	case 7:
		system("cls");
		cout << "***��ѡ���ˣ�7.ͳ�������Ϣ" << endl;
		cout << "��ѡ��ͳ�Ƶ���Ϣ��" << endl;
		cout << "1->�γ̵�����" << endl;
		cout << "2->ѧ��������" << endl;
		cout << "3->ѡ��ĳ�ſγ̵�ѧ������" << endl;

		cin >> x;
		if (x == 1)
		{
			cout << "�γ̵�����Ϊ��" << this->Count << "��" << endl;
		}
		else if (x == 2)
		{
			cout << "ѧ��������Ϊ��" << this->PeoCou << "��" << endl;
		}

		else
		{
			int num;
			cout << "������γ̱��: ";
			cin >> num;
			cout << endl;
			cout << "ѡ�޸ÿγ̵�ѧ������Ϊ��" <<this->COURSE[this->Search(num)]->PeopleCount<<"��"<< endl;
			

		}
		system("pause");
		system("cls");
		break;
	case 8:
		system("cls");
		cout << "***��ѡ���ˣ�8.�ֶ�����***" << endl << endl;
		this->SaveFile();
		system("pause");
		system("cls");
		break;
	case 9:
		system("cls");
		cout << "***��ѡ���ˣ�9.��ʽ��(���ֶ�����)***" << endl << endl;
		this->Count = 0;	//�γ�����ֵΪ0��ʹ�ö�ȡ�����γ�����
		StuList.clear();
		cout << "��ʽ���ɹ������ֶ�����" << endl;
		system("pause");
		system("cls");
		break;
	case 0:
		cout << "��ӭ���´�ʹ�ã��ټ���" << endl;
		this->SaveFile();
		system("pause");
		exit(0);
		break;
	default:
		cout << "��������ȷ��������ѡ��ѡ��" << endl;
		goto loop;
		break;
	}
};


Administrator::~Administrator()
{
	this->Count = 0;
	this->PeoCou = 0;
	delete[] this->COURSE;
}