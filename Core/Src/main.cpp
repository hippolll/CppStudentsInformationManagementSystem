#include <iostream>
#include <Students.h>
#include <Management.h>
#include <Windows.h>

using namespace std;

int main() {    

    Student* student = new Student;
    student->next = new Student;

    end(mainMenu(init(login(), student), student), student);
    
}

void SetCursorPositon(int x, int y) {
	//横轴是x，纵轴是y，左上角为（0，0）点，正方向是向右和向下
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(handle, coord);
}
