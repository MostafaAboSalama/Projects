#include <stdio.h>
#include<string.h>
#include "file_access.h"
#include"../../Business_Logic/Student/student.h"

extern int cpy_numStudents;
extern char adminPassword[];

void DFILE_writeStudentData ()
{
	FILE * fileWrite ;
	fileWrite = fopen("StudentsData.bin" , "wb" );
	fwrite(& students , sizeof(Student) , 500 , fileWrite);
	fclose(fileWrite);	
}
void DFILE_readStudentData()
{
	FILE * fileRead ;
	fileRead = fopen ("StudentsData.bin" , "rb");
	fread(& students , sizeof(Student) , 500 , fileRead);
	fclose(fileRead);
}
void DFILE_writeNumberOfStudents()
{
	FILE * saveNumOfStu ;
	saveNumOfStu = fopen("numberofstudents.bin" , "wb");
	fwrite(&cpy_numStudents , sizeof(int) , 1 , saveNumOfStu );
	fclose(saveNumOfStu);
}
void DFILE_readNumberOfStudents()
{
	FILE * readNumOfStu ;
	readNumOfStu = fopen("numberofstudents.bin" , "rb");
	fread(&cpy_numStudents , sizeof(int) , 1 , readNumOfStu );
	fclose(readNumOfStu);
}
void DFILE_writeAdminPassword()
{
	FILE * writeAdminPass ;
	writeAdminPass = fopen("adminpass.bin" , "wb");
	fwrite(adminPassword, sizeof(char), strlen(adminPassword), writeAdminPass);
	fclose(writeAdminPass);
}
void DFILE_readAdminPassword()
{
	FILE * readAdminPass ;
	readAdminPass = fopen("adminpass.bin" , "rb");
	fread( adminPassword , sizeof(char) , strlen(adminPassword) , readAdminPass);
	fclose(readAdminPass);
}
