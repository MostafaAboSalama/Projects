#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "Server.h"

int main()
{


   printf("Hello\n");
   /*ST_transaction_t transData;
   char* str="10/25";
   strcpy(transData.cardHolderData.cardExpirationDate, str);
   char* str2="Osama";
   strcpy(transData.cardHolderData.cardHolderName, str2);
    char* str3="10/02/2025";
   strcpy(transData.terminalData.transactionDate, str3);
    transData.terminalData.maxTransAmount=1000;
    char* str4="4024007120114508";
   strcpy(transData.cardHolderData.primaryAccountNumber, str4);
   transData.terminalData.transAmount=500;
   transData.transactionSequenceNumber=1;
   transData.transState=APPROVED;


EN_transState_t asd =saveTransaction(&transData);
printf("%s\n", transStateStrings[asd]);


ST_transaction_t transData2;
   char* str10="11/25";
   strcpy(transData2.cardHolderData.cardExpirationDate, str10);
   char* str11="ALI";
   strcpy(transData2.cardHolderData.cardHolderName, str11);
    char* str12="10/08/2025";
   strcpy(transData2.terminalData.transactionDate, str12);
    transData2.terminalData.maxTransAmount=2000;
    char* str13="4024007120114508";
   strcpy(transData2.cardHolderData.primaryAccountNumber, str13);
   transData2.terminalData.transAmount=500;
   transData2.transactionSequenceNumber=1;
   transData2.transState=APPROVED;

EN_transState_t asd2 =saveTransaction(&transData2);
printf("%s\n", transStateStrings[asd2]);
printf("%d\n", transData2.transactionSequenceNumber);
printf("TEST\n");

  /* Queue q;
    QueueInit(&q);
    populateQueue(&q);
     printQueue(&q);
    /* printf("%d\n",QueueSize(&q));
   ST_transaction_t transData;
   char* str="4024007120114508";
   strcpy(transData.cardHolderData.primaryAccountNumber, str);
   append(&q,&transData);
  // EN_transState_t asd =recieveTransactionData(&transData);
//printf("%s\n", transStateStrings[asd]);
 ST_transaction_t transData2;
   char* str2="402400712011508";
   strcpy(transData2.cardHolderData.primaryAccountNumber, str2);
   append(&q,&transData);
   printf("%d\n",QueueSize(&q));
   printQueue(&q);
   /*EN_transState_t asd2 =recieveTransactionData(&transData2);
printf("%s\n", transStateStrings[asd2]);*/

    //printQueue(&q);

   /* List lst;
    ListInit(&lst);
    populateListFromFile(&lst);
    //ListPrint(&lst);
    ST_cardData_t CardData;
    char* str="453263803268581";
   strcpy(CardData.primaryAccountNumber, str);
    ValidationResult asd = isValidAccountLoop(&lst,&CardData);
if(asd.error==ACCOUNT_NOT_FOUND)
    printf("NOT FOUND");
else
    printf("index=%d",asd.index);


    /*ST_terminalData_t termData;
    termData.transAmount=5000;
    printf("transAmount = %0.2f\n",termData.transAmount);
    printf("balance = %0.2f\n",lst.data[0]->balance);
     EN_serverError_t asd = isAmountAvailable(&termData, lst.data[0]);
printf("%s\n", getServerErrorString(asd));*/

    //printf("MOSTAFA\n");
    /*ST_cardData_t CardData;
    EN_serverError_t asd = isBlockedAccount(lst.data[0]);
    printf("%s\n", getServerErrorString(asd));*/
//printf("%s",accountStateStrings[lst.data[0]]);
   /* char* str="4532638032685881";
   strcpy(CardData.primaryAccountNumber, str);
    //CardData.primaryAccountNumber={"4532638032685881"};

   EN_serverError_t asd = isValidAccountLoop(&lst,&CardData);
printf("%s\n", getServerErrorString(asd));*/
  // printf("MOSTAFA\n");
    return 0;
}
