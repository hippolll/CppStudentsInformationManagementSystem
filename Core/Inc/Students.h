#pragma once


/////////////////////////////////////////
//inlcudes
#include <string>

using namespace std;

////////////////////////////////////////
//Data

//struct: Student's information
//Student.num: identification
struct Student {
    unsigned int num = 0; //Primary key
    string name = "";
    string duty = "";
    unsigned int age = 0;
    string sex = ""; 
    unsigned long long phoneNum = 0;
    Student* next = NULL;
};


//////////////////////////////////////
//Function prototype

void newStudent(Student*);
void readTXT(Student*);
void writeTXT(Student*);
Student* searchStudent(Student*);
void deleteStudent(Student*);
void rewriteStudent(Student*);
void rankStudent(Student*);
void showOne(Student*);
void showAll(Student*);

