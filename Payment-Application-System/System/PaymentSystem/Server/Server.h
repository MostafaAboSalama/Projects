#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED
#include "library.h"
#include "../Card/Card.h"
#include "../Terminal2/Terminal.h"
#include "../../DataStructures/Queue/Queue.h"
#include "../../DataStructures/lst/lst.h"
//#include "../../Database/filehandlingtest/file.h"

typedef enum EN_serverError_t
{
SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND,
LOW_BALANCE, BLOCKED_ACCOUNT
}EN_serverError_t ;

EN_transState_t recieveTransactionData(ST_transaction_t *transData);

EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t* accountRefrence);

EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence);

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t* accountRefrence);

EN_serverError_t saveTransaction(ST_transaction_t *transData);

const char* getServerErrorString(EN_serverError_t error);

//int isValidAccountLoop(List* lst, ST_cardData_t* CardData);

void listSavedTransactions(void);

typedef struct {
    int index;
    EN_serverError_t error;
} ValidationResult;

ValidationResult isValidAccountLoop(List* lst, ST_cardData_t* CardData);

void initializeQueue();

extern const char* transStateStrings[];

extern int lastSeqNumber;


void recieveTransactionDataTest(void);

void isValidAccountLoopTest(void);

void isValidAccountTest(void);

void isBlockedAccountTest(void);

void isAmountAvailableTest(void);

void saveTransactionTest(void);

void listSavedTransactionsTest(void);

void ServerInit(ST_cardData_t* cardData, ST_terminalData_t* termData, ST_transaction_t* transData);

#endif // SERVER_H_INCLUDED
