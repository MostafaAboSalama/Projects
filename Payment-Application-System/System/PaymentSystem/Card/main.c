#include "Card.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
   // ST_cardData_t cardData;
    /*EN_cardError_t error =getCardExpiryDate(&cardData);
    printf("%s",getCardErrorString(error));*/
    getCardPANTest();
    getCardExpiryDateTest();
    getCardHolderNameTest();

    return 0;
}
