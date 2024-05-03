#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "Terminal.h"
#include <time.h>

bool isLeapYear(int year)
{
    if (year % 4 != 0)
        return false;
    else if (year % 100 != 0)
        return true;
    else if (year % 400 != 0)
        return false;
    else
        return true;
}

EN_terminalError_t validateTransactionDate(const char *date)
{
    int day, month, year;

    if (sscanf(date, "%2d/%2d/%4d", &day, &month, &year) != 3)
    return WRONG_DATE;

    if (month < 1 || month > 12)
        return WRONG_DATE;

    int maxDay = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        maxDay = 30;
    else if (month == 2)
    {
        maxDay = isLeapYear(year) ? 29 : 28;
    }

    if (day < 1 || day > maxDay)
        return WRONG_DATE;


    return TERMINAL_OK;
}


EN_terminalError_t getTransactionDate(ST_terminalData_t *termData) // add function to check date
{

    int day, month, year;

    printf("Enter the transaction date: ");
   scanf("%s",termData->transactionDate);


    if(strlen(termData->transactionDate)!=10)
        return WRONG_DATE;

    if (termData->transactionDate[2] != '/' || termData->transactionDate[5] != '/')
        return WRONG_DATE;

    EN_terminalError_t checkResult=validateTransactionDate(termData->transactionDate);
    if(checkResult != TERMINAL_OK)
        return checkResult;

    return TERMINAL_OK;
}

void getTransactionDateTest(void)
{
    ST_terminalData_t termData;

    printf("Tester Name: Mostafa Abd-Allah AboSalama\n");
    printf("Function Name: getTransactionDate\n");
    for(int i=0;i<10;i++)
    {
         printf("Test Case %d:\n",i+1);
         EN_terminalError_t error = getTransactionDate(&termData);
         printf("Input Data: %s\n",termData.transactionDate);
         printf("Actual Result: %s\n", getTerminalErrorString(error));
    }
}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
    int cardMonth, cardYear, transactionDay, transactionMonth, transactionYear;
    if (sscanf(cardData->cardExpirationDate, "%2d/%2d", &cardMonth, &cardYear) != 2)
        return WRONG_EXP_DATE;
    if (sscanf(termData->transactionDate, "%2d/%2d/%4d", &transactionDay, &transactionMonth, &transactionYear) != 3)
        return WRONG_DATE;


    int cardYearFull = 2000 + cardYear; // Convert the two-digit card year to full year

    if (transactionYear > cardYearFull )
        return EXPIRED_CARD;
    else if (transactionYear == cardYearFull && transactionMonth > cardMonth)
        return EXPIRED_CARD;
    else if (transactionYear == cardYearFull && transactionMonth == cardMonth && transactionDay > 0)
        return EXPIRED_CARD;

    return TERMINAL_OK;
}




EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    printf("Enter the transaction amount : ");
    scanf("%f",&termData->transAmount);
    if(termData->transAmount <=0)
        return INVALID_AMOUNT;
    else
        return TERMINAL_OK;
}

void getTransactionAmountTest(void)
{
    ST_terminalData_t termData;

    printf("Tester Name: Mostafa Abd-Allah AboSalama\n");
    printf("Function Name: getTransactionAmount\n");
    for(int i=0;i<2;i++)
    {
         printf("Test Case %d:\n",i+1);
         EN_terminalError_t error = getTransactionAmount(&termData);
         printf("Input Data: %0.2f\n",termData.transAmount);
         printf("Actual Result: %s\n", getTerminalErrorString(error));
    }
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData, float maxAmount) //check
{
    if (maxAmount <= 0)
        return INVALID_MAX_AMOUNT;

    termData->maxTransAmount = maxAmount;
    return TERMINAL_OK;
}
void setMaxAmountTest(void) //check
{
    ST_terminalData_t termData;

    printf("Tester Name: Mostafa Abd-Allah AboSalama\n");
    printf("Function Name: setMaxAmount\n");
   // printf("Test Case %d:\n",i+1);
    EN_terminalError_t error = setMaxAmount(&termData ,150);
    printf("Input Data: %0.2f\n",termData.maxTransAmount);
    printf("Actual Result: %s\n", getTerminalErrorString(error));

}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    //printf("%0.2f\n",termData->transAmount);
    //printf("%0.2f\n",termData->maxTransAmount);
    if (termData->transAmount > termData->maxTransAmount)
        return EXCEED_MAX_AMOUNT;

    return TERMINAL_OK;
}

void isBelowMaxAmountTest(void)
{
    ST_terminalData_t termData;

    printf("Tester Name: Mostafa Abd-Allah AboSalama\n");
    printf("Function Name: isBelowMaxAmount\n");
    EN_terminalError_t error = isBelowMaxAmount(&termData);
    printf("Input Data: %f\n",termData.maxTransAmount);
    printf("Actual Result: %s\n", getTerminalErrorString(error));
}



EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData)
{
    int sum=0;
    int len=strlen(cardData->primaryAccountNumber);
    int digit=0;
    for(int i=len-1;i>=0;i--)
    {
        digit=cardData->primaryAccountNumber[i]-'0';
        if(i % 2 ==0)
        {
            digit*=2;
            if(digit>=9)
                digit-=9;
        }
        sum+=digit;
    }
    if(sum % 10 !=0)
       return INVALID_CARD;

    return TERMINAL_OK;
}

void isValidCardPANTest(void)
{
    ST_cardData_t cardData;
   for(int i=0;i<2;i++)
    {
        EN_cardError_t card_error = getCardPAN(&cardData);
        EN_terminalError_t terminal_error = isValidCardPAN(&cardData);
        printf("Test Case 1:\n");
        printf("Input Data: %s\n",cardData.primaryAccountNumber);
        printf("Actual Result: %s\n", getTerminalErrorString(terminal_error));
        printf("\n");
    }

}

const char* getTerminalErrorString(EN_terminalError_t error)
{
    switch (error)
    {
        case TERMINAL_OK:
            return "TERMINAL_OK";
        case WRONG_DATE:
            return "WRONG_DATE";
        case EXPIRED_CARD:
            return "EXPIRED_CARD";
        case INVALID_CARD:
            return "INVALID_CARD";
        case INVALID_AMOUNT:
            return "INVALID_AMOUNT";
        case EXCEED_MAX_AMOUNT:
            return "EXCEED_MAX_AMOUNT";
        case INVALID_MAX_AMOUNT:
            return "INVALID_MAX_AMOUNT";
    }
}

