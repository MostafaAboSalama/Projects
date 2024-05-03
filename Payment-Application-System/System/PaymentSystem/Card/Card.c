#include "Card.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
    printf("Enter the card holder's name : ");
    gets(cardData->cardHolderName);
    if(strlen(cardData->cardHolderName) == 0 || strlen(cardData->cardHolderName) > 24 || strlen(cardData->cardHolderName) < 20)
        return WRONG_NAME;
    else
        return CARD_OK;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
    printf("Enter Card Expiry Date(MM/YY) : ");
    gets(cardData->cardExpirationDate);
    if(strlen(cardData->cardExpirationDate)!=5 ||
       cardData->cardExpirationDate[2]!='/' ||
       !isNumeric(cardData->cardExpirationDate ,2) ||
       !isNumeric(cardData->cardExpirationDate+3 ,2) ||
       !isMonths(cardData->cardExpirationDate) ||
       !isYear(cardData->cardExpirationDate))
        return WRONG_EXP_DATE;
    else
        return CARD_OK;

}

EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
    printf("Enter the card PAN: ");
    scanf("%s",cardData->primaryAccountNumber);
    int panLength=strlen(cardData->primaryAccountNumber);

    if (panLength == 0 || panLength < 16 || panLength > 19)
        {
            return WRONG_PAN;
            exit(1);
        }
    else
        return CARD_OK;
}

const char* getCardErrorString(EN_cardError_t error)
{
    switch (error)
    {
        case CARD_OK:
            return "CARD_OK";
        case WRONG_NAME:
            return "WRONG_NAME";
        case WRONG_EXP_DATE:
            return "WRONG_EXP_DATE";
        case WRONG_PAN:
            return "WRONG_PAN";
    }
}

void getCardHolderNameTest(void)
{
    ST_cardData_t cardData;

    printf("Tester Name: Mostafa Abd-Allah AboSalama\n");
    printf("Function Name: getCardHolderName\n");
    for(int i=0;i<3;i++)
    {
         printf("Test Case %d:\n",i+1);
         EN_cardError_t error = getCardHolderName(&cardData);
         printf("Input Data: %s\n",cardData.cardHolderName);
         //printf("Expected Result: WRONG_NAME\n");
         printf("Actual Result: %s\n", getCardErrorString(error));
    }
}

void getCardExpiryDateTest(void)
{
    ST_cardData_t cardData;

    printf("Tester Name: Mostafa Abd-Allah AboSalama\n");
    printf("Function Name: getCardExpiryDate\n");
    for(int i=0;i<5;i++)
    {
         printf("Test Case %d:\n",i+1);
         EN_cardError_t error = getCardExpiryDate(&cardData);
         printf("Input Data: %s\n",cardData.cardExpirationDate);
         //printf("Expected Result: WRONG_NAME\n");
         printf("Actual Result: %s\n", getCardErrorString(error));
    }
}

int isNumeric(char* str ,int len)
{
    for(int i=0;i<len;i++)
    {
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}

int isMonths(char* str)
{
    int months= atoi(str);
    return (months>0 && months <=12);
}

int isYear(char* str)
{
    int years= atoi(str+3);
    return (years>=0 && years <=99);
}
void getCardPANTest(void)
{
    ST_cardData_t cardData;

    printf("Tester Name: Mostafa Abd-Allah AboSalama\n");
    printf("Function Name: getCardPAN\n");
    for(int i=0;i<3;i++)
    {
         printf("Test Case %d:\n",i+1);
         EN_cardError_t error = getCardPAN(&cardData);
         printf("Input Data: %s\n",cardData.primaryAccountNumber);
         //printf("Expected Result: WRONG_NAME\n");
         printf("Actual Result: %s\n", getCardErrorString(error));
    }
}
