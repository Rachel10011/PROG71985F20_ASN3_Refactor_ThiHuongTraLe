//Thi Huong Tra Le
//PROG71985F20
//Assignment 3 Refactor 
//Fall 2020

//Feedback from assignment 3: 
//--Structure layout is incorrect
//--you were meant to create an array of students

#pragma once
#define MAXSTRLEN 20
#define MAXNUMLEN 11
#define STUDENTNUM 5
 
typedef struct studentName
{
	char* firstname;
	char* lastname;
	char* middlename;
}NAME, *PNAME;


typedef struct student {
	char* studentNumber;
	NAME name;				//nested structure
}STUDENT, *PSTUDENT;


STUDENT createStudent(char[], char[], char[], char[]);
PSTUDENT copyStudent(STUDENT);
void initializeTheListStudent(PSTUDENT[], int);
void printStudent(PSTUDENT [], int);
void removeStudent(PSTUDENT[], int);

  
