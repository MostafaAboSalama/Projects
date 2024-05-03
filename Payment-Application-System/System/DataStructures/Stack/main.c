#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "Stack.h"




int main()
{
    printf("Hello worldjjjjh!\n");
    Stack S;
    StackInit(&S);
   populateStack(&S);
   printf("TEST");
   printStack(&S);
    return 0;
}
