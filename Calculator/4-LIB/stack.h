#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define MAXSTACK 16
#define StackEntry int

typedef struct stack
{
    int top;
    StackEntry entry[MAXSTACK];
} Stack;


void push(StackEntry e,Stack *ps);

void pop(StackEntry *pe,Stack *ps);


#endif // STACK_H_INCLUDED
