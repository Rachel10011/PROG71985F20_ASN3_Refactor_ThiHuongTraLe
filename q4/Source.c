//Thi Huong Tra Le
//PROG71985F20
//Assignment 3 Refactor 
//Fall 2020

//Feedback from assignment 3: 
//--Structure layout is incorrect
//--you were meant to create an array of students

#include <stdio.h>
#include "student.h"
#include <string.h>

int main(void)
{
	PSTUDENT pStudent[STUDENTNUM];

	initializeTheListStudent(pStudent, STUDENTNUM);

	STUDENT student1 = createStudent("2001021234", "Rachel", "Le", "N/A");
	STUDENT student2 = createStudent("1996030000", "Levi", "Valenzuela", "Ranjan");
	STUDENT student3 = createStudent("2001123399", "Mia", "Le", "Nguyen");
	STUDENT student4 = createStudent("1999050987", "Jenna", "Valenzuela", "Gabon");
	STUDENT student5 = createStudent("2000086547", "Jason", "Gobna", "N/A");

	pStudent[0] = copyStudent(student1);
	pStudent[1] = copyStudent(student2);
	pStudent[2] = copyStudent(student3);
	pStudent[3] = copyStudent(student4);
	pStudent[4] = copyStudent(student5);
	
	printStudent(pStudent, STUDENTNUM);
	removeStudent(pStudent, STUDENTNUM);

	return 0;
}