#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "library.h"
#include "../../Database/filehandlingtest/file.h"

#define ListEntry ST_accountsDB_t

#define MAX_SIZE MAX_ACCOUNTS


typedef struct {
    ST_accountsDB_t* data[MAX_SIZE];
    int size;
} List;

void ListInit(List* plist);

int ListIsEmpty(const List* plist);

int ListIsFull(const List* plist);

void ListInsert(List* plist, ST_accountsDB_t* element, int position);

void ListRemove(List* plist, int position);

ST_accountsDB_t* ListGetElement(const List* plist, int position);

void ListPrint(List* plist);

void populateListFromFile(List* plist);

void update(List* pl);

extern const char* accountStateStrings[];

//extern int lastSeqNumber;


#endif // LIST_H_INCLUDED
