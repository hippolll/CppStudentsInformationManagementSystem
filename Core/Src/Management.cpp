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

	//用户登录界面


	while (count < 3) {

		system("cls");

		cout 
			<< "请输入用户名和密码\n" //0
			<< "  ﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎  \n"
			<< " ┆                                 ┆\n"
			<< " ┆                                 ┆\n"
			<< " ┆     用户名:                     ┆\n"
			<< " ┆                                 ┆\n" //5
			<< " ┆                                 ┆\n"
			<< " ┆     密码:                       ┆\n"
			<< " ┆                                 ┆\n"
			<< " ┆                                 ┆\n"
			<< " ┆                                 ┆\n" //10
			<< "  ﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊  " << endl;


		if (count) {
			cout << "您还剩下" << 3 - count << "次输入机会" << endl;
		}
		
		SetCursorPositon(15, 4);
		cin >> userName;
		SetCursorPositon(15, 7);
		cin >> password;

		SetCursorPositon(0, 12);
		if (userName != "scut2019") {
			cout << "该用户不存在，请检查是否输入错误\n";
			count++;
		}
		else if (password != "scut123456789") {
			cout << "密码输入错误\n";
			count++;
		}
		else {
			return OK;
		}

		system("pause");

	}

	cout << "对不起，您的输入错误次数过多，系统即将退出……" << endl;

	return UN_OK;
}


//function: init and welcome
//Read the txt and welcome the user.
System_State init(System_State a, Student* student) {
	if (!a) {
		return UN_OK;
	}

	//欢迎界面
	cout
		<< "===========================================\n"
		<< "---------欢迎使用学生信息管理系统！--------\n"
		<< "===========================================\n";
	
	readTXT(student);

	return OK;
}


//function: main menu
System_State mainMenu(System_State a, Student* student) {

	if (!a) {
		return UN_OK;
	}

	//主菜单界面+子菜单界面

	system("cls");

	int menu;

	while (1) {

		cout 
			<< "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
			<< "┃        学生信息管理系统          ┃\n"
			<< "┃                                  ┃\n"
			<< "┃         (请按提示操作)           ┃\n" 
			<< "┃                                  ┃\n" 
			<< "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n" 
			<< "┃                                  ┃\n" 
			<< "┃        1.新增一个学生            ┃\n" 
			<< "┃                                  ┃\n" 
			<< "┃        2.查找指定学生            ┃\n" 
			<< "┃                                  ┃\n" 
			<< "┃        3.修改指定学生信息        ┃\n" 
			<< "┃                                  ┃\n"
			<< "┃        4.删除指定学生信息        ┃\n"
			<< "┃                                  ┃\n" 
			<< "┃        5.对学生进行排序          ┃\n" 
			<< "┃                                  ┃\n" 
			<< "┃        6.显示所有学生数据        ┃\n" 
			<< "┃                                  ┃\n" 
			<< "┃        7.保存当前学生数据        ┃\n" 
			<< "┃                                  ┃\n" 
			<< "┃        0.退出系统                ┃\n" 
			<< "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ " << endl
			<< " 选择你要进行的操作(输入数字即可):";
		cin >> menu;

		int num;

		switch (menu) {
		case 1:
			//新增学生
			newStudent(student);
			break;
		case 2:
			//查找指定学生
			showOne(student);
			break;
		case 3:
			//修改指定学生信息
			rewriteStudent(student);
			break;
		case 5:
			//排序
			rankStudent(student);
			break;
		case 6:
			//显示所有学生信息
			showAll(student);
			break;
		case 7:
			//保存当前操作
			writeTXT(student);
			break;
		case 4:
			//删除指定学生信息
			deleteStudent(student);
			break;
		case 0:  
			cout << "是否保存当前操作？\n输入0不保存直接退出，输入1保存后退出";
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