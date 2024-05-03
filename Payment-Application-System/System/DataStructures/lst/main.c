#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "lst.h"
int main()
{

    List list;

    ListInit(&list);

     populateListFromFile(&list);
     printf("WI\n");
     ListPrint(&list);
     printf("GFDS");

    // Free the allocated memory for account data
    /*for (int i = 0; i < list.size; i++) {
        free(list.data[i]);
    }*/
    printf("HI");

    return 0;
}
