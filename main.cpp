#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

typedef struct course
{
	unsigned m_number;
	string m_title;    //�γ�����
	string m_time;     //�Ͽ�ʱ��
	string m_libart;   //�γ�����
	string m_teacher;  //�ον�ʦ
	string m_assistant;//���̽�ʦ
	string m_district; //�Ͽΰ༶
	struct course *m_next;
} course;

class Course
{
private :
	course *head;

public :
	Course();
	~Course();
	void entry();
	void adding();
	bool insInfo(const course &cour);
	course *findNum(unsigned num) const;
	course *findTit(const string &tit) const;
	unsigned liber() const;
	unsigned science() const;
	unsigned elseSub() const;
	unsigned total() const;
	bool deleNum();
	bool deleTit();
	void displ() const;
	void query() const;
	void friend statis(const Course &cour);
	void friend dele(Course &cour);
	void friend modify(Course &cour);
	void ending();
};

Course::Course()//����head
{
    head = new course;
    head->m_number = 0;
    head->m_title = "none";
	head->m_time ="none";
	head->m_libart = "none";
	head->m_teacher = "none";
	head->m_assistant = "none";
    head->m_district = "none";
    head->m_next = NULL;
}

Course::~Course()//ɾ������
{
    course *p = head;
    course *q;
    while(p)
    {
        q = p;
        p = q->m_next;
        delete q;
    }
}

string inform()//������Ϣ
{
	string str;
	while(cin.get() != '\n');
	cin >> str;
	return str;
}

course *Course::findNum(unsigned num) const//����Ų�ѯ
{
	course *p;
	for(p = head; p->m_next; p = p->m_next)
    {
		if(p->m_next->m_number == num)
            return p;
    }
	return NULL;
}

course *Course::findTit(const string &tit) const//�����Ʋ�ѯ
{
	course *p;
	for(p = head; p->m_next; p = p->m_next)
    {
		if(p->m_next->m_title == tit)
            return p;
    }
	return NULL;
}

bool Course::insInfo(const course &cour)//������Ϣ
{
	course *newnode;
	course *p = head;
	if(p->m_next == NULL)
    {
		p->m_next = new course(cour);
		p->m_next->m_next = NULL;
		return true;
	}
	while(p->m_next)
	{
		if(p->m_next->m_number == cour.m_number)
		{
			cout << "\t�ظ��ı�ţ�����ʧ��!\n";
			return false;
		}
		if(p->m_next->m_number > cour.m_number)
		{
			newnode = new course(cour);
			newnode->m_next = p->m_next;
			p->m_next = newnode;
			return true;
		}
		p = p->m_next;
	}
	p->m_next = new course(cour);
	p->m_next->m_next = NULL;
	return true;
}

void show(course *p)//չʾ
{
	cout <<"\t" << p->m_number << "\t" << p->m_title << "\t" << p->m_time;
	cout <<"\t" << p->m_libart << "\t " << p->m_teacher;
	cout <<"\t " << p->m_assistant << "\t" << p->m_district << endl;
}

unsigned Course::liber() const//�Ŀ�ͳ��
{
	unsigned cnt = 0;
	course *p;
	for (p = head->m_next; p; p = p->m_next)
    {
		if(p->m_libart == "��")
            ++cnt;
    }
	return cnt;
}

unsigned Course::science() const
{
	unsigned cnt = 0;
	course *p;
	for(p = head->m_next; p; p = p->m_next)
    {
		if(p->m_libart == "��")
            ++cnt;
    }
	return cnt;
}

unsigned Course::elseSub() const
{
	unsigned cnt = 0;
	course *p;
	for(p = head->m_next; p; p = p->m_next)
    {
		if(p->m_libart == "����")
            ++cnt;
    }
	return cnt;
}

unsigned Course::total() const
{
	unsigned cnt = 0;
	course *p;
	for(p = head->m_next; p; p = p->m_next,++cnt);
	return cnt;
}

bool Course::deleNum()
{
	course *q,*p;
	unsigned num;
	cout << "\t����Ҫɾ���γ̵ı��:";
	cin >> num;
	p = findNum(num);
	if(p == NULL)
    {
		cout << "\t�Ҳ������Ϊ\"" << num << "\"�Ŀγ̣�ɾ��ʧ��!\n";
		return false;
	}
	q = p->m_next;
	p->m_next = q->m_next;
	delete q;
	return true;
}

bool Course::deleTit()
{
	course *q,*p;
	string tit;
	cout << "\t����Ҫɾ���γ̵�����:";
	tit = inform();
	p = findTit(tit);
	if(p == NULL)
    {
		cout << "\t�Ҳ�������Ϊ\"" << tit << "\"�Ŀγ̣�ɾ��ʧ��!\n";
		return false;
	}
	q = p->m_next;
	p->m_next = q->m_next;
	delete q;
	return true;
}

int menu()//���˵�
{
	int choice;
	do
    {
		system("cls");
		cout << "\t***********************************\n";
		cout << "\t*---------------------------------*\n";
		cout << "\t*|     ���γ���Ϣ����ϵͳ��      |*\n";
		cout << "\t*|===============================|*\n";
		cout << "\t*|      ��ϵͳ�������¹���       |*\n";
		cout << "\t*|===============================|*\n";
		cout << "\t*|        1��¼��γ���Ϣ        |*\n";
		cout << "\t*|        2����ʾ�γ���Ϣ        |*\n";
		cout << "\t*|        3����ѯ�γ���Ϣ        |*\n";
		cout << "\t*|        4����ӿγ���Ϣ        |*\n";
		cout << "\t*|        5��ͳ�ƿγ���Ϣ        |*\n";
		cout << "\t*|        6��ɾ���γ���Ϣ        |*\n";
		cout << "\t*|        7���޸Ŀγ���Ϣ        |*\n";
		cout << "\t*|        0���˳�����ϵͳ        |*\n";
		cout << "\t*---------------------------------*\n";
		cout << "\t***********************************\n";
		cout << "\n\t��ѡ��";

		cin >> choice;
		if (choice < 0 || choice > 7)
        {
            cout << "\tѡ�����������ѡ��";
            Sleep(2000);
        }
	}while(choice < 0 || choice > 7);

	return choice;
}

void Course::entry()//¼��
{
	course tmp;
	cout << "\t�γ̱��(�γ̱��Ϊ��λ���֣�����0�Է���): ";
	cin >> tmp.m_number;
	while(tmp.m_number)
    {
		if(findNum(tmp.m_number) == NULL)
		{
			cout << "\t�γ�����: ";
			tmp.m_title = inform();
			cout << "\t�Ͽ�ʱ�䣨xx:xx��: ";
			tmp.m_time = inform();
			cout << "\t�γ����ԣ���or��or������: ";
			tmp.m_libart = inform();
			cout << "\t�ο���ʦ: ";
			tmp.m_teacher = inform();
			cout << "\t������ʦ��û����ޡ���: ";
			tmp.m_assistant = inform();
			cout << "\t�Ͽΰ༶: ";
			tmp.m_district = inform();
			insInfo(tmp);
		}
		else
        {
            cout << "\t�ظ��ı��:" << tmp.m_number << "�����������룡" << endl;
        }
		cout << "\t�γ̱��(����0�Է���): ";
		cin >> tmp.m_number;
	}
}

void Course::adding()//���
{
	course tmp;
	cout << "\t�γ̱��(�γ̱��Ϊ��λ���֣�����0�Է���): ";
	cin >> tmp.m_number;
	while(tmp.m_number)
    {
		if(findNum(tmp.m_number) == NULL)
		{
			cout << "\t�γ�����: ";
			tmp.m_title = inform();
			cout << "\t�Ͽ�ʱ�䣨xx:xx��: ";
			tmp.m_time = inform();
			cout << "\t����: ";
			tmp.m_libart = inform();
			cout << "\t�ο���ʦ: ";
			tmp.m_teacher = inform();
			cout << "\t������ʦ��û����ޡ���: ";
			tmp.m_assistant = inform();
			cout << "\t�Ͽΰ༶��: ";
			tmp.m_district = inform();
			insInfo(tmp);
		}
		else
        {
            cout << "\t�ظ��ı��:" << tmp.m_number << "�����������룡" << endl;
        }
        cout << "\t�γ̱��(����0�Է���): ";
        cin >> tmp.m_number;
	}
}

void Course::displ() const//��ʾ
{
	course *p;
    p = head->m_next;

    if (p == NULL)
    {
        cout << "\t----------------------------------------------------------\n";
        cout << "\t\t\t��δ¼���κ���Ϣ��\n";
        cout << "\t----------------------------------------------------------\n";
    }
    else
    {
        cout << "\t--------------------------------------------------------------\n";
        cout << "\t�γ̱��" << "|" << "�γ�����" << "|" << "�Ͽ�ʱ��" << "|";
        cout << "�γ�����" << "|" << "�ο���ʦ" << "|";
        cout << "������ʦ" << "|" << "�Ͽΰ༶" << endl;
        cout << "\t--------------------------------------------------------------\n";
        for( ; p; p = p->m_next)
            show(p);
        cout << "\t--------------------------------------------------------------\n";
    }

	system("pause");
}

void Course::query() const//��ѯ
{
	int select;
	unsigned num;
	string tit;
	course *p;
	cout << "\t1�����γ̱�Ų�ѯ\n\t2�����γ����Ʋ�ѯ\n\t0������\n";
	cout << "\t��ѡ��";
	cin >> select;
	switch(select)
	{
		case 1 :
		    cout << "\t��������:";
		    cin >> num;
			if(p = findNum(num))
                show(p->m_next);
			break;

		case 2 :
		    cout << "\t������γ�����:";
		    tit = inform();
			if(p = findTit(tit))
                show(p->m_next);
			break;

		case 0 : return;

		default : cout << "\t���������޷�ִ�У�\n";
	}
	system("pause");
}

void statis(const Course &cour)//ͳ��
{
	unsigned total = cour.total();
	unsigned liber = cour.liber();
	unsigned science = cour.science();
	unsigned elseSub = cour.elseSub();
	cout << "\t���տγ�������:" << total << "����\n";
	cout << "\t���У��Ŀ���:" << liber << "����\n";
	cout << "\t�����:" << science << "����\n";
    cout << "\t��������:" << elseSub << "����\n";
	system("pause");
}

void dele(Course &cour)//ɾ��
{
	int select;
	cout << "\t1�������ɾ��\n\t2��������ɾ��\n\t0������\n";
	cout << "\t��ѡ��";
	cin >> select;
	switch(select)
	{
		case 1 :
			if (cour.deleNum())
            {
				cout << "\tɾ���ɹ���\n";
            }
			break;

		case 2 :
			if (cour.deleTit())
            {
				cout << "\tɾ���ɹ���\n";
            }
            break;

		case 0 : return;

		default : cout << "\tѡ�����\n";
	}
	system("pause");
}

void modify(Course &cour)//�޸�
{
	int select;
	unsigned num;
	string tit;
	course *p,*q;
	cout << "\t1��������޸�\n\t2���������޸�\n\t0������\n";
	cout << "\t��ѡ��";
	cin >> select;
	switch(select)
	{
		case 1 :
		    cout << "\t�������޸Ķ���ı��:";
		    cin >> num;
			if (p = cour.findNum(num))
            {
				q = p->m_next;
                cout << "\t�޸ĺ�Ŀγ�����: ";
                q->m_title = inform();
                cout << "\t�޸ĺ���Ͽ�ʱ��: ";
                q->m_time = inform();
                cout << "\t�޸ĺ������: ";
                q->m_libart = inform();
                cout << "\t�޸ĺ���ο���ʦ: ";
                q->m_teacher = inform();
                cout << "\t�޸ĺ��������ʦ: ";
                q->m_assistant = inform();
                cout << "\t�޸ĺ���Ͽΰ༶: ";
                q->m_district = inform();
				cout << "\t�ɹ��޸ı��Ϊ " << num << " �Ŀγ���Ϣ��\n";
			}
			if (p == NULL)
                cout << "\t�Ҳ������Ϊ\"" << num << "\"�Ŀγ̣��޸�ʧ��!\n";
			break;

		case 2 :
		    cout << "\t�������޸Ķ���Ŀγ�����:";
		    tit = inform();
			if (p = cour.findTit(tit))
            {
				q = p->m_next;
				cout << "\t�޸ĺ�Ŀγ̱��: ";
                cin >> q->m_number;
                cout << "\t�޸ĺ���Ͽ�ʱ��: ";
                q->m_time = inform();
                cout << "\t�޸ĺ�Ŀγ�����: ";
                q->m_libart = inform();
                cout << "\t�޸ĺ���ο���ʦ: ";
                q->m_teacher = inform();
                cout << "\t�޸ĺ��������ʦ: ";
                q->m_assistant = inform();
                cout << "\t�޸ĺ���Ͽΰ༶: ";
                q->m_district = inform();
				cout << "\t�ɹ��޸�����Ϊ " << tit << " �Ŀγ���Ϣ��\n";
			}
			if (p == NULL)
                cout << "\t�Ҳ�������Ϊ\"" << tit << "\"�Ŀγ̣��޸�ʧ��!\n";
			break;

		case 0 : return;

		default : cout << "\tѡ�����\n";
	}
	system("pause");
}

void Course::ending()//�˳�
{
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t===============================================================\n";
    cout << "\t**                                                           **\n";
    cout << "\t---------------------------------------------------------------\n";
    cout << "\t**         ��л���Ա�ϵͳ��֧�֣���ӭ�´�ʹ�ã��ټ�!         **\n";
    cout << "\t---------------------------------------------------------------\n";
    cout << "\t**                Thank you for your support!                **\n";
    cout << "\t===============================================================\n";
}

int main()
{
	Course m;
	int a;
	do
    {
		a = menu();
		switch(a)
		{
			case 1 : m.entry(); break;
			case 2 : m.displ(); break;
			case 3 : m.query(); break;
			case 4 : m.adding(); break;
			case 5 : statis(m); break;
			case 6 : dele(m); break;
			case 7 : modify(m); break;
			case 0 : m.ending(); break;
			default : cout << "\tѡ�����\n"; break;
		}
	}while(a);
	return 0;
}