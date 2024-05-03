#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "library.h"
#include "../../Database/filehandlingtest/file.h"

#define StackEntry ST_transaction_t*
#define MAXSTACK MAX_TRANSACTIONS

typedef struct {
     StackEntry entry[MAX_TRANSACTIONS];
    int top;
    int size;
} Stack;

void populateStack(Stack* ps);

void printStack(Stack* ps);

void StackInit(Stack* ps);

extern const char* transStateStrings[];



#endif // STACK_H_INCLUDED
