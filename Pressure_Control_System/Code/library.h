#ifndef _LIBRARY_H
#define _LIBRARY_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SET_BIT(ADDRESS,BIT)   ADDRESS |=  (1<<BIT)
#define RESET_BIT(ADDRESS,BIT) ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT)  ADDRESS ^=  (1<<BIT)
#define READ_BIT(ADDRESS,BIT) ((ADDRESS) &   (1<<(BIT)))

#define GPIO_PORTA 0x40010800

#endif /* _LIBRARY_H */