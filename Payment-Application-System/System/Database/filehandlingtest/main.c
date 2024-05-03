#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include <ctype.h>
int main()
{
    printf("Hello world!\n");
    ST_accountsDB_t* accounts[MAX_ACCOUNTS];
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        accounts[i] = malloc(sizeof(ST_accountsDB_t));
    }
    readAccountsDataFromFile(accounts);

    return 0;
}
