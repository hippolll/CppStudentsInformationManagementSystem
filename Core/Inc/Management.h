#pragma once


////////////////////////////////////
//includes
#include <Students.h>

////////////////////////////////////
//Data
//0: end the system; 1: keep going on 
typedef enum {
	UN_OK = 0,
	OK = 1
}System_State;


////////////////////////////////////
//Function prototype
System_State login();
System_State init(System_State, Student*);
System_State mainMenu(System_State, Student*);
void end(System_State, Student*);

