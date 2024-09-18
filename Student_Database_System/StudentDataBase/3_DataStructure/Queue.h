#ifndef _QUEUE_H
#define _QUEUE_H

#include "../5_Library/library.h"
#include "config.h"

typedef enum Error_State
{
	NO_ERROR,
	QUEUE_FULL,
	QUEUE_NOT_FULL,
	QUEUE_NOT_EMPTY,
	QUEUE_EMPTY,
	QUEUE_NULL,
}QueueError;

typedef struct student
{
	char name[30];
	double marks;
	int age;
	int id;
}StudentType;

#if QueueType == QueueArray
    typedef struct queue
    {
		QueueEntry queueElements[MAX_ELEMENTS];
		int front;
		int rear;
		int size;
    }Queue;

#elif QueueType == QueueLinkedList
	typedef struct Node
    {
		QueueEntry value;
		struct Node* next;
    }QueueNode;
		
    typedef struct queue
    {
		QueueNode* front;
		QueueNode* rear;
		int size;
    }Queue;

#endif

QueueError Queue_enumQueueErrorInit		(Queue* PQ);
QueueError Queue_enumQueueErrorEnqueue		(Queue* PQ, QueueEntry element);
QueueError Queue_enumQueueErrorDequeue 		(Queue* PQ, QueueEntry* element);
QueueError Queue_enumQueueErrorIsFull	(Queue* PQ);
QueueError Queue_enumQueueErrorIsEmpty	(Queue* PQ);
QueueError Queue_enumQueueErrorSize		(Queue* PQ, int* size);
QueueError Queue_enumQueueErrorFront	(Queue* PQ, QueueEntry* front)  ;
QueueError Queue_enumQueueErrorPrint	(Queue* PQ);
void SetStudentInfo(StudentInfo_t* newStudent);
void DeleteStudent(Queue* PQ, int id);
void ViewStudent(Queue* PQ, int id);
void AddStudent(Queue* PQ, StudentInfo_t* newStudent);
void DeleteAllStudents(Queue* PQ);
void ViewStudentWithIndex(Queue* PQ, int index);
//int CountNumberOfStudents(Queue* PQ, QueueNode* ptrToNode);
void ViewStudentWithReversedIndex(Queue* PQ, int index);
void ViewMiddleStudent(Queue* PQ);
void IsThereALoop(Queue* PQ);
void ReverseTheStudentsOrder(Queue* PQ);
void AddFromFile(Queue* PQ);
void ViewStudentWithRoll(Queue* PQ, int roll);
void ViewStudentWithFname(Queue* PQ, char fname[]);
void ViewStudentsInCourse(Queue* PQ, int course_id);
void DeleteStudent(Queue* PQ, int roll);
void UpdateStudent(Queue* PQ, int roll);



#endif /* _QUEUE_H */