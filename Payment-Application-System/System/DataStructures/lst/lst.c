#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "lst.h"

void ListInit(List* plist) {
    plist->size = 0;
for (int i = 0; i < MAX_ACCOUNTS; i++) {
        plist->data[i] = malloc(sizeof(ST_accountsDB_t));
         memset(plist->data[i], 0, sizeof(ST_accountsDB_t));
    }
}

int ListIsEmpty(const List* plist) {
    return plist->size == 0;
}

int ListIsFull(const List* plist) {
    return plist->size == MAX_SIZE;
}

void ListInsert(List* plist, ST_accountsDB_t* element, int position) {
    if (plist == NULL)
    {
      printf("Invalid list. Cannot insert element.\n");
      return;
     }
    if (ListIsFull(plist)) {
        printf("List is full. Cannot insert element.\n");
        return;
    }

    if (position < 0 || position > plist->size) {
        printf("Invalid position. Cannot insert element.\n");
        return;
    }

    // Shift elements to the right
    for (int i = plist->size-1; i >= position; i--) {
        plist->data[i+1] = plist->data[i];
    }

    // Insert the new element
    plist->data[position] = element;
    plist->size++;
}

void ListRemove(List* plist, int position) {
    if (ListIsEmpty(plist)) {
        printf("List is empty. Cannot remove element.\n");
        return;
    }

    if (position < 0 || position >= plist->size) {
        printf("Invalid position. Cannot remove element.\n");
        return;
    }

    // Shift elements to the left
    for (int i = position; i < plist->size - 1; i++) {
        plist->data[i] = plist->data[i + 1];
    }

    plist->size--;
}

ST_accountsDB_t* ListGetElement(const List* plist, int position) {
    if (position < 0 || position >= plist->size) {
        //printf("Invalid position. Cannot retrieve element.\n");
        return NULL;
    }

    return plist->data[position];
}

void ListPrint(List* plist) {
    if (ListIsEmpty(plist)) {
        printf("List is empty.\n");
        return;
    }

    printf("List elements:\n");
    for (int i = 0; i < plist->size; i++) {
        printf("Primary Account Number: %s\n", plist->data[i]->primaryAccountNumber);
        printf("State: %s\n", accountStateStrings[plist->data[i]->state]);
        printf("Balance: %.2f\n", plist->data[i]->balance);
        printf("\n");
    }
}



void populateListFromFile(List* plist) {
    ST_accountsDB_t* ptrAccountData[MAX_SIZE];  // Assuming MAX_SIZE is defined appropriately
for (int i = 0; i < MAX_ACCOUNTS; i++) {
        ptrAccountData[i] = malloc(sizeof(ST_accountsDB_t));
         memset(ptrAccountData[i], 0, sizeof(ST_accountsDB_t));
    }
    // Call the readAccountsDataFromFile function to read account data into ptrAccountData array
    readAccountsDataFromFile(ptrAccountData);

    // Insert the account data into the list

   for (int i = 0; i < MAX_SIZE; i++) {
        if (strlen(ptrAccountData[i]->primaryAccountNumber))
            ListInsert(plist, ptrAccountData[i], i);
        else
            break;  // Stop inserting when encountering NULL pointer
    }

}

void update(List* pl)
{
    clearAccountDatabase();
   for(int i=0;i<pl->size;i++)
   {
      updateAccountDatabsae(pl->data[i]);
   }

}
