#include <stdio.h>
#include <stdlib.h>
#include "../5_Library/library.h"
#include "../3_DataStructure/Queue.h"

//*******************************
// Function: Queue_enumQueueErrorPrint
// Description: Prints the elements in the queue
//*******************************
QueueError Queue_enumQueueErrorPrint(Queue* PQ)  
{
    QueueError errorState = NO_ERROR;    

    #if QueueType == QueueArray
        printf("\n*******************************************\n");
        printf("********** Printing QueueArray ***********\n");
        printf("*******************************************\n");
        for(int i = 0; i < PQ->size; i++)
        {
            printf("Record Number: %d\n", i + 1);
            printf("Student FName: %s\n", PQ->queueElements[i]->fname);
            printf("Student LNAME: %s\n", PQ->queueElements[i]->lname);
            printf("Student Roll: %d\n", PQ->queueElements[i]->roll);
            printf("Student GPA: %.2lf\n", PQ->queueElements[i]->GPA);
            for(int j = 0; j < 10; j++)
            {
                if(PQ->queueElements[i]->course_id[j] != 0)
                    printf("Course Id %d: %d\n", j + 1, PQ->queueElements[i]->course_id[j]);
            }
            printf("\n#########################################\n");
        }

    #elif QueueType == QueueLinkedList
        printf("\n*******************************************\n");
        printf("********** Printing QueueLinkedList ******\n");
        printf("*******************************************\n");
        QueueNode* currentNode = PQ->front;
        int i = 0;
        while(currentNode != NULL)
        {
            printf("Record Number: %d\n", ++i);
            printf("Student Name: %s\n", currentNode->value->name);
            printf("Student Age: %d\n", currentNode->value->age);
            printf("Student ID: %d\n", currentNode->value->id);
            printf("Student Marks: %.2lf\n", currentNode->value->marks);
            printf("###########################################\n");
            currentNode = currentNode->next;
        }
        printf("\n#########################################\n");
    #endif
    
    return errorState;
}

//*******************************
// Function: main
// Description: Main program loop for the Student Database
//*******************************
int main()
{
    Queue Q;
    Queue_enumQueueErrorInit(&Q);
    int choice = 0;
    StudentInfo_t* newStudent;
    char fname[50];
    int roll;
    int course_id;

    printf("*******************************************\n");
    printf("** Welcome to the Student Database System **\n");
    printf("*******************************************\n");
    
    while(choice != 10)
    {
        printf("\n*******************************************\n");
        printf("** Choose one of the following options: **\n");
        printf("01- Add Student From File\n"); 
        printf("02- Add Student Manually\n");
        printf("03- View Student Using Roll Number\n"); 
        printf("04- View Student Using First Name\n");
        printf("05- View Students in A Course\n");
        printf("06- Count Number Of Students\n");
        printf("07- Delete Student\n");
        printf("08- Update Student\n");
        printf("09- View All Students\n");
        printf("10- Exit\n");
        printf("*******************************************\n");
        printf("\nEnter Option Number: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
                AddFromFile(&Q);
                break;
            
            case 2: 
                newStudent = (StudentInfo_t*)malloc(sizeof(StudentInfo_t));
                SetStudentInfo(newStudent);
                AddStudent(&Q, newStudent);
                break;
                    
            case 3:               
                printf("Enter the Student roll: ");
                scanf("%d", &roll);
                ViewStudentWithRoll(&Q, roll);
                break;
                    
            case 4: 
                printf("Enter the Student First Name: ");
                scanf("%s", fname);
                ViewStudentWithFname(&Q, fname);
                break;
                
            case 5: 
                printf("Enter the Course ID: ");
                scanf("%d", &course_id);
                printf("Students Enrolled in Course %d are : \n", course_id);
                ViewStudentsInCourse(&Q, course_id);
                break;
                
            case 6: 
                printf("Number Of Students = %d\n", Q.size);
                break;
            
            case 7:
                printf("Enter the Student roll: ");
                scanf("%d", &roll);
                DeleteStudent(&Q, roll);
                break;
                
            case 8: 
                printf("Enter the Student roll: ");
                scanf("%d", &roll);
                UpdateStudent(&Q, roll);
                break;
                
            case 9: 
                Queue_enumQueueErrorPrint(&Q);
                break;
                            
            case 10:
                printf("Exiting the Student Database System. Goodbye!\n");
                break;

            default:
                printf("Invalid Option. Please try again.\n");
                break;
        }
    }
    
    return 0;
}
