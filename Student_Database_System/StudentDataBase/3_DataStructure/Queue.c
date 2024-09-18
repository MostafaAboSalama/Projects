/*
* ***************************************
* ************ Queue.c ******************
* ***************************************
*/

#include "Queue.h"
#include "../2_FileHandling/FileHandling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*******************************
// Initialize the queue based on type
//*******************************
QueueError Queue_enumQueueErrorInit(Queue* PQ)
{
    QueueError errorState = NO_ERROR;
    
    #if QueueType == QueueArray
        PQ->size  = 0;
        PQ->front = 0;
        PQ->rear  = 0;
    
    #elif QueueType == QueueLinkedList
        PQ->size = 0;
        PQ->front = NULL;
    
    #endif
    
    return errorState;
}

//*******************************
// Enqueue an element into the queue
//*******************************
QueueError Queue_enumQueueErrorEnqueue(Queue* PQ, QueueEntry element)   
{
    QueueError errorState = NO_ERROR;

    #if QueueType == QueueArray
        if (Queue_enumQueueErrorIsFull(PQ) == QUEUE_FULL) 
        {
            return QUEUE_FULL;
        } 
        else 
        {
            PQ->queueElements[PQ->rear] = element;                
            // Update rear and size
            PQ->rear = (PQ->rear + 1) % MAX_ELEMENTS;
            PQ->size++;
        }
        
    #elif QueueType == QueueLinkedList
        QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
        if(newNode == NULL)
            return QUEUE_NULL;
        
        newNode->value = element;
        newNode->next = NULL;
        
        if(Queue_enumQueueErrorIsEmpty(PQ) == QUEUE_EMPTY)
            PQ->front = newNode;
        else
            PQ->rear->next = newNode;
        
        PQ->rear = newNode;
        PQ->size++;
    
    #endif
    
    return errorState;
}

//*******************************
// Dequeue an element from the queue
//*******************************
QueueError Queue_enumQueueErrorDequeue(Queue* PQ, QueueEntry* element) 
{
    QueueError errorState = NO_ERROR;
    
    #if QueueType == QueueArray
        if(Queue_enumQueueErrorIsEmpty(PQ) == QUEUE_EMPTY)
            return QUEUE_EMPTY;
        else
        {
            *element = PQ->queueElements[PQ->front];
            PQ->front = (PQ->front + 1) % MAX_ELEMENTS;
            PQ->size--;
        }
    
    #elif QueueType == QueueLinkedList
        if(Queue_enumQueueErrorIsEmpty(PQ) == QUEUE_EMPTY)
            return QUEUE_EMPTY;
        
        QueueNode* ptrToNode = PQ->front;
        *element = ptrToNode->value;        
        PQ->front = PQ->front->next;
        free(ptrToNode);
        PQ->size--;
        if(PQ->size == 0)
            PQ->rear = NULL;
         
    #endif
    
    return errorState;
}

//*******************************
// Check if the queue is full
//*******************************
QueueError Queue_enumQueueErrorIsFull(Queue* PQ) 
{
    QueueError errorState = QUEUE_NOT_FULL;
    
    #if QueueType == QueueArray
        if(PQ->size == MAX_ELEMENTS)
            errorState = QUEUE_FULL;
    
    #endif
    
    return errorState;
}

//*******************************
// Check if the queue is empty
//*******************************
QueueError Queue_enumQueueErrorIsEmpty(Queue* PQ)
{
    QueueError errorState = QUEUE_NOT_EMPTY;
    
    #if QueueType == QueueArray
        if(PQ->size == 0)
            errorState = QUEUE_EMPTY;
    
    #elif QueueType == QueueLinkedList
        if(PQ->size == 0)
            errorState = QUEUE_EMPTY;
    
    #endif
    
    return errorState;
}

//*******************************
// Get the current size of the queue
//*******************************
QueueError Queue_enumQueueErrorSize(Queue* PQ, int* size)   
{
    QueueError errorState = NO_ERROR;
    
    #if QueueType == QueueArray
        *size = PQ->size;
    
    #elif QueueType == QueueLinkedList
        *size = PQ->size;
    
    #endif
    
    return errorState;
}

//*******************************
// Get the front element of the queue
//*******************************
QueueError Queue_enumQueueErrorFront(Queue* PQ, QueueEntry* front)    
{
    QueueError errorState = NO_ERROR;
    
    #if QueueType == QueueArray
        *front = PQ->queueElements[PQ->front];

    #elif QueueType == QueueLinkedList
        *front = PQ->front->value;
    
    #endif
    
    return errorState;
}

//*******************************
// Add a student to the queue
//*******************************
void AddStudent(Queue* PQ, StudentInfo_t* newStudent)
{
    int exist = 0;
    for(int i = 0; i < PQ->size; i++)
    {
        if(PQ->queueElements[i]->roll == newStudent->roll)
        {
            exist = 1;
            break;
        }
    }
    if(exist)
        printf("ID Already exists\n");
    else
    {
        Queue_enumQueueErrorEnqueue(PQ, newStudent);
    }
}

//*******************************
// Add students from a file
//*******************************
void AddFromFile(Queue* PQ)
{
    Queue temp;
    Queue_enumQueueErrorInit(&temp);
    
    // Allocate memory for all elements
    for (int i = 0; i < MAX_ELEMENTS; i++) 
    {
        temp.queueElements[i] = malloc(sizeof(StudentInfo_t));
        memset(temp.queueElements[i], 0, sizeof(StudentInfo_t));
    }

    // Read students from the file
    int numStudents;
    ReadFromFile(temp.queueElements, &numStudents); 
        
    for (int i = 0; i < numStudents; i++) 
    { 
        AddStudent(PQ, temp.queueElements[i]);
		printf("Student Added Successfully\n");
    }
}

//*******************************
// Set student information
//*******************************
void SetStudentInfo(StudentInfo_t* newStudent) 
{
    int numOfCourses; 

    printf("Enter the first name: ");
    scanf("%s", newStudent->fname);
    
    printf("Enter the last name: ");
    scanf("%s", newStudent->lname);

    printf("Enter the roll number: ");
    scanf("%d", &newStudent->roll);
    
    printf("Enter the GPA: ");
    scanf("%f", &newStudent->GPA);
    
    printf("Enter the number of courses you are in: ");
    scanf("%d", &numOfCourses);
    
    for(int i = 0; i < numOfCourses; i++)
    {
        printf("Enter Course %d id: ", i + 1);
        scanf("%d", &newStudent->course_id[i]);
    }
    
    // Initialize remaining course_id slots to 0 
    for(int i = numOfCourses; i < 10; i++) 
    {
        newStudent->course_id[i] = 0;
    }
}

//*******************************
// View student information by roll number
//*******************************
void ViewStudentWithRoll(Queue* PQ, int roll)
{
    int exist = 0;
    int i = 0;
    for( ; i < PQ->size; i++)
    {
        if(PQ->queueElements[i]->roll == roll)
        {
            exist = 1;
            break;
        }
    }
    if(exist)
    {
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
    else
        printf("Student Doesn't exist\n");
}

//*******************************
// View student information by first name
//*******************************
void ViewStudentWithFname(Queue* PQ, char fname[])
{
    int exist = 0;
    int i = 0;
    for( ; i < PQ->size; i++)
    {
        if(strcmp(fname, PQ->queueElements[i]->fname) == 0)
        {
            exist = 1;
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
    }
    if(!exist)
       printf("Student Doesn't exist\n");
}

//*******************************
// View students in a course
//*******************************
void ViewStudentsInCourse(Queue* PQ, int course_id)
{
    int i = 0;
    for( ; i < PQ->size; i++)
    {
        for(int k = 0; k < 10; k++)
        {
            if(PQ->queueElements[i]->course_id[k] == course_id)
            {
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
                break;
            }
        }
    }
}

//*******************************
// Delete a student from the queue by roll number
//*******************************
void DeleteStudent(Queue* PQ, int roll)
{
    int exist = 0;
    int i = 0;
    for( ; i < PQ->size; i++)
    {
        if(PQ->queueElements[i]->roll == roll)
        {
            exist = 1;
            PQ->queueElements[i]->roll = -1; // Mark as deleted
            break;
        }
    }
    if(exist)
    {
        for( ; i < PQ->size - 1; i++)
        {
            free(PQ->queueElements[i]);
            PQ->queueElements[i] = PQ->queueElements[i + 1];
        }
        PQ->size--;
        PQ->rear = PQ->size;
    }
    else
        printf("Student Doesn't exist\n");
}

//*******************************
// Update a student by roll number
//*******************************
void UpdateStudent(Queue* PQ, int roll)
{
    int exist = 0;
    int i = 0;
    int numOfCourses = 0;
    for( ; i < PQ->size; i++)
    {
        if(PQ->queueElements[i]->roll == roll)
        {
            exist = 1;
            break;
        }
    }
    if(exist)
    {
        printf("Enter the new first name: ");
        scanf("%s", PQ->queueElements[i]->fname);
        
        printf("Enter the new last name: ");
        scanf("%s", PQ->queueElements[i]->lname);
        
        printf("Enter the new GPA: ");
        scanf("%f", &PQ->queueElements[i]->GPA);
        
        printf("Enter the number of courses you are in: ");
        scanf("%d", &numOfCourses);
        
        for(int j = 0; j < numOfCourses; j++)
        {
            printf("Enter Course %d id: ", j + 1);
            scanf("%d", &PQ->queueElements[i]->course_id[j]);
        }
        
        // Initialize remaining course_id slots to 0 
        for(int j = numOfCourses; j < 10; j++) 
        {
            PQ->queueElements[i]->course_id[j] = 0;
        }
    }
    else
        printf("Student Doesn't exist\n");
}
