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

    //p�ƶ�������ĩβ
    while (p->next != NULL) {
        p = p->next;
    }
    
    //����ѧ��������Ϣ
    //���������ݲ�������������ʱ��������

    int sta;

    do {

        system("cls");

        cout                    //��18
            << "                ѧ��������Ϣ                       \n" //0
            << " �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[   \n" //1
            << " �U        1.ѧ��:                            �U  \n" //2
            << " �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g  \n" //3
            << " �U        2.����:                            �U  \n" //4
            << " �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g  \n" //5
            << " �U        3.����:                            �U  \n" //6
            << " �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g  \n" //7
            << " �U        4.ְ��:                            �U  \n" //8
            << " �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g  \n" //9
            << " �U        5.�Ա�:                            �U  \n" //10
            << " �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g  \n" //11
            << " �U        6.�绰����:                        �U  \n" //12
            << " �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a  " << endl; //13
        cout << "�밴����ʾ��Ϣ����ѧ���ĸ�����Ϣ;" << endl;

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

        cout << "����������룬��ȷ�����Ҫ������Щ��Ϣ����������1����������2���������룬������0���ص��˵�";
        cin >> sta;

    }while (sta == 2);

    if (sta) {
        //��ѧ���ӵ�����ĩβ
        newStu->next = NULL;
        p->next = newStu;
        cout << "�½�ѧ����Ϣ�ɹ���";
    }
    else {
        cout << "�����ص��˵�";
    }
}


//function: read all the students from the txt and save them in a list
//param: head node of LinkList
//return: the list of all the students
//Read all the information in the txt.
void readTXT(Student* student) {

    cout << "��ʼ��ȡ" << endl;

    //�������������ͷ���
    Student* p, * r;
    ifstream file;
    bool sta = 1;
    
    file.open("DataBase\\Students.txt", ios_base::in); //�����ݿ��ĵ�
    if (!file) {
        //����򿪴���
        cerr << "�ļ��򿪴��󣬳������г��������˳�";
        exit(EXIT_FAILURE);
    }
    
    cout << "��ȡ�С���" << endl;

    //����������β�巨������ͷ��㣩

    r = student; //rΪָ��β���Ľ��
    
    while(sta){
        p = new Student;
        p->next = new Student;

        file >> p->num >> p->name >> p->duty >> p->sex >> p->age >> p->phoneNum; //��ȡ����

        r->next = p; //����β�ն�ָ��ָ���½��
        r = p; //����ǰ���½�㶨��Ϊ�ն˽��

        file >> sta; //������״̬���Ʊ�����0Ϊ�ļ�β����û�����ݣ�1Ϊ�к��
    }

    r->next = NULL; //��ʾ��ǰ�������
    
    file.close(); //�ر��ļ�

    cout << "��ȡ�ɹ�";

}


//function: write the list into the file
//param: head node of LinkList
//LinkList: all the information of the students
//Write currrent information int the txt.
void writeTXT(Student* student) {

    cout << "��ʼ����" << endl;

    //�������������ͷ���
    Student* p = student, *q; //pָ���һ��ѧ��;
    ofstream file;

    file.open("DataBase\\Students.txt", ios_base::out);
    if (!file) {
        //����򿪴���
        cerr << "�ļ��򿪴��󣬳������г��������˳�";
        exit(EXIT_FAILURE);
    }
    q = p->next;

    cout << "�����С���" << endl;

    while (1) {
        file << q->num << ' ' << q->name << ' ' << q->duty << ' ' << q->sex << ' ' << q->age << ' ' << q->phoneNum << ' ';
        
        p = q;
        q = q->next; //�ƶ�����һ�����

        //�ж�p��ǰ�Ƿ�Ϊ�գ����жϵ�ǰ����������Ƿ�Ϊ���һ��ѧ��
        if (q != NULL) {
            //������
            file << 1 << endl;
        }
        else {
            //����
            file << 0 << endl;
            break; //�˳����
        }
    }

    file.close(); //�ر��ļ�

    cout << "����ɹ�" << endl;

}


//function: find a student
//param: search a student by his num
//return: find the student 
Student* searchStudent(Student* student) {
    
    Student* p = student->next;

    unsigned int num = 0;

    //ѧ����Ϣ���ҽ���
    //���ո�����Ϣ��ѯ����������ڼܹ�ʱ�Ĺ��ܲ�������ɾ�����������ʼ�İ�ѧ�Ų�ѯ
    //����ֵΪ��ѯ����ѧ���Ľṹ��ָ��

    cout << "������Ҫ���ҵ�ѧ����ѧ�ţ�";
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
        cout << "�Բ����޷��ҵ�����������ѧ��";
    }

    return NULL;
}


//function: delate students
//param: student's num
//Search a student by his num and delate him
void deleteStudent(Student* student) {
    
    Student* slow = student, * fast = slow->next;
    //˫ָ���ƶ������в��ҳɹ���Ҫɾ��������ָ��

    bool state = false;

    unsigned int num;
    cout << "������Ҫɾ����ѧ����ѧ�ţ�";
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
        cout << "�޷��ҵ���ѧ����ɾ��ʧ��" << endl;
        return;
    }

    slow->next = fast->next; //����ָ��ָ���ָ��ĺ��Ԫ��
    delete fast; //�ͷſ�ָ�붯̬�ڴ�

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
        << "                ѧ��������Ϣ                       \n" //0
        << " �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[   \n" //1
        << " �U        1.ѧ��:                            �U  \n" //2
        << " �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g  \n" //3
        << " �U        2.����:                            �U  \n" //4
        << " �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g  \n" //5
        << " �U        3.����:                            �U  \n" //6
        << " �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g  \n" //7
        << " �U        4.ְ��:                            �U  \n" //8
        << " �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g  \n" //9
        << " �U        5.�Ա�:                            �U  \n" //10
        << " �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g  \n" //11
        << " �U        6.�绰����:                        �U  \n" //12
        << " �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a  " << endl; //13

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


    cout << "�밴����ʾ��Ϣ��������ѧ����������Ϣ;" << endl;

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

    cout << "�����С���" << endl;

    //ð������

    unsigned int week;
    Student* p, * q, * r, * s; //rǰָ�룬p��ָ�룬q��ָ�룬s����ָʾָ��
    s = student;

    while (s->next != NULL && s->next->next != NULL) {
        //s->nextΪNULL������studentΪ������
        //s->next->nextΪNULL������student��ֻ��һ��Ԫ��
        week = 1;
        r = s;
        p = r->next;
        q = p->next;
         do {
            if (p->num > q->num) {
                //r p q ��� r q p
                r->next = q;
                p->next = q->next;
                q->next = p;
                week = 0;
            }
            //r q p _ ��� _ r p q
            r = r->next;
            p = r->next;
            q = p->next;
        }while (q != NULL && p != NULL);
        if (week) {
            break;
        }
        s = s->next;
    }

    cout << "����ɹ���";

}


//function: show all the students
//param: all the information of the students
//Print all the students' informations to the screen
void showAll(Student* student) {

    Student* p;
    p = student->next;
    int pos = 0;

    system("cls");

    cout << "ѧ����Ϣ��";

    cout << endl;
    pos += 1;

    SetCursorPositon(0, pos);
    cout << "ѧ��";
    SetCursorPositon(9, pos);
    cout << "����";
    SetCursorPositon(16, pos);
    cout << "ְ��";
    SetCursorPositon(25, pos);
    cout << "�Ա�";
    SetCursorPositon(30, pos);
    cout << "����";
    SetCursorPositon(35, pos);
    cout << "�绰";
    
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
        << "                ѧ��������Ϣ                       \n" //0
        << " �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[   \n" //1
        << " �U        1.ѧ��:                            �U  \n" //2
        << " �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g  \n" //3
        << " �U        2.����:                            �U  \n" //4
        << " �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g  \n" //5
        << " �U        3.����:                            �U  \n" //6
        << " �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g  \n" //7
        << " �U        4.ְ��:                            �U  \n" //8
        << " �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g  \n" //9
        << " �U        5.�Ա�:                            �U  \n" //10
        << " �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g  \n" //11
        << " �U        6.�绰����:                        �U  \n" //12
        << " �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a  " << endl; //13

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