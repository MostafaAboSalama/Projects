#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include "library.h"

#define MAX_TRANSACTIONS 50
#define MAX_ACCOUNTS 50

static int transIndex;
static int accountIndex;

void writeTransactionData(ST_transaction_t* ptrTransactionData);

void readAccountsDataFromFile(ST_accountsDB_t* ptrAccountData[]);

void readTransactionsDataFromFile(ST_transaction_t* ptrTransactionData[]);

void clearAccountDatabase();

void updateAccountDatabsae(ST_accountsDB_t* ptrAccountData);

int getLastTransactionSequenceNumber();

#endif // FILE_H_INCLUDED
