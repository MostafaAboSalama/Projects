#include "stack.h"




void push(StackEntry e,Stack *ps)
{
        
     ps->entry[ps->top++]=e;
}

void pop(StackEntry *pe,Stack *ps)
{
    
    *pe=ps->entry[--ps->top];
        
}


