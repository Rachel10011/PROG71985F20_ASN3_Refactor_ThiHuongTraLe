//Thi Huong Tra Le
//PROG71985F20
//Assignment 3 Refactor 
//Fall 2020

//Feedback from assignment 3: 
//--Structure layout is incorrect
//--you were meant to create an array of students

#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include <stdio.h>
#include <stdlib.h>

void initializeTheListStudent(PSTUDENT pListStudent[], int maxLen)   //set student ;ist to empty 
{
	for (int i = 0; i < maxLen; i++)
	{
		pListStudent[i] = NULL;
	}
}

STUDENT createStudent(char student_number[],char first_name[], char last_name[], char middle_name[])
{
	STUDENT s;
	s.studentNumber = (char*)malloc(strlen(student_number) + 1);
	s.name.firstname = (char*)malloc(strlen(first_name) + 1);
	s.name.lastname = (char*)malloc(strlen(last_name) + 1);
	s.name.middlename = (char*)malloc(strlen(middle_name) + 1);
	
	if (!s.studentNumber||!s.name.firstname || !s.name.lastname || !s.name.middlename)
	{
		fprintf(stderr, "error allocating memory\n");
		exit(1);
	}
	strncpy(s.studentNumber, student_number, strlen(student_number) + 1);
	strncpy(s.name.lastname, last_name, strlen(last_name)+1);
	strncpy(s.name.firstname, first_name, strlen(first_name)+1);
	strncpy(s.name.middlename, middle_name, strlen(middle_name)+1);
	
	 //erase the null character at the end of the string 
	s.studentNumber[strlen(student_number)] = '\0';
	s.name.lastname[strlen(last_name)] = '\0';
	s.name.firstname[strlen(first_name)] = '\0';
	s.name.middlename[strlen(middle_name)] = '\0';
	
	return s;
}

PSTUDENT copyStudent(STUDENT s)
{
	PSTUDENT pCopyStudent = (PSTUDENT)malloc(sizeof(STUDENT));
	if (!pCopyStudent)
	{
		fprintf(stderr, "error allocating memory\n");
		exit(1);
	}

	pCopyStudent->studentNumber = (char*)malloc(strlen(s.studentNumber) + 1); 
	pCopyStudent->name.firstname = (char*)malloc(strlen(s.name.firstname) + 1);
	pCopyStudent->name.lastname = (char*)malloc(strlen(s.name.lastname) + 1);
	pCopyStudent->name.middlename = (char*)malloc(strlen(s.name.middlename) + 1);
	
	if (!pCopyStudent->studentNumber)
	{
		fprintf(stderr, "error allocating memory\n");
		exit(1);
	}
	memset(pCopyStudent->studentNumber, 0, strlen(s.studentNumber) + 1);
	strncpy(pCopyStudent->studentNumber, s.studentNumber, strlen(s.studentNumber));

	memset(pCopyStudent->name.firstname, 0, strlen(s.name.firstname) + 1);
	strncpy(pCopyStudent->name.firstname, s.name.firstname, strlen(s.name.firstname));

	memset(pCopyStudent->name.lastname, 0, strlen(s.name.lastname)+1);
	strncpy(pCopyStudent->name.lastname, s.name.lastname, strlen(s.name.lastname));

	memset(pCopyStudent->name.middlename, 0, strlen(s.name.middlename)+1);
	strncpy(pCopyStudent->name.middlename, s.name.middlename, strlen(s.name.middlename));
	
	return pCopyStudent;
}

void removeStudent(PSTUDENT p_student[], int student_total)    
{
	for (int i = 0; i < student_total; i++)
	{
		free(p_student[i]->studentNumber);
		free(p_student[i]->name.firstname);
		free(p_student[i]->name.lastname);
		free(p_student[i]->name.middlename);
	}
}

void printStudent(PSTUDENT p_student[], int student_total)
{

	for (int i = 0; i <student_total ; i++)
	{

		if (strcmp(p_student[i]->name.middlename, "N/A") != 0)
		{
			printf("%s --- %s, %s %s.\n",
				p_student[i]->studentNumber, p_student[i]->name.lastname, p_student[i]->name.firstname, p_student[i]->name.middlename);
		}
		else
		{
			printf("%s --- %s, %s\n",
				p_student[i]->studentNumber, p_student[i]->name.lastname, p_student[i]->name.firstname);
		}
	}
}
