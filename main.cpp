#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

typedef struct course
{
	unsigned m_number;
	string m_title;    //课程名称
	string m_time;     //上课时间
	string m_libart;   //课程属性
	string m_teacher;  //任课教师
	string m_assistant;//助教教师
	string m_district; //上课班级
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

Course::Course()//创建head
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

Course::~Course()//删除链表
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

string inform()//输入信息
{
	string str;
	while(cin.get() != '\n');
	cin >> str;
	return str;
}

course *Course::findNum(unsigned num) const//按编号查询
{
	course *p;
	for(p = head; p->m_next; p = p->m_next)
    {
		if(p->m_next->m_number == num)
            return p;
    }
	return NULL;
}

course *Course::findTit(const string &tit) const//按名称查询
{
	course *p;
	for(p = head; p->m_next; p = p->m_next)
    {
		if(p->m_next->m_title == tit)
            return p;
    }
	return NULL;
}

bool Course::insInfo(const course &cour)//插入信息
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
			cout << "\t重复的编号，插入失败!\n";
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

void show(course *p)//展示
{
	cout <<"\t" << p->m_number << "\t" << p->m_title << "\t" << p->m_time;
	cout <<"\t" << p->m_libart << "\t " << p->m_teacher;
	cout <<"\t " << p->m_assistant << "\t" << p->m_district << endl;
}

unsigned Course::liber() const//文科统计
{
	unsigned cnt = 0;
	course *p;
	for (p = head->m_next; p; p = p->m_next)
    {
		if(p->m_libart == "文")
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
		if(p->m_libart == "理")
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
		if(p->m_libart == "其他")
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
	cout << "\t输入要删除课程的编号:";
	cin >> num;
	p = findNum(num);
	if(p == NULL)
    {
		cout << "\t找不到编号为\"" << num << "\"的课程，删除失败!\n";
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
	cout << "\t输入要删除课程的名称:";
	tit = inform();
	p = findTit(tit);
	if(p == NULL)
    {
		cout << "\t找不到名称为\"" << tit << "\"的课程，删除失败!\n";
		return false;
	}
	q = p->m_next;
	p->m_next = q->m_next;
	delete q;
	return true;
}

int menu()//主菜单
{
	int choice;
	do
    {
		system("cls");
		cout << "\t***********************************\n";
		cout << "\t*---------------------------------*\n";
		cout << "\t*|     【课程信息管理系统】      |*\n";
		cout << "\t*|===============================|*\n";
		cout << "\t*|      本系统包含以下功能       |*\n";
		cout << "\t*|===============================|*\n";
		cout << "\t*|        1、录入课程信息        |*\n";
		cout << "\t*|        2、显示课程信息        |*\n";
		cout << "\t*|        3、查询课程信息        |*\n";
		cout << "\t*|        4、添加课程信息        |*\n";
		cout << "\t*|        5、统计课程信息        |*\n";
		cout << "\t*|        6、删除课程信息        |*\n";
		cout << "\t*|        7、修改课程信息        |*\n";
		cout << "\t*|        0、退出管理系统        |*\n";
		cout << "\t*---------------------------------*\n";
		cout << "\t***********************************\n";
		cout << "\n\t请选择：";

		cin >> choice;
		if (choice < 0 || choice > 7)
        {
            cout << "\t选择错误，请重新选择！";
            Sleep(2000);
        }
	}while(choice < 0 || choice > 7);

	return choice;
}

void Course::entry()//录入
{
	course tmp;
	cout << "\t课程编号(课程编号为四位数字；输入0以返回): ";
	cin >> tmp.m_number;
	while(tmp.m_number)
    {
		if(findNum(tmp.m_number) == NULL)
		{
			cout << "\t课程名称: ";
			tmp.m_title = inform();
			cout << "\t上课时间（xx:xx）: ";
			tmp.m_time = inform();
			cout << "\t课程属性（文or理or其他）: ";
			tmp.m_libart = inform();
			cout << "\t任课老师: ";
			tmp.m_teacher = inform();
			cout << "\t助教老师（没有填“无”）: ";
			tmp.m_assistant = inform();
			cout << "\t上课班级: ";
			tmp.m_district = inform();
			insInfo(tmp);
		}
		else
        {
            cout << "\t重复的编号:" << tmp.m_number << "，请重新输入！" << endl;
        }
		cout << "\t课程编号(输入0以返回): ";
		cin >> tmp.m_number;
	}
}

void Course::adding()//添加
{
	course tmp;
	cout << "\t课程编号(课程编号为四位数字；输入0以返回): ";
	cin >> tmp.m_number;
	while(tmp.m_number)
    {
		if(findNum(tmp.m_number) == NULL)
		{
			cout << "\t课程名称: ";
			tmp.m_title = inform();
			cout << "\t上课时间（xx:xx）: ";
			tmp.m_time = inform();
			cout << "\t属性: ";
			tmp.m_libart = inform();
			cout << "\t任课老师: ";
			tmp.m_teacher = inform();
			cout << "\t助教老师（没有填“无”）: ";
			tmp.m_assistant = inform();
			cout << "\t上课班级）: ";
			tmp.m_district = inform();
			insInfo(tmp);
		}
		else
        {
            cout << "\t重复的编号:" << tmp.m_number << "，请重新输入！" << endl;
        }
        cout << "\t课程编号(输入0以返回): ";
        cin >> tmp.m_number;
	}
}

void Course::displ() const//显示
{
	course *p;
    p = head->m_next;

    if (p == NULL)
    {
        cout << "\t----------------------------------------------------------\n";
        cout << "\t\t\t尚未录入任何信息！\n";
        cout << "\t----------------------------------------------------------\n";
    }
    else
    {
        cout << "\t--------------------------------------------------------------\n";
        cout << "\t课程编号" << "|" << "课程名称" << "|" << "上课时间" << "|";
        cout << "课程属性" << "|" << "任课老师" << "|";
        cout << "助教老师" << "|" << "上课班级" << endl;
        cout << "\t--------------------------------------------------------------\n";
        for( ; p; p = p->m_next)
            show(p);
        cout << "\t--------------------------------------------------------------\n";
    }

	system("pause");
}

void Course::query() const//查询
{
	int select;
	unsigned num;
	string tit;
	course *p;
	cout << "\t1、按课程编号查询\n\t2、按课程名称查询\n\t0、返回\n";
	cout << "\t请选择：";
	cin >> select;
	switch(select)
	{
		case 1 :
		    cout << "\t请输入编号:";
		    cin >> num;
			if(p = findNum(num))
                show(p->m_next);
			break;

		case 2 :
		    cout << "\t请输入课程名称:";
		    tit = inform();
			if(p = findTit(tit))
                show(p->m_next);
			break;

		case 0 : return;

		default : cout << "\t操作错误，无法执行！\n";
	}
	system("pause");
}

void statis(const Course &cour)//统计
{
	unsigned total = cour.total();
	unsigned liber = cour.liber();
	unsigned science = cour.science();
	unsigned elseSub = cour.elseSub();
	cout << "\t今日课程数量共:" << total << "个。\n";
	cout << "\t其中，文科有:" << liber << "个。\n";
	cout << "\t理科有:" << science << "个。\n";
    cout << "\t其他科有:" << elseSub << "个。\n";
	system("pause");
}

void dele(Course &cour)//删除
{
	int select;
	cout << "\t1、按编号删除\n\t2、按名称删除\n\t0、返回\n";
	cout << "\t请选择：";
	cin >> select;
	switch(select)
	{
		case 1 :
			if (cour.deleNum())
            {
				cout << "\t删除成功！\n";
            }
			break;

		case 2 :
			if (cour.deleTit())
            {
				cout << "\t删除成功！\n";
            }
            break;

		case 0 : return;

		default : cout << "\t选择错误！\n";
	}
	system("pause");
}

void modify(Course &cour)//修改
{
	int select;
	unsigned num;
	string tit;
	course *p,*q;
	cout << "\t1、按编号修改\n\t2、按名称修改\n\t0、返回\n";
	cout << "\t请选择：";
	cin >> select;
	switch(select)
	{
		case 1 :
		    cout << "\t请输入修改对象的编号:";
		    cin >> num;
			if (p = cour.findNum(num))
            {
				q = p->m_next;
                cout << "\t修改后的课程名称: ";
                q->m_title = inform();
                cout << "\t修改后的上课时间: ";
                q->m_time = inform();
                cout << "\t修改后的文理: ";
                q->m_libart = inform();
                cout << "\t修改后的任课老师: ";
                q->m_teacher = inform();
                cout << "\t修改后的助教老师: ";
                q->m_assistant = inform();
                cout << "\t修改后的上课班级: ";
                q->m_district = inform();
				cout << "\t成功修改编号为 " << num << " 的课程信息。\n";
			}
			if (p == NULL)
                cout << "\t找不到编号为\"" << num << "\"的课程，修改失败!\n";
			break;

		case 2 :
		    cout << "\t请输入修改对象的课程名称:";
		    tit = inform();
			if (p = cour.findTit(tit))
            {
				q = p->m_next;
				cout << "\t修改后的课程编号: ";
                cin >> q->m_number;
                cout << "\t修改后的上课时间: ";
                q->m_time = inform();
                cout << "\t修改后的课程属性: ";
                q->m_libart = inform();
                cout << "\t修改后的任课老师: ";
                q->m_teacher = inform();
                cout << "\t修改后的助教老师: ";
                q->m_assistant = inform();
                cout << "\t修改后的上课班级: ";
                q->m_district = inform();
				cout << "\t成功修改名称为 " << tit << " 的课程信息。\n";
			}
			if (p == NULL)
                cout << "\t找不到名称为\"" << tit << "\"的课程，修改失败!\n";
			break;

		case 0 : return;

		default : cout << "\t选择错误！\n";
	}
	system("pause");
}

void Course::ending()//退出
{
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t===============================================================\n";
    cout << "\t**                                                           **\n";
    cout << "\t---------------------------------------------------------------\n";
    cout << "\t**         感谢您对本系统的支持，欢迎下次使用，再见!         **\n";
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
			default : cout << "\t选择错误。\n"; break;
		}
	}while(a);
	return 0;
}