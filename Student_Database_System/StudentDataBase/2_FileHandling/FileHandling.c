#include "../5_Library/library.h"
#include "FileHandling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 	100

void ReadFromFile(StudentInfo_t* ptrStudent[], int* number)
{
    FILE* file = fopen("1_Database/Student_Info.txt", "r");
    
    if(file == NULL) {
        printf("Error Opening File\n");
        return;
    }
    
    char buffer[MAX_LINES];
    int index = 0;
    
    while (fgets(buffer, MAX_LINES, file) != NULL)  
    {
        ptrStudent[index] = malloc(sizeof(StudentInfo_t));  
        if (ptrStudent[index] == NULL) 
		{
            printf("Memory allocation failed\n");
            break;
        }
        
        char* roll = strtok(buffer, ", ");
        ptrStudent[index]->roll = atoi(roll);
        
        char* fname = strtok(NULL, ", ");
        strcpy(ptrStudent[index]->fname, fname);
        
        char* lname = strtok(NULL, ", ");
        strcpy(ptrStudent[index]->lname, lname);
        
        char* GPA = strtok(NULL, ", ");
        ptrStudent[index]->GPA = atof(GPA);
        
        for(int i = 0; i < 10; i++) {
            char* course_id = strtok(NULL, ", ");
            if(course_id == NULL) {
                break;
            }
            ptrStudent[index]->course_id[i] = atoi(course_id);
        }
		
        index++;
    }
   
    fclose(file);
	*number = index;
}
