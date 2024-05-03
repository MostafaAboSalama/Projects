#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "library.h"
#include "../../Database/filehandlingtest/file.h"

#define QueueEntry ST_transaction_t*
#define MAXQUEUE 50

typedef struct queue
{
    QueueEntry entry[MAX_TRANSACTIONS];
    int front;
    int rear;
    int size;
}Queue;

void QueueInit(Queue* pq);

int QueueEmpty(Queue* pq);

int QueueFull(Queue* pq);

int QueueSize(Queue* pq);

void append(Queue* pq ,QueueEntry e);

void serve(Queue* pq ,QueueEntry* pe);

void ClearQueue(Queue* pq);

void TraverseQueue(Queue* pq ,void(*pf)(QueueEntry));

void populateQueue(Queue* pq);

void printQueue( Queue* pq);

void writeToDatabase(Queue* pq);

extern const char* transStateStrings[];



#endif // QUEUE_H_INCLUDED
