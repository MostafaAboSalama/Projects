#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include <ctype.h>
int lastSeqNumber = 0;

const char* transStateStrings[] = {
    "APPROVED",
    "DECLINED_INSUFFECIENT_FUND",
    "DECLINED_STOLEN_CARD",
    "FRAUD_CARD",
    "INTERNAL_SERVER_ERROR"
};

const char* accountStateStrings[] = {
    "RUNNING",
    "BLOCKED"
};


int getLastTransactionSequenceNumber() {
    FILE *file = fopen("../Database/Data/Server-side-transactions.txt", "r");
    if (file == NULL) {
        return 0;
    }

    int lastSequenceNumber = 0;
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        int sequenceNumber;
        sscanf(line, "%*[^,], %*[^,], %*[^,], %*[^,], %*f, %*f, %*[^,], %d", &sequenceNumber);
        if (sequenceNumber > lastSequenceNumber) {
            lastSequenceNumber = sequenceNumber;
        }
    }

    fclose(file);
    return lastSequenceNumber;
}

void writeTransactionData(ST_transaction_t* ptrTransactionData) {
    // Get the last sequence number
    int lastSequenceNumber = getLastTransactionSequenceNumber();

    FILE *file = fopen("../Database/Data/Server-side-transactions.txt", "a"); // Open in "a" mode for appending
    if (file == NULL) {
        printf("Error opening database file.\n");
        exit(1);
    }

    // Increment the sequence number
    int newSequenceNumber = lastSequenceNumber + 1;

    if (fprintf(file, "%s, %s, %s, %s, %0.2f, %0.2f, %s, %d\n", ptrTransactionData->cardHolderData.cardHolderName,
                ptrTransactionData->cardHolderData.primaryAccountNumber,
                ptrTransactionData->cardHolderData.cardExpirationDate, ptrTransactionData->terminalData.transactionDate,
                ptrTransactionData->terminalData.transAmount, ptrTransactionData->terminalData.maxTransAmount,
                transStateStrings[ptrTransactionData->transState], newSequenceNumber) < 0) {
        printf("Error writing transaction data.\n");
        exit(1);
    }

    fflush(file); // Flush the data buffer
    fclose(file); // Close the file after writing
}



void readTransactionsDataFromFile(ST_transaction_t* ptrTransactionData[])
{
    FILE* file = fopen("../Database/Data/Server-side-transactions.txt", "r");
    if (file == NULL) {
        printf("Error opening database file.\n");
        exit(1);
    }

    char* line = NULL;
    size_t lineBufferSize = 0;
    size_t transIndex = 0;

    ssize_t bytesRead;
    while ((bytesRead = getline(&line, &lineBufferSize, file)) != -1) {
        // Check if the line is empty or contains only whitespace
        int isEmptyOrWhitespace = 1;
        for (size_t i = 0; i < bytesRead; i++) {
            if (!isspace(line[i])) {
                isEmptyOrWhitespace = 0;
                break;
            }
        }

        if (isEmptyOrWhitespace) {
            continue;  // Skip empty lines
        }

        // Parse the line and extract account information

        char *token;

        token = strtok(line, ",");
        strcpy(ptrTransactionData[transIndex]->cardHolderData.cardHolderName, token);

        token = strtok(NULL, ",");
        strcpy(ptrTransactionData[transIndex]->cardHolderData.primaryAccountNumber, token);

        token = strtok(NULL, ",");
        strcpy(ptrTransactionData[transIndex]->cardHolderData.cardExpirationDate, token);

        token = strtok(NULL, ",");
        strcpy(ptrTransactionData[transIndex]->terminalData.transactionDate, token);

        token = strtok(NULL, ",");
        ptrTransactionData[transIndex]->terminalData.transAmount = atof(token);

        token = strtok(NULL, ",");
        ptrTransactionData[transIndex]->terminalData.maxTransAmount = atof(token);

        token = strtok(NULL, ",");
        char* str1=" APPROVED";
        char* str2=" DECLINED_INSUFFECIENT_FUND";
        char* str3=" DECLINED_STOLEN_CARD";
        char* str4=" FRAUD_CARD";
        char* str5=" INTERNAL_SERVER_ERROR";
        if(!strcmp(token, str1))
            ptrTransactionData[transIndex]->transState=0;
        else if(!strcmp(token, str2))
            ptrTransactionData[transIndex]->transState=1;
        else if(!strcmp(token, str3))
           ptrTransactionData[transIndex]->transState=2;
        else if(!strcmp(token, str4))
            ptrTransactionData[transIndex]->transState=3;
        else if(!strcmp(token, str5))
           ptrTransactionData[transIndex]->transState=4;

        token = strtok(NULL, ",");
        ptrTransactionData[transIndex]->transactionSequenceNumber = atoi(token);


        transIndex++;
    }
    free(line);
    fclose(file);
}


void readAccountsDataFromFile(ST_accountsDB_t* ptrAccountData[])
{
    FILE* file = fopen("../Database/Data/Server-side-accounts.txt", "r");
    if (file == NULL) {
        printf("Error opening database file.\n");
        exit(1);
    }

    char* line = NULL;
    size_t lineBufferSize = 0;
    size_t accountIndex = 0;

    ssize_t bytesRead;
    while ((bytesRead = getline(&line, &lineBufferSize, file)) != -1) {
        // Check if the line is empty or contains only whitespace
        int isEmptyOrWhitespace = 1;
        for (size_t i = 0; i < bytesRead; i++) {
            if (!isspace(line[i])) {
                isEmptyOrWhitespace = 0;
                break;
            }
        }

        if (isEmptyOrWhitespace) {
            continue;  // Skip empty lines
        }

        // Parse the line and extract account information
        char* token;
        token = strtok(line, ",");
        strcpy(ptrAccountData[accountIndex]->primaryAccountNumber, token);

        char* str=" RUNNING";
        token = strtok(NULL, ",");
        if(!strcmp(token, str))
            ptrAccountData[accountIndex]->state=0;
        else
            ptrAccountData[accountIndex]->state=1;

        token = strtok(NULL, ",");
        ptrAccountData[accountIndex]->balance = atof(token);


        accountIndex++;
    }

    fclose(file);
    free(line);
}

void updateAccountDatabsae(ST_accountsDB_t* ptrAccountData)
{
     FILE *file = fopen("../Database/Data/Server-side-accounts.txt", "a"); // Open in "a" mode for appending
    if (file == NULL) {
        printf("Error opening database file.\n");
        exit(1);
    }
        //fprintf(file, "\n");
        if (fprintf(file, "%s, %s, %0.2f\n", ptrAccountData->primaryAccountNumber,
                     accountStateStrings[ptrAccountData->state], ptrAccountData->balance) < 0) {
            printf("Error writing transaction data.\n");
            exit(1);
        }

    fflush(file); // Flush the data buffer
    fclose(file); // Close the file after writing
}

void clearAccountDatabase()
{
    FILE* file = fopen("../Database/Data/Server-side-accounts.txt", "w");
    fclose(file);
}
