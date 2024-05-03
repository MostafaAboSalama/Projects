#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "App.h"

void appStart(void)
{
    ST_cardData_t cardData;

    EN_cardError_t name = getCardHolderName(&cardData);
    if(name==WRONG_NAME)
        {
            printf("%s\n",getCardErrorString(name));
            exit(1);
        }

    EN_cardError_t ExpDate = getCardExpiryDate(&cardData);
    if(ExpDate==WRONG_EXP_DATE)
        {
            printf("%s\n",getCardErrorString(ExpDate));
            exit(1);
        }

     EN_cardError_t PAN = getCardPAN(&cardData);
    if(PAN==WRONG_PAN)
        {
            printf("%s\n",getCardErrorString(PAN));
            exit(1);
        }

    ST_terminalData_t termData;

    EN_terminalError_t validPAN= isValidCardPAN(&cardData);
    if(validPAN==INVALID_CARD)
        {
            printf("%s\n",getTerminalErrorString(validPAN));
            exit(1);
        }

    EN_terminalError_t TransDate= getTransactionDate(&termData);
    if(TransDate==WRONG_DATE)
        {
            printf("%s\n",getTerminalErrorString(TransDate));
            exit(1);
        }
    EN_terminalError_t isExpired= isCardExpired(&cardData, &termData);
    if(isExpired==EXPIRED_CARD)
        {
            printf("%s\n",getTerminalErrorString(isExpired));
            exit(1);
        }

    EN_terminalError_t maxAmount= setMaxAmount(&termData,1000);
    if(maxAmount==INVALID_MAX_AMOUNT)
       {
            printf("%s\n",getTerminalErrorString(maxAmount));
            exit(1);
        }

    EN_terminalError_t transAmount= getTransactionAmount(&termData);
    if(transAmount==INVALID_AMOUNT)
        {
            printf("%s\n",getTerminalErrorString(transAmount));
            exit(1);
        }

    EN_terminalError_t isExceddedAmount= isBelowMaxAmount(&termData);
    if(isExceddedAmount==EXCEED_MAX_AMOUNT)
       {
            printf("%s\n",getTerminalErrorString(isExceddedAmount));
            exit(1);
        }

    ST_transaction_t transData;

    ServerInit(&cardData, &termData, &transData);
    EN_transState_t isValid= recieveTransactionData(&transData);
    if(isValid!= SERVER_OK)
        {
            printf("%s\n",transStateStrings[isValid]);
            exit(1);
        }

    printf("Succedded\n");
}
