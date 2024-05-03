#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Data_Access/File_Access/file_access.h"

extern int cpy_numStudents;
 
void BSTUDENT_viewRecord(int cpy_temp , char z[20])
{
   DFILE_readNumberOfStudents();
   DFILE_readStudentData();
   for(int cpy_counter =0 ; cpy_counter < cpy_numStudents ; cpy_counter++)
   {
      if (cpy_temp == students[cpy_counter].id && (strcmp(students[cpy_counter].password , z)==0))
      {
         printf("The details are\n");
         printf("Name is %s\n", students[cpy_counter].name);
         printf("Age is %d\n", students[cpy_counter].age);
         printf("Grade is %.2f\n", students[cpy_counter].grade);
      }
   }
	  return ;
 }
void BSTUDENT_editYourDetail(int cpy_temp , char z[20])
{
   DFILE_readNumberOfStudents();
   DFILE_readStudentData();
   
   char buffer[20];
   char currentPasswordBuffer [20] ; 
   
   for (int cpy_counter = 0; cpy_counter < cpy_numStudents; cpy_counter++)
   {
      if (cpy_temp == students[cpy_counter].id && (strcmp(students[cpy_counter].password , z)==0))
      {
         printf("1. Edit your Name\n"
                "2. Edit your Password\n");
         int cpy_choice;
         scanf("%d", &cpy_choice);
         switch(cpy_choice) {
            case 1:
               printf("Enter the updated name : ");
               scanf("%s", buffer);
			   if(strcmp(buffer , students[cpy_counter].name) == 0)
			   {
				   printf("You entered your current name \nName unchanged\n");
			   }else{
			   strcpy(students[cpy_counter].name , buffer);
			   printf("Name updated successfully\n");
			   }
               break;
            case 2:
			   printf("Enter your current password :");
			   scanf("%s", currentPasswordBuffer);
			   if(strcmp(currentPasswordBuffer , students[cpy_counter].password) != 0)
			   {
				   printf("Incorrect current password. Password not changed.\n");
			   }
			   else{
               printf("Enter the updated password : ");
               scanf("%s", buffer);
				while ( strlen(buffer) < 4 )
				{
					printf("Password too short *it should be atleast 4 characters*\n");
					printf("Enter the updated password : ");
                    scanf("%s", buffer);
				}
				if(strcmp(buffer , students[cpy_counter].password) == 0)
				{
				printf("You entered your current password \nPassword unchanged\n");
				}
				else{
			   strcpy(students[cpy_counter].password , buffer);
			   printf("Password updated successfully\n");
				}
			   }
			   }
         }
		 DFILE_writeStudentData();
      }
   return ;
}