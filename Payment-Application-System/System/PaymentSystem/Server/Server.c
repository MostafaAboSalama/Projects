#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "Server.h"

void ServerInit(ST_cardData_t* cardData, ST_terminalData_t* termData, ST_transaction_t* transData)
{
    transData->cardHolderData= *cardData;
    transData->terminalData= *termData;
}

EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{
    List lst;
    ListInit(&lst);
    populateListFromFile(&lst);


   ValidationResult accountExistsorNot = isValidAccountLoop(&lst, &(transData->cardHolderData));
   if(accountExistsorNot.error==ACCOUNT_NOT_FOUND)
      {
        transData->transState=FRAUD_CARD;
        EN_serverError_t save = saveTransaction(transData);
        if(save==INTERNAL_SERVER_ERROR)
           return INTERNAL_SERVER_ERROR;
        return FRAUD_CARD;
      }

   EN_serverError_t blockedOrNot = isBlockedAccount(lst.data[accountExistsorNot.index]);
   if(blockedOrNot==BLOCKED_ACCOUNT)
      {
        transData->transState=DECLINED_STOLEN_CARD;
        EN_serverError_t save = saveTransaction(transData);
        if(save==INTERNAL_SERVER_ERROR)
           return INTERNAL_SERVER_ERROR;
        return DECLINED_STOLEN_CARD;
      }

   EN_serverError_t checkAmount = isAmountAvailable(&(transData->terminalData),lst.data[accountExistsorNot.index]);
   if(checkAmount==LOW_BALANCE)
      {
        transData->transState=DECLINED_INSUFFECIENT_FUND;
        EN_serverError_t save = saveTransaction(transData);
        if(save==INTERNAL_SERVER_ERROR)
           return INTERNAL_SERVER_ERROR;
        return DECLINED_INSUFFECIENT_FUND;
      }
      transData->transState=APPROVED;
      EN_serverError_t save = saveTransaction(transData);
        if(save==INTERNAL_SERVER_ERROR)
           return INTERNAL_SERVER_ERROR;
        lst.data[accountExistsorNot.index]->balance -= transData->terminalData.transAmount;
        update(&lst);

return APPROVED;
}


ValidationResult isValidAccountLoop(List* lst, ST_cardData_t* CardData) {
    ValidationResult result;
    result.index = ACCOUNT_NOT_FOUND;
    result.error = ACCOUNT_NOT_FOUND;

    for (int i = 0; i < lst->size; i++) {
        EN_serverError_t asd = isValidAccount(CardData, lst->data[i]);

        if (asd == SERVER_OK) {
            result.index = i; // Update the index with the index of the valid account
            result.error = SERVER_OK; // Update the error with SERVER_OK
            break; // Break out of the loop since a valid account is found
        }
    }

    return result;
}

EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t* accountReference)
{
    if (strcmp(cardData->primaryAccountNumber, accountReference->primaryAccountNumber) == 0)
        return SERVER_OK;
    else
        {
             accountReference=NULL;
            return ACCOUNT_NOT_FOUND;
        }
}


EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountReference) {
    char *str = "RUNNING";
  //  printf("state: %s\n",accountStateStrings[accountReference->state]);
    if (strcmp(accountStateStrings[accountReference->state], str) == 0) {
        return SERVER_OK;
    } else {
        accountReference = NULL;
        return BLOCKED_ACCOUNT;
    }
}

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t* accountRefrence)
{
   if(termData->transAmount > accountRefrence->balance)
      return LOW_BALANCE;
   else
      return SERVER_OK;
}




EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
    Queue q;
    QueueInit(&q);
    append(&q, transData);
    writeToDatabase(&q);
    listSavedTransactions();
    return SERVER_OK;
}

void listSavedTransactions(void)
{
    Queue q;
    QueueInit(&q);
    populateQueue(&q);
     printQueue(&q);
}


void recieveTransactionDataTest(void)
{
    ST_transaction_t transactionData;
    EN_transState_t result = recieveTransactionData(&transactionData);

    printf("Tester Name: Mostafa AboSalama\n");
    printf("Function Name: recieveTransactionData\n");
    printf("Test Case:\n");
    printf("Input Data:\n");
    printf("Expected Result: \n");
    printf("Actual Result: %s\n", transStateStrings[result]);
    printf("\n");
}


void isValidAccountTest(void)
{

    ST_cardData_t cardData;

    ST_accountsDB_t accountReference;

    EN_serverError_t result = isValidAccount(&cardData, &accountReference);

    printf("Tester Name: Mostafa AboSalama\n");
    printf("Function Name: isValidAccount\n");
    printf("Test Case:\n");
    printf("Input Data:\n");
    printf("Expected Result:\n");
    printf("Actual Result: %s\n", getServerErrorString(result));
    printf("\n");
}

void isBlockedAccountTest(void)
{
    ST_accountsDB_t accountReference;

    EN_serverError_t result = isBlockedAccount(&accountReference);

    printf("Tester Name: Mostafa AboSalama\n");
    printf("Function Name: isBlockedAccount\n");
    printf("Test Case:\n");
    printf("Input Data:\n");
    printf("Expected Result:\n");
    printf("Actual Result: %s\n", getServerErrorString(result));
    printf("\n");
}

void isAmountAvailableTest(void)
{
    ST_terminalData_t termData;

    ST_accountsDB_t accountReference;

    EN_serverError_t result = isAmountAvailable(&termData, &accountReference);

    printf("Tester Name: Mostafa AboSalama\n");
    printf("Function Name: isAmountAvailable\n");
    printf("Test Case:\n");
    printf("Input Data:\n");
    printf("Expected Result:\n");
    printf("Actual Result: %s\n", getServerErrorString(result));
    printf("\n");
}

void saveTransactionTest(void)
{
    ST_transaction_t transactionData;

    EN_serverError_t result = saveTransaction(&transactionData);

    printf("Tester Name: Mostafa AboSalama\n");
    printf("Function Name: saveTransaction\n");
    printf("Test Case:\n");
    printf("Input Data:\n");
    printf("Expected Result:\n");
    printf("Actual Result: %s\n", getServerErrorString(result));
    printf("\n");
}

void listSavedTransactionsTest(void)
{
    printf("Tester Name: Mostafa AboSalama\n");
    printf("Function Name: listSavedTransactions\n");
    printf("Test Case:\n");
    printf("InputData:\n");
    printf("Expected Result:\n");

    printf("Actual Result:\n");
    printf("\n");
}


const char* getServerErrorString(EN_serverError_t error)
{
    switch (error)
    {
        case SERVER_OK:
            return "SERVER_OK";
        case SAVING_FAILED:
            return "SAVING_FAILED";
        case TRANSACTION_NOT_FOUND:
            return "TRANSACTION_NOT_FOUND";
        case ACCOUNT_NOT_FOUND:
            return "ACCOUNT_NOT_FOUND";
        case LOW_BALANCE:
            return "LOW_BALANCE";
        case BLOCKED_ACCOUNT:
            return "BLOCKED_ACCOUNT";
    }
}

