#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>

#include "library.h"
#include "../Card/Card.h"

typedef enum EN_terminalError_t
{
  TERMINAL_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT,
  EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData);

EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t* termData);

EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData);

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData);

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData, float maxAmount);

EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData);

void getTransactionAmountTest(void);

void isBelowMaxAmountTest(void);

const char* getTerminalErrorString(EN_terminalError_t error);

bool isLeapYear(int year);

EN_terminalError_t validateTransactionDate(const char *date);

void getTransactionDateTest(void);

void setMaxAmountTest(void);

void isCardExpiredTest(void);

void isValidCardPANTest(void);

#endif // TERMINAL_H_INCLUDED
