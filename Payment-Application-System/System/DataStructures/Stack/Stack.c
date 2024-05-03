#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "Stack.h"


void StackInit(Stack* ps)
{
    ps->size=0;
    ps->top=0;
}


void populateStack(Stack* ps)
{
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        ps->entry[i] = malloc(sizeof(ST_transaction_t));
        memset(ps->entry[i], 0, sizeof(ST_transaction_t));
        ps->top++;  // Increase the top index
    }

    readTransactionsDataFromFile(ps->entry);
}


void printStack( Stack* ps)
{
    for (int i = ps->top-1; i >= 0; i--) {

        if (strlen(ps->entry[i]->cardHolderData.cardHolderName) == 0) {
            continue;  // Skip empty transactions
        }
        printf("Transaction %d:\n", i + 1);
        printf("Card Holder Name: %s\n", ps->entry[i]->cardHolderData.cardHolderName);
        printf("Primary Account Number: %s\n", ps->entry[i]->cardHolderData.primaryAccountNumber);
        printf("Card Expiration Date: %s\n", ps->entry[i]->cardHolderData.cardExpirationDate);
        printf("Transaction Date: %s\n", ps->entry[i]->terminalData.transactionDate);
        printf("Transaction Amount: %.2f\n", ps->entry[i]->terminalData.transAmount);
        printf("Max Transaction Amount: %.2f\n", ps->entry[i]->terminalData.maxTransAmount);
        printf("Transaction State: %s\n", transStateStrings[ps->entry[i]->transState]);
        printf("Transaction Sequence Number: %d\n", ps->entry[i]->transactionSequenceNumber);
        printf("\n");
    }
}
