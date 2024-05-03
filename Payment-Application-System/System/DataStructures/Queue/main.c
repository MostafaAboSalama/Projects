#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "Queue.h"




int main()
{
    printf("Hello worldjjjjh!\n");
    Queue q;
    QueueInit(&q);
   populateQueue(&q);
   printQueue(&q);
   writeToDatabase(&q);
   printf("ads");
    return 0;
}
