/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mostafa AboSalama
 *  Layer  : HAL
 *  SWC    : KPD
 *
 */

#include <util/delay.h>

#include "../4-LIB/STD_TYPES.h"
#include "../4-LIB/BIT_MATH.h"

#include "../1-MCAL/DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"


void KPD_Init(void){

	/*                    connect pull up for the pins of the rows                             */

	DIO_enumConnectPullup        ( KPD_PORT , KPD_R0 , DIO_PIN_HIGH );
	DIO_enumConnectPullup        ( KPD_PORT , KPD_R1 , DIO_PIN_HIGH );
	DIO_enumConnectPullup        ( KPD_PORT , KPD_R2 , DIO_PIN_HIGH );
	DIO_enumConnectPullup        ( KPD_PORT , KPD_R3 , DIO_PIN_HIGH );


	                   


	DIO_enumSetPinDirection( KPD_PORT , KPD_C0 , DIO_PIN_OUTPUT );
	DIO_enumSetPinDirection( KPD_PORT , KPD_C1 , DIO_PIN_OUTPUT );
	DIO_enumSetPinDirection( KPD_PORT , KPD_C2 , DIO_PIN_OUTPUT );
	DIO_enumSetPinDirection( KPD_PORT , KPD_C3 , DIO_PIN_OUTPUT );

	DIO_enumSetPinValue    ( KPD_PORT , KPD_C0 , DIO_PIN_HIGH );
	DIO_enumSetPinValue    ( KPD_PORT , KPD_C1 , DIO_PIN_HIGH );
	DIO_enumSetPinValue    ( KPD_PORT , KPD_C2 , DIO_PIN_HIGH );
	DIO_enumSetPinValue    ( KPD_PORT , KPD_C3 , DIO_PIN_HIGH );

}


u8   KPD_u8GetPressed( void ){

	u8 LOC_u8ReturnData = NOTPRESSED ;
	u8 LOC_u8GetPressed ;
	/* iterators  */
	u8 LOC_u8Row ;
	u8 LOC_u8Col ;

	for( LOC_u8Col = 0 + KPD_COL_INIT ; LOC_u8Col < KPD_COL_END + 1 ; LOC_u8Col++ ){

		DIO_enumSetPinValue    ( KPD_PORT , LOC_u8Col , DIO_PIN_LOW );   // Low on the columns

		for( LOC_u8Row = 0 +KPD_ROW_INIT ; LOC_u8Row < KPD_ROW_END + 1 ; LOC_u8Row++ ){

			DIO_enumGetPinValue( KPD_PORT , LOC_u8Row , &LOC_u8GetPressed ); // retun the row value
			/* 
			if the row is high ....there is no pressed buttons
			if the row is low ....there is pressed button ===>> I will check on this
			 */
			if( LOC_u8GetPressed == 0 )
			{

				_delay_ms(50);   // delay for bouncing

				DIO_enumGetPinValue( KPD_PORT , LOC_u8Row , &LOC_u8GetPressed );   // to make sure that the button is pressed & check again

				if( LOC_u8GetPressed == 0 )

				{
					/*      # Important Note #

					the button will khnow by the row and the column (ASCII Code)
					==> Hint1 : I already defined The ASCII Codes in 2D array at --> "KPD_config.h"
					==> Hint2 : if there is no pressed buttons , it will retured NOTPRESSED (0xff) and there is not any button has this ASCII (0xff)
					*/

					LOC_u8ReturnData = KPD_u8Buttons[ LOC_u8Row - KPD_ROW_INIT ][ LOC_u8Col - KPD_COL_INIT ];

				}

				// stay here if the button is pressed   # we could put delay 200 ms instead of that
				DIO_enumGetPinValue( KPD_PORT , LOC_u8Row , &LOC_u8GetPressed );
				while( DIO_PIN_LOW == LOC_u8GetPressed ) /*  This cond for safty instead of (LOC_u8GetPressed == DIO_PIN_LOW) if i foget = */
				{

					DIO_enumGetPinValue( KPD_PORT , LOC_u8Row , &LOC_u8GetPressed );

				}

				break ;

			}

		}

		// return this column’s pin to high
		DIO_enumSetPinValue    ( KPD_PORT , LOC_u8Col , DIO_PIN_HIGH );

	}

	return LOC_u8ReturnData ;

}
