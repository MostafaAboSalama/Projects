#include <stdio.h>
#include "../../Business_Logic/Authentication/authentication.h"
int main(){
int cpy_choice;
 while(1){
	 printf("Welcome in our system\n");
       printf("Choose Admin mode or Student mode\n" 
       "1: Admin mode\n"
       "2: Student mode\n"
	   "3: Exit\n" );
        scanf("%d",&cpy_choice);

 switch(cpy_choice){
   case 1:   printf("Welcome in Admin mode !\n");
             BAUTHENTICATION_checkAdminPassword();
             break;

   case 2:   printf("Welcome in student mode !\n");
             BAUTHENTICATION_checkStudentPassword();
             break;
			 
   case 3:   printf("Exiting..");
             return 0;

   default: 
   break;
}
}
}




