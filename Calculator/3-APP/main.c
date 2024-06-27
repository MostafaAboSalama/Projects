/*
 * main.c
 *
 *  Created on: Jun 23, 2024
 *      Author: AboSalama
 */
#include "../4-LIB/STD_TYPES.h"
#include "../4-LIB/BIT_MATH.h"
#include "../1-MCAL/DIO_interface.h"
#include "../2-HAL/KPD_interface.h"
#include "../2-HAL/CLCD_interface.h"
#include "../4-LIB/stack.h"

void DecToBinary(u16 a);
void Infix();
void Postfix();
//void Prefix();
void processBaseConversion();
void Math();
void handleBaseOperation(u8 pressed);

s16 n1 = 0, n2 = 0;
u8 pressed, operator, binStr[16], i = 0, type;
Stack S;

void main(void)
{
    KPD_Init();
    CLCD_voidInit();

    CLCD_voidSendString("1-Math 2-Base");
    while (1)
    {
        u8 option = KPD_u8GetPressed();
        if (option != NOTPRESSED)
        {
            CLCD_voidClearScreen();

            if (option == '1')
            	Math();

            else if (option == '2')
                processBaseConversion();

        }
    }
}

void Infix()
{

    CLCD_voidClearScreen();
    CLCD_voidSendString("Math Mode: Infix.");
    CLCD_voidSetPosition(2, 1);
    while (1)
    {

        pressed = KPD_u8GetPressed();
        if (pressed != NOTPRESSED)
        {

            if (pressed >= '0' && pressed <= '9')
            {

                CLCD_voidSendData(pressed);
                n1 = n1 * 10 + (pressed - '0');
            }
            else if (pressed == '+' || pressed == '-' || pressed == '*' || pressed == '/')
            {
                CLCD_voidSendData(pressed);
                operator = pressed;
                n2 = n1;
                n1 = 0;
            }
            else if (pressed == '=')
            {
                CLCD_voidSendData(pressed);
                switch (operator)
                {
                    case '+': CLCD_voidSendNumber(n1 + n2); break;
                    case '-': CLCD_voidSendNumber(n2 - n1); break;
                    case '*': CLCD_voidSendNumber(n1 * n2); break;
                    case '/': CLCD_voidSendNumber(n2 / n1); break;
                }
            }
            else if (pressed == '?')
            {
                n1 = 0;
                n2 = 0;
                CLCD_voidClearScreen();
                CLCD_voidSendString("Math Mode : Infix.");
                CLCD_voidSetPosition(2, 1);
            }
        }
    }
}

void Postfix()
{
    CLCD_voidClearScreen();
    CLCD_voidSendString("Math Mode: Postfix.");
    CLCD_voidSetPosition(2, 1);
    S.top = 0;
    while (1)
    {
        pressed = KPD_u8GetPressed();
        if (pressed != NOTPRESSED) {

            if (pressed == '+' || pressed == '-' || pressed == '*' || pressed == '/')
            {
                CLCD_voidSendData(pressed);
                pop(&n2, &S);
                pop(&n1, &S);
                switch (pressed) {
                    case '+': push(n1 + n2, &S); break;
                    case '-': push(n1 - n2, &S); break;
                    case '*': push(n1 * n2, &S); break;
                    case '/': push(n1 / n2, &S); break;
                }
            }
            else if (pressed >= '0' && pressed <= '9')
            {
                CLCD_voidSendData(pressed);
                push(pressed - '0', &S);
            }
            else if (pressed == '=')
            {
                CLCD_voidSendData(pressed);
                pop(&n1, &S);
                CLCD_voidSendNumber(n1);
            }
            else if (pressed == '?')
            {
                CLCD_voidClearScreen();
                CLCD_voidSendString("Math Mode: Postfix.");
                CLCD_voidSetPosition(2, 1);
                n1 = 0;
                n2 = 0;
                S.top = 0;
            }
        }
    }
}

/*void Prefix() {
    CLCD_voidClearScreen();
    S.top = 0;
    u8 expression[16], len, temp;
    while (1) {
        pressed = KPD_u8GetPressed();
        if (pressed != NOTPRESSED) {
            if (pressed == '=') {
                CLCD_voidSendData(pressed);
                break;
            } else {
                CLCD_voidSendData(pressed);
                expression[i++] = pressed;
            }
        }
    }

    expression[i] = '\0';
    len = i;
    for (i = 0; i < len / 2; ++i) {
        temp = expression[i];
        expression[i] = expression[len - 1 - i];
        expression[len - 1 - i] = temp;
    }

    for (i = 0; i < len; ++i) {
        pressed = expression[i];
        if (pressed == '+' || pressed == '-' || pressed == '*' || pressed == '/') {
            pop(&n1, &S);
            pop(&n2, &S);
            switch (pressed) {
                case '+': push(n1 + n2, &S); break;
                case '-': push(n1 - n2, &S); break;
                case '*': push(n1 * n2, &S); break;
                case '/':
                    if (n2 != 0) {
                        push(n1 / n2, &S);
                    } else {
                        CLCD_voidSendString("ERROR");
                    }
                    break;
            }
        } else if (pressed >= '0' && pressed <= '9') {
            push(pressed - '0', &S);
        }
    }

    pop(&n1, &S);
    CLCD_voidSendNumber(n1);
}*/

void Math()
{
    CLCD_voidSendString("1-Infix 2-Postfix");
    while (1)
    {
        u8 order = KPD_u8GetPressed();
        if (order != NOTPRESSED)
        {
            CLCD_voidClearScreen();
            if (order == '1')
            	Infix();

            else if (order == '2')
            	Postfix();

            else if (order == '3')
                //Prefix();

            break;
        }
    }
}

void processBaseConversion()
{
    CLCD_voidSendString("Dec2Hex Bin2Dec");
    CLCD_voidSetPosition(2, 5);
    CLCD_voidSendString("3-Dec2Bin");
    while (1)
    {
        type = KPD_u8GetPressed();
        if (type != NOTPRESSED)
        {
            CLCD_voidClearScreen();
            if (type == '1')
            {
                CLCD_voidSendString("Dec2Hex.");
            }
            else if (type == '2')
            {
                CLCD_voidSendString("Bin2Dec.");
            }
            else if (type == '3')
            {
                CLCD_voidSendString("Dec2Bin.");
            }
            CLCD_voidSetPosition(2, 1);
            while (1)
            {
                pressed = KPD_u8GetPressed();
                if (pressed != NOTPRESSED) {
                    handleBaseOperation(pressed);
                }
            }
        }
    }
}

void handleBaseOperation(u8 pressed)
{
    if (type == '1' || type == '3')
    {
        if (pressed >= '0' && pressed <= '9') {
            CLCD_voidSendData(pressed);
            n1 = n1 * 10 + (pressed - '0');
        }
        else if (pressed == '=')
        {
            CLCD_voidClearScreen();
            if (type == '1')
            {
                CLCD_voidSendString("Dec2Hex.");
                CLCD_voidSetPosition(2, 1);
                u8 hex[20];
                sprintf(hex, "%X", n1);
                CLCD_voidSendString(hex);
            }
            else if (type == '3')
            {
                CLCD_voidSendString("Dec2Bin.");
                CLCD_voidSetPosition(2, 1);
                DecToBinary(n1);
            }
        }
        else if (pressed == '?')
        {
            n1 = 0;
            CLCD_voidClearScreen();
            if (type == '1')
            {
                CLCD_voidSendString("Dec2Hex.");
            }
            else if (type == '3')
            {
                CLCD_voidSendString("Dec2Bin.");
            }
            CLCD_voidSetPosition(2, 1);
        }
    }
    else if (type == '2')
    {
        if (pressed >= '0' && pressed <= '1')
        {
            CLCD_voidSendData(pressed);
            binStr[i++] = pressed;
            binStr[i] = '\0';
        }
        else if (pressed == '=')
        {
            CLCD_voidClearScreen();
            CLCD_voidSendString("Bin2Dec.");
            CLCD_voidSetPosition(2, 1);
            u16 decimal = 0;
            for (u8 j = 0; j < i; ++j)
            {
                decimal = decimal * 2 + (binStr[j] - '0');
            }
            CLCD_voidSendNumber(decimal);
        }
        else if (pressed == '?')
        {
            i = 0;
            binStr[0] = '\0';
            CLCD_voidClearScreen();
            CLCD_voidSendString("Bin2Dec.");
            CLCD_voidSetPosition(2, 1);
        }
    }
}

void DecToBinary(u16 a)
{
    if (a > 1) DecToBinary(a / 2);
    CLCD_voidSendNumber(a % 2);
}
