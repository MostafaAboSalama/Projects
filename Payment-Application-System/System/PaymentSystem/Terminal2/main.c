
#include "Terminal.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{

   // isValidCardPANTest();
    // getTransactionDateTest();
    /* ST_cardData_t cardData2;
    ST_terminalData_t termData2;
    // EN_terminalError_t res1=getTransactionDate(&termData2);
    // printf("%s\n",getTerminalErrorString(res1));
   EN_terminalError_t res= isCardExpired(&cardData2,&termData2);
    printf("%s\n",getTerminalErrorString(res));*/
    /*ST_cardData_t cardData2;
    ST_terminalData_t termData2;
    getTransactionAmount(&termData2);
    setMaxAmount(&termData2,170);
   EN_terminalError_t res= isBelowMaxAmount(&termData2);
   printf("%s\n",getTerminalErrorString(res));*/
   ST_cardData_t cardData2;
    ST_terminalData_t termData2;
     EN_terminalError_t TransDate=getTransactionDate(&termData2);
     printf("%s\n",getTerminalErrorString(TransDate));
     EN_cardError_t EXPDate=getCardExpiryDate(&cardData2);
     printf("%s\n",getCardErrorString(EXPDate));
   EN_terminalError_t res=isCardExpired(&cardData2, &termData2);
  printf("%s\n",getTerminalErrorString(res));
    return 0;
}
