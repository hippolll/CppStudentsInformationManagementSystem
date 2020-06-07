///////////////////////////////////
//includes
#include <iostream>
#include <Students.h>
#include <Management.h>
#include <main.h>

using namespace std;


//////////////////////////////////
//Programmes 

//function: user login and logout
System_State login() {
	string userName, password;
	int count = 0;

	//�û���¼����


	while (count < 3) {

		system("cls");

		cout 
			<< "�������û���������\n" //0
			<< "  �m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m  \n"
			<< " ��                                 ��\n"
			<< " ��                                 ��\n"
			<< " ��     �û���:                     ��\n"
			<< " ��                                 ��\n" //5
			<< " ��                                 ��\n"
			<< " ��     ����:                       ��\n"
			<< " ��                                 ��\n"
			<< " ��                                 ��\n"
			<< " ��                                 ��\n" //10
			<< "  �i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i  " << endl;


		if (count) {
			cout << "����ʣ��" << 3 - count << "���������" << endl;
		}
		
		SetCursorPositon(15, 4);
		cin >> userName;
		SetCursorPositon(15, 7);
		cin >> password;

		SetCursorPositon(0, 12);
		if (userName != "scut2019") {
			cout << "���û������ڣ������Ƿ��������\n";
			count++;
		}
		else if (password != "scut123456789") {
			cout << "�����������\n";
			count++;
		}
		else {
			return OK;
		}

		system("pause");

	}

	cout << "�Բ��������������������࣬ϵͳ�����˳�����" << endl;

	return UN_OK;
}


//function: init and welcome
//Read the txt and welcome the user.
System_State init(System_State a, Student* student) {
	if (!a) {
		return UN_OK;
	}

	//��ӭ����
	cout
		<< "===========================================\n"
		<< "---------��ӭʹ��ѧ����Ϣ����ϵͳ��--------\n"
		<< "===========================================\n";
	
	readTXT(student);

	return OK;
}


//function: main menu
System_State mainMenu(System_State a, Student* student) {

	if (!a) {
		return UN_OK;
	}

	//���˵�����+�Ӳ˵�����

	system("cls");

	int menu;

	while (1) {

		cout 
			<< "������������������������������������������������������������������������\n"
			<< "��        ѧ����Ϣ����ϵͳ          ��\n"
			<< "��                                  ��\n"
			<< "��         (�밴��ʾ����)           ��\n" 
			<< "��                                  ��\n" 
			<< "�ǩ���������������������������������������������������������������������\n" 
			<< "��                                  ��\n" 
			<< "��        1.����һ��ѧ��            ��\n" 
			<< "��                                  ��\n" 
			<< "��        2.����ָ��ѧ��            ��\n" 
			<< "��                                  ��\n" 
			<< "��        3.�޸�ָ��ѧ����Ϣ        ��\n" 
			<< "��                                  ��\n"
			<< "��        4.ɾ��ָ��ѧ����Ϣ        ��\n"
			<< "��                                  ��\n" 
			<< "��        5.��ѧ����������          ��\n" 
			<< "��                                  ��\n" 
			<< "��        6.��ʾ����ѧ������        ��\n" 
			<< "��                                  ��\n" 
			<< "��        7.���浱ǰѧ������        ��\n" 
			<< "��                                  ��\n" 
			<< "��        0.�˳�ϵͳ                ��\n" 
			<< "������������������������������������������������������������������������ " << endl
			<< " ѡ����Ҫ���еĲ���(�������ּ���):";
		cin >> menu;

		int num;

		switch (menu) {
		case 1:
			//����ѧ��
			newStudent(student);
			break;
		case 2:
			//����ָ��ѧ��
			showOne(student);
			break;
		case 3:
			//�޸�ָ��ѧ����Ϣ
			rewriteStudent(student);
			break;
		case 5:
			//����
			rankStudent(student);
			break;
		case 6:
			//��ʾ����ѧ����Ϣ
			showAll(student);
			break;
		case 7:
			//���浱ǰ����
			writeTXT(student);
			break;
		case 4:
			//ɾ��ָ��ѧ����Ϣ
			deleteStudent(student);
			break;
		case 0:  
			cout << "�Ƿ񱣴浱ǰ������\n����0������ֱ���˳�������1������˳�";
			cin >> num;
			if (num == 0) {
				a = UN_OK;
			}
			else if (num == 1) {
				a = OK;
			}
			return a;
		}
		system("pause");
		system("cls");
	}

}


//function: final phase
void end(System_State save, Student* student) {

	if (save)
		writeTXT(student);

	Student* p = student, * q;

	while (p != NULL) {
		q = p->next;
		delete p;
		p = q;
	}
}