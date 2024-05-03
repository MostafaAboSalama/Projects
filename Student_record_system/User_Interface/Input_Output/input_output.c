#include "input_output.h"
#include <stdio.h>
#include "../../Business_Logic/Admin/admin.h"
#include "../../Business_Logic/Student/student.h"

void UIO_chooseAdminTask()
{
	while(1){
    int cpy_choice;
    printf("1- Edit Admin Password\n");
    printf("2- Add a new student detail\n");
    printf("3- Find the details of a student using ID number\n");
    printf("4- Delete the details of a student\n");
    printf("5- Update the details of a student\n");
	printf("6- View details of all student\n");
    printf("7- Go back\n");
    printf("Enter the task number : ");
    scanf("%d",&cpy_choice);
    switch(cpy_choice)
    {
      case 1:
        BADMIN_changeAdminPassword();
        break;
      case 2:
        BADMIN_addNewStudent();
         break;
      case 3:
        BADMIN_findStudentDetails();
         break;
      case 4:
        BADMIN_deleteStudent();
         break;
      case 5:
        BADMIN_editStudentGrade();
         break;
      case 6:
          BADMIN_viewAllRecords();
         break;
      default:
           break;
    }
	if (cpy_choice == 7)
		break;
	}
}


void UIO_chooseStudentTask(int cpy_id , char password[20])
{
  while(1){
  int cpy_choice;
  
   printf("1- Edit your details\n");
   printf("2- View your record\n");
   printf("3- Go back\n");
   scanf("%d",&cpy_choice);
    switch(cpy_choice)
    {
     case 1:
         BSTUDENT_editYourDetail(cpy_id , password);
        break;
     case 2:
         BSTUDENT_viewRecord(cpy_id , password);
         break;
     default:
        break;
    }
	if (cpy_choice == 3)
		break;
}
}