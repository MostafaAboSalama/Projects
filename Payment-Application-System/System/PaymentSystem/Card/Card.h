#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <stdint.h>
#include "library.h"

typedef enum EN_cardError_t
{
CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;

EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);
void getCardPANTest();

const char* getCardErrorString(EN_cardError_t error);

void getCardHolderNameTest(void);

const char* getCardErrorString(EN_cardError_t error);

void getCardHolderNameTest(void);

void getCardExpiryDateTest(void);

int isNumeric(char* str ,int len);

int isMonths(char* str);

int isYear(char* str);


#endif // CARD_H_INCLUDED
