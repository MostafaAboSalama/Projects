#include "authentication.h"
#include <string.h>
#include <stdio.h>
#include "../Student/student.h"
#include "../../Data_Access/File_Access/file_access.h"
#include "../../User_Interface/Input_Output/input_output.h"

char adminPassword[] = "1234";
extern int cpy_numStudents;

void BAUTHENTICATION_checkAdminPassword(){
	    char password[20];
		DFILE_readAdminPassword();
		int cpy_attempts = 3;
        while (cpy_attempts >0) 
		{
        printf("Enter admin password: ");
        scanf("%s", password);
          if (strcmp(password, adminPassword) == 0) 
		{
            printf("Access granted!\n");
			UIO_chooseAdminTask();
            break;
        }
		else 
		{
            printf("Incorrect password. %d attempts remaining.\n", cpy_attempts -1);
            cpy_attempts--;
        }
        }
        if (cpy_attempts == 0) {
			printf("Maximum attempts reached.\nExiting\n");
			return;
        }
	    }
    void BAUTHENTICATION_checkStudentPassword() { 
	
	DFILE_readStudentData();
	DFILE_readNumberOfStudents();
		
	int cpy_id;
    char password[20];
	
	printf("\nEnter your ID: ");
    scanf("%d", &cpy_id);

    Student* user = NULL;
    for (int cpy_counter = 0; cpy_counter < cpy_numStudents; cpy_counter++) 
	{
        if (students[cpy_counter].id == cpy_id) 
		{
            user =& students[cpy_counter];
			int cpy_attempts = 3;
	        while(cpy_attempts > 0){  
            printf("Enter your password: ");
            scanf("%s", password);

    if (strcmp(user->password , password)) {
        printf("Incorrect password %d attempts remaining\n" , cpy_attempts-1);
    }
	else 
	{
		 printf("Access granted!\n");
		 UIO_chooseStudentTask(cpy_id , password);
	}
	cpy_attempts -- ;
	}
	}
	 if (user == NULL) 
		{
			printf("User not found\n");
			break;
        }
	}
}