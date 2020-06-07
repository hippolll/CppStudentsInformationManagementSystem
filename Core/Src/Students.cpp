////////////////////////////////////////
//includes
#include <Students.h>
#include <fstream>
#include <iostream>
#include <string>
#include <main.h>

using namespace std;


////////////////////////////////////////
//Data management


//function: new a student
//param: struct student
//Use the information in the established struct to new a student, 
//write him to the end of the txt.
void newStudent(Student* student) {

    Student* p = student;

    Student * newStu = new Student;
    newStu->next = new Student;

    //p移动到链表末尾
    while (p->next != NULL) {
        p = p->next;
    }
    
    //给新学生输入信息
    //当输入内容不符合数据类型时程序会崩溃

    int sta;

    do {

        system("cls");

        cout                    //↓18
            << "                学生个人信息                       \n" //0
            << " ╔═══════════════════════════════════════════╗   \n" //1
            << " ║        1.学号:                            ║  \n" //2
            << " ╠═══════════════════════════════════════════╣  \n" //3
            << " ║        2.姓名:                            ║  \n" //4
            << " ╠═══════════════════════════════════════════╣  \n" //5
            << " ║        3.年龄:                            ║  \n" //6
            << " ╠═══════════════════════════════════════════╣  \n" //7
            << " ║        4.职务:                            ║  \n" //8
            << " ╠═══════════════════════════════════════════╣  \n" //9
            << " ║        5.性别:                            ║  \n" //10
            << " ╠═══════════════════════════════════════════╣  \n" //11
            << " ║        6.电话号码:                        ║  \n" //12
            << " ╚═══════════════════════════════════════════╝  " << endl; //13
        cout << "请按照提示信息输入学生的各项信息;" << endl;

        SetCursorPositon(18, 2);
        cin >> newStu->num;
        SetCursorPositon(18, 4);
        cin >> newStu->name;
        SetCursorPositon(18, 6);
        cin >> newStu->age;
        SetCursorPositon(18, 8);
        cin >> newStu->duty;
        SetCursorPositon(18, 10);
        cin >> newStu->sex;
        SetCursorPositon(22, 12);
        cin >> newStu->phoneNum;

        SetCursorPositon(0, 15);

        cout << "请检查你的输入，并确认真的要保存这些信息吗？是请输入1，否请输入2并重新输入，或输入0并回到菜单";
        cin >> sta;

    }while (sta == 2);

    if (sta) {
        //新学生接到链表末尾
        newStu->next = NULL;
        p->next = newStu;
        cout << "新建学生信息成功！";
    }
    else {
        cout << "即将回到菜单";
    }
}


//function: read all the students from the txt and save them in a list
//param: head node of LinkList
//return: the list of all the students
//Read all the information in the txt.
void readTXT(Student* student) {

    cout << "开始读取" << endl;

    //传入参数：链表头结点
    Student* p, * r;
    ifstream file;
    bool sta = 1;
    
    file.open("DataBase\\Students.txt", ios_base::in); //打开数据库文档
    if (!file) {
        //如果打开错误
        cerr << "文件打开错误，程序运行出错，即将退出";
        exit(EXIT_FAILURE);
    }
    
    cout << "读取中……" << endl;

    //建立新链表：尾插法（含有头结点）

    r = student; //r为指向尾部的结点
    
    while(sta){
        p = new Student;
        p->next = new Student;

        file >> p->num >> p->name >> p->duty >> p->sex >> p->age >> p->phoneNum; //读取数据

        r->next = p; //将表尾终端指针指向新结点
        r = p; //将当前的新结点定义为终端结点

        file >> sta; //读入后继状态控制变量，0为文件尾后面没有数据，1为有后继
    }

    r->next = NULL; //表示当前链表结束
    
    file.close(); //关闭文件

    cout << "读取成功";

}


//function: write the list into the file
//param: head node of LinkList
//LinkList: all the information of the students
//Write currrent information int the txt.
void writeTXT(Student* student) {

    cout << "开始保存" << endl;

    //传入参数：链表头结点
    Student* p = student, *q; //p指向第一个学生;
    ofstream file;

    file.open("DataBase\\Students.txt", ios_base::out);
    if (!file) {
        //如果打开错误
        cerr << "文件打开错误，程序运行出错，即将退出";
        exit(EXIT_FAILURE);
    }
    q = p->next;

    cout << "保存中……" << endl;

    while (1) {
        file << q->num << ' ' << q->name << ' ' << q->duty << ' ' << q->sex << ' ' << q->age << ' ' << q->phoneNum << ' ';
        
        p = q;
        q = q->next; //移动到下一个结点

        //判断p当前是否为空，即判断当前输出的数据是否为最后一个学生
        if (q != NULL) {
            //若不是
            file << 1 << endl;
        }
        else {
            //若是
            file << 0 << endl;
            break; //退出输出
        }
    }

    file.close(); //关闭文件

    cout << "保存成功" << endl;

}


//function: find a student
//param: search a student by his num
//return: find the student 
Student* searchStudent(Student* student) {
    
    Student* p = student->next;

    unsigned int num = 0;

    //学生信息查找界面
    //按照各项信息查询和这个函数在架构时的功能不符，先删除，仅保留最开始的按学号查询
    //返回值为查询到的学生的结构体指针

    cout << "请输入要查找的学生的学号：";
    cin >> num;

    while (p != NULL) {
        if (p->num == num) {
            return p;
        }
        else {
            p = p->next;
        }
    }
    
    if (p == NULL) {
        cout << "对不起，无法找到符合条件的学生";
    }

    return NULL;
}


//function: delate students
//param: student's num
//Search a student by his num and delate him
void deleteStudent(Student* student) {
    
    Student* slow = student, * fast = slow->next;
    //双指针移动，其中查找成功后要删除的是慢指针

    bool state = false;

    unsigned int num;
    cout << "请输入要删除的学生的学号：";
    cin >> num;

    while (fast != NULL) {
        if (fast->num == num) {
            state = true;
            break;
        }
        else {
            slow = slow->next;
            fast = fast->next;
        }
    }

    if (!state) {
        cout << "无法找到该学生，删除失败" << endl;
        return;
    }

    slow->next = fast->next; //让慢指针指向快指针的后继元素
    delete fast; //释放快指针动态内存

}


//function: rewrite student's information
//param: student's num
//param: value
//Search a student by his num and rewrite his information.
void rewriteStudent(Student* student) {

    Student* p = searchStudent(student);
    if (p == NULL) {
        return;
    }

    system("cls");

    cout
        << "                学生个人信息                       \n" //0
        << " ╔═══════════════════════════════════════════╗   \n" //1
        << " ║        1.学号:                            ║  \n" //2
        << " ╠═══════════════════════════════════════════╣  \n" //3
        << " ║        2.姓名:                            ║  \n" //4
        << " ╠═══════════════════════════════════════════╣  \n" //5
        << " ║        3.年龄:                            ║  \n" //6
        << " ╠═══════════════════════════════════════════╣  \n" //7
        << " ║        4.职务:                            ║  \n" //8
        << " ╠═══════════════════════════════════════════╣  \n" //9
        << " ║        5.性别:                            ║  \n" //10
        << " ╠═══════════════════════════════════════════╣  \n" //11
        << " ║        6.电话号码:                        ║  \n" //12
        << " ╚═══════════════════════════════════════════╝  " << endl; //13

    SetCursorPositon(18, 2);
    cout << p->num;
    SetCursorPositon(18, 4);
    cout << p->name;
    SetCursorPositon(18, 6);
    cout << p->age;
    SetCursorPositon(18, 8);
    cout << p->duty;
    SetCursorPositon(18, 10);
    cout << p->sex;
    SetCursorPositon(22, 12);
    cout << p->phoneNum;

    SetCursorPositon(0, 14);


    cout << "请按照提示信息重新输入学生的所有信息;" << endl;

    SetCursorPositon(18, 2);
    cin >> p->num;
    SetCursorPositon(18, 4);
    cin >> p->name;
    SetCursorPositon(18, 6);
    cin >> p->age;
    SetCursorPositon(18, 8);
    cin >> p->duty;
    SetCursorPositon(18, 10);
    cin >> p->sex;
    SetCursorPositon(22, 12);
    cin >> p->phoneNum;

    SetCursorPositon(0, 15);

}


//function: rank students
//param: sort by num
void rankStudent(Student* student) {

    cout << "排序中……" << endl;

    //冒泡排序法

    unsigned int week;
    Student* p, * q, * r, * s; //r前指针，p慢指针，q快指针，s进度指示指针
    s = student;

    while (s->next != NULL && s->next->next != NULL) {
        //s->next为NULL，代表student为空链表
        //s->next->next为NULL，代表student中只有一个元素
        week = 1;
        r = s;
        p = r->next;
        q = p->next;
         do {
            if (p->num > q->num) {
                //r p q 变成 r q p
                r->next = q;
                p->next = q->next;
                q->next = p;
                week = 0;
            }
            //r q p _ 变成 _ r p q
            r = r->next;
            p = r->next;
            q = p->next;
        }while (q != NULL && p != NULL);
        if (week) {
            break;
        }
        s = s->next;
    }

    cout << "排序成功！";

}


//function: show all the students
//param: all the information of the students
//Print all the students' informations to the screen
void showAll(Student* student) {

    Student* p;
    p = student->next;
    int pos = 0;

    system("cls");

    cout << "学生信息表";

    cout << endl;
    pos += 1;

    SetCursorPositon(0, pos);
    cout << "学号";
    SetCursorPositon(9, pos);
    cout << "姓名";
    SetCursorPositon(16, pos);
    cout << "职务";
    SetCursorPositon(25, pos);
    cout << "性别";
    SetCursorPositon(30, pos);
    cout << "年龄";
    SetCursorPositon(35, pos);
    cout << "电话";
    
    cout << endl;
    pos += 1;

    do {
        
        SetCursorPositon(0, pos);
        cout << p->num;
        SetCursorPositon(9, pos);
        cout << p->name;
        SetCursorPositon(16, pos);
        cout << p->duty;
        SetCursorPositon(25, pos);
        cout << p->sex;
        SetCursorPositon(30, pos);
        cout << p->age;
        SetCursorPositon(35, pos);
        cout << p->phoneNum;
        
        cout << endl;
        pos += 1;

        p = p->next;

    } while (p != NULL);

}


//function: show one student
//param: the num of the one student
//Print one student to the screen
void showOne(Student* student) {

    system("cls");

    Student* p = searchStudent(student);
    
    if (p == NULL) {
        return;
    }

    system("cls");

    cout
        << "                学生个人信息                       \n" //0
        << " ╔═══════════════════════════════════════════╗   \n" //1
        << " ║        1.学号:                            ║  \n" //2
        << " ╠═══════════════════════════════════════════╣  \n" //3
        << " ║        2.姓名:                            ║  \n" //4
        << " ╠═══════════════════════════════════════════╣  \n" //5
        << " ║        3.年龄:                            ║  \n" //6
        << " ╠═══════════════════════════════════════════╣  \n" //7
        << " ║        4.职务:                            ║  \n" //8
        << " ╠═══════════════════════════════════════════╣  \n" //9
        << " ║        5.性别:                            ║  \n" //10
        << " ╠═══════════════════════════════════════════╣  \n" //11
        << " ║        6.电话号码:                        ║  \n" //12
        << " ╚═══════════════════════════════════════════╝  " << endl; //13

    SetCursorPositon(18, 2);
    cout << p->num;
    SetCursorPositon(18, 4);
    cout << p->name;
    SetCursorPositon(18, 6);
    cout << p->age;
    SetCursorPositon(18, 8);
    cout << p->duty;
    SetCursorPositon(18, 10);
    cout << p->sex;
    SetCursorPositon(22, 12);
    cout << p->phoneNum;

    SetCursorPositon(0, 14);

}