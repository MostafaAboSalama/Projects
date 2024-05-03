#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Student/student.h"
#include "admin.h"
#include "../../Data_Access/Memory_Management/memory_management.h"
#include "../../Data_Access/File_Access/file_access.h"

int cpy_numStudents=0; 
extern char adminPassword[];

void BADMIN_changeAdminPassword(){
	DFILE_readAdminPassword();
	char currentPassword[MAX_PASSWORD_LENGTH];
	char newPassword[MAX_PASSWORD_LENGTH];

	printf("Enter current password : ");
	scanf("%s",currentPassword);
	if (strcmp(currentPassword, adminPassword) != 0)
	{
	printf("Incorrect current password. Password not changed.\n");
	}
	else
	{
	printf("Enter the new password : ");
	scanf("%s",newPassword);
	while(strlen(newPassword) < 4)
	{
		printf("Password too short *it should be atleast 4 characters*\n");
		printf("Enter the new password : ");
	    scanf("%s",newPassword);
	}
	if(strcmp(newPassword, adminPassword) == 0)
	{
		printf("You entered your current password \nPassword unchanged\n");
	}else
	{
	printf("Password updated successfully\n");
	strcpy(adminPassword, newPassword);
	DFILE_writeAdminPassword();
	}
	}
	return ;
	}

void BADMIN_addNewStudent(){
	
	DFILE_readNumberOfStudents();
	DFILE_readStudentData();

	void DMEMORY_allocateStudent();

	printf("Enter the details of the new student:\n");

	int cpy_studentNumber = cpy_numStudents ;

	printf("Enter the name:");
	scanf("%s",students[cpy_studentNumber].name);
	printf("Enter the age:");
	scanf("%d",&students[cpy_studentNumber].age);
	printf("Enter ID number:");
	scanf("%d",&students[cpy_studentNumber].id);
	for(int cpy_counter = 0 ; cpy_counter < cpy_numStudents ; cpy_counter ++)
	{
		if(students[cpy_studentNumber].id == students[cpy_counter].id)
		{
			printf ("This id already exists\n");
			printf("Enter ID number:");
	        scanf("%d",&students[cpy_studentNumber].id);
		}
	}		
	printf("Enter student Grade:");
	scanf("%f",&students[cpy_studentNumber].grade);
	while( students[cpy_studentNumber].grade < 0 || students[cpy_studentNumber].grade > 100 )
	{
		printf("The Grade must be between 0 and 100\n");
		printf("Enter student Grade:");
	    scanf("%f",&students[cpy_studentNumber].grade);
	}
	printf("Enter student's new password:");
	scanf("%s",students[cpy_studentNumber].password);
	while(strlen(students[cpy_studentNumber].password) < 4 )
	{
		printf("The password should be atleast 4 characters\n");
		printf("Enter student's new password:");
	    scanf("%s",students[cpy_studentNumber].password);
	}
	printf("\n");
	printf("Student added successfully\n");
	DFILE_writeStudentData();
	cpy_numStudents ++ ;
	DFILE_writeNumberOfStudents();
	}

void BADMIN_deleteStudent()
{
	DFILE_readStudentData();
	DFILE_readNumberOfStudents();
	int cpy_temp;
	int cpy_found=0;
	printf("Enter the ID number of the student\n");
	scanf("%d", &cpy_temp);
	for (int cpy_firstCounter = 0; cpy_firstCounter < cpy_numStudents; cpy_firstCounter++)
	{
	if (cpy_temp == students[cpy_firstCounter].id)
	{
	cpy_found ++ ;	
	for (int cpy_secondCounter = cpy_firstCounter; cpy_secondCounter < cpy_numStudents; cpy_secondCounter++)
	{
	students[cpy_secondCounter] = students[cpy_secondCounter + 1];
	}
	cpy_numStudents --;
	DMEMORY_freeStudent(&students[cpy_firstCounter]);
	DFILE_writeStudentData ();
	DFILE_writeNumberOfStudents();
	printf("The entered student's records are deleted successfully\n");
	}
	}
	if(cpy_found == 0)
	{
		printf("Student not found\n");
	}
}
void BADMIN_editStudentGrade()
{
	DFILE_readStudentData();
	DFILE_readNumberOfStudents();
	int cpy_temp;
	float buffer ;
	int cpy_found = 0;
	printf("Enter the ID number of the student\n");
	scanf("%d", &cpy_temp);
	for (int cpy_counter = 0; cpy_counter < cpy_numStudents; cpy_counter++)
	{
	if (cpy_temp == students[cpy_counter].id)
	{
	printf("Enter the updated Grade : ");
    scanf("%f", &buffer);
	if(buffer == students[cpy_counter].grade)
    {
	    printf("You entered the current grade \nGrade unchanged\n");
	}
	else
	{
		while( buffer < 0 ||buffer > 100 )
	{
		printf("The Grade must be between 0 and 100\n");
		printf("Enter the updated Grade : ");
        scanf("%f", &buffer);
	}
		students[cpy_counter].grade = buffer;
		printf("Grade updated successfully\n");
    }
	cpy_found ++ ;
	DFILE_writeStudentData();
	}
	}
	if(cpy_found == 0)
	{
		printf("Student not found\n");
	}
	return ;
}
void BADMIN_findStudentDetails()
{
	DFILE_readStudentData();
	DFILE_readNumberOfStudents();
	int cpy_temp;
	int cpy_found=0;
	printf("Enter the ID number of the student\n");
	scanf("%d", &cpy_temp);
	for (int cpy_counter=0 ; cpy_counter<cpy_numStudents ; cpy_counter++)
	{
	if (cpy_temp == students[cpy_counter].id)
	{
	printf("The student's details are\n");
	printf("The Name is %s\n", students[cpy_counter].name);
	printf("The age is %d\n", students[cpy_counter].age);
	printf("The Grade is %.2f\n", students[cpy_counter].grade);
	cpy_found ++ ;
	}
	}
	if(cpy_found == 0)
	{
		printf("Student not found\n");
	}
	return ;
}


void BADMIN_viewAllRecords() 
{
	DFILE_readStudentData();
	DFILE_readNumberOfStudents();
    printf("\nAll Student Records:\n");
    for (int cpy_counter = 0; cpy_counter < cpy_numStudents; cpy_counter++) {
	printf("*****************************************************\n");
    printf("Student %d:\n", cpy_counter + 1);
    printf("Name: %s\n", students[cpy_counter].name);
    printf("Age: %d\n", students[cpy_counter].age);
    printf("ID: %d\n", students[cpy_counter].id);
    printf("Grade: %.2f\n", students[cpy_counter].grade);
	printf("*****************************************************\n");
    }
return ;
}