#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "Queue.h"



void QueueInit(Queue* pq)
{
    pq->size=0;
    pq->front=0;
    pq->rear=-1;
    //lastSeqNumber=0;
}

int QueueEmpty(Queue* pq)
{
    return (!pq->size);
}

int QueueFull(Queue* pq)
{
    return (pq->size==MAXQUEUE);
}

int QueueSize(Queue* pq)
{
    return pq->size;
}

void append(Queue* pq ,QueueEntry e)
{
    pq->rear=(pq->rear+1) % MAXQUEUE;
    pq->entry[pq->rear]=e;
    pq->size++;
}

void serve(Queue* pq ,QueueEntry* pe)
{
    *pe=pq->entry[pq->front];
     pq->front=(pq->front+1) % MAXQUEUE;
    pq->size--;
}

void ClearQueue(Queue* pq)
{
    pq->size=0;
    pq->front=0;
    pq->rear=-1;
}

void TraverseQueue(Queue* pq ,void(*pf)(QueueEntry))
{
    int s;
    for(int i=pq->front,s=0;s<pq->size;s++)
    {
        (*pf)(pq->entry[i]);
         i=(i+1) % MAXQUEUE;
    }
}


void populateQueue(Queue* pq)
{

    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        pq->entry[i] = malloc(sizeof(ST_transaction_t));
        memset(pq->entry[i], 0, sizeof(ST_transaction_t));
    }

   readTransactionsDataFromFile(pq->entry);


   for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        if (strlen(pq->entry[i]->cardHolderData.cardHolderName) == 0)
            break;
        pq->size++;
         pq->rear=pq->size-1;
        }
}

void writeToDatabase(Queue* pq)
{

    ST_transaction_t* ptrTransactionData;
    while (!QueueEmpty(pq)) {
        serve(pq, &ptrTransactionData);
        writeTransactionData(ptrTransactionData);
        free(ptrTransactionData);
    }
}


void printQueue( Queue* pq)
{
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        if (strlen(pq->entry[i]->cardHolderData.cardHolderName) == 0) {
            continue;  // Skip empty transactions
        }
         pq->entry[i]->transactionSequenceNumber=i+2;
        printf("#########################\n");
       printf("Transaction Sequence Number: %d\n", i+1);
       printf("Transaction Date: %s\n", pq->entry[i]->terminalData.transactionDate);
       printf("Transaction Amount: %.2f\n", pq->entry[i]->terminalData.transAmount);
       printf("Transaction State: %s\n", transStateStrings[pq->entry[i]->transState]);
       printf("Terminal Max Amount: %.2f\n", pq->entry[i]->terminalData.maxTransAmount);
        printf("Card Holder Name: %s\n", pq->entry[i]->cardHolderData.cardHolderName);
        printf("PAN: %s\n", pq->entry[i]->cardHolderData.primaryAccountNumber);
        printf("Card Expiration Date: %s\n", pq->entry[i]->cardHolderData.cardExpirationDate);
        printf("#########################\n");

       // printf("\n");
    }

}



