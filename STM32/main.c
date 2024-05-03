
#include <stdint.h>
#include "stm32f103x6.h"
#include "Stm32_F103C6_GPIO.h"
#include "lcd.h"


void clock_init()
{
	//Enable port A clock
	RCC_GPIOA_CLK_EN();
	//Enable port B clock
	RCC_GPIOB_CLK_EN();
}
void wait_ms(uint32_t time){
	uint32_t i,j;
	for(i=0;i<time;i++)
		for(j=0;j<255;j++);
}//hint time :100 == 1 sec

int main(void)
{
	clock_init();
	lcd_init();
	
	GPIO_PIN_CONFIG_T PinConfig;
	PinConfig.GPIO_PIN_NUMBER = GPIO_PIN_1;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_2MHz;
	
	GPIO_t *GPIOx = GPIOB;
	MCAL_GPIO_Init(GPIOx, &PinConfig);
	
	GPIO_PIN_CONFIG_T PinConfig2;
	PinConfig2.GPIO_PIN_NUMBER = GPIO_PIN_12;
	PinConfig2.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig2.GPIO_OUTPUT_SPEED = GPIO_SPEED_2MHz;
	
	GPIO_t *GPIOx2 = GPIOB;
	MCAL_GPIO_Init(GPIOx2, &PinConfig2);
	
	GPIO_PIN_CONFIG_T PinConfig3;
	PinConfig3.GPIO_PIN_NUMBER = GPIO_PIN_3;
	PinConfig3.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig3.GPIO_OUTPUT_SPEED = GPIO_SPEED_2MHz;
	
	GPIO_t *GPIOx3 = GPIOB;
	MCAL_GPIO_Init(GPIOx3, &PinConfig3);
	
	GPIO_PIN_CONFIG_T PinConfig4;
	PinConfig4.GPIO_PIN_NUMBER = GPIO_PIN_13;
	PinConfig4.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig4.GPIO_OUTPUT_SPEED = GPIO_SPEED_2MHz;
	
	GPIO_t *GPIOx4 = GPIOB;
	MCAL_GPIO_Init(GPIOx4, &PinConfig4);
	
	GPIO_PIN_CONFIG_T PinConfig5;
	PinConfig5.GPIO_PIN_NUMBER = GPIO_PIN_14;
	PinConfig5.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig5.GPIO_OUTPUT_SPEED = GPIO_SPEED_2MHz;
	
	GPIO_t *GPIOx5 = GPIOB;
	MCAL_GPIO_Init(GPIOx5, &PinConfig5);
	
	GPIO_PIN_CONFIG_T PinConfig6;
	PinConfig6.GPIO_PIN_NUMBER = GPIO_PIN_15;
	PinConfig6.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig6.GPIO_OUTPUT_SPEED = GPIO_SPEED_2MHz;
	
	GPIO_t *GPIOx6 = GPIOB;
	MCAL_GPIO_Init(GPIOx6, &PinConfig6);
	
	GPIO_PIN_CONFIG_T PinConfig7;
	PinConfig7.GPIO_PIN_NUMBER = GPIO_PIN_11;
	PinConfig7.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig7.GPIO_OUTPUT_SPEED = GPIO_SPEED_2MHz;
	
	GPIO_t *GPIOx7 = GPIOB;
	MCAL_GPIO_Init(GPIOx7, &PinConfig7);
	
	
	GPIO_PIN_CONFIG_T PinConfig8;
	PinConfig8.GPIO_PIN_NUMBER = GPIO_PIN_10;
	PinConfig8.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig8.GPIO_OUTPUT_SPEED = GPIO_SPEED_2MHz;
	
	GPIO_t *GPIOx8 = GPIOB;
	MCAL_GPIO_Init(GPIOx8, &PinConfig8);
	
	GPIO_PIN_CONFIG_T PinConfig9;
	PinConfig9.GPIO_PIN_NUMBER = GPIO_PIN_4;
	PinConfig9.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig9.GPIO_OUTPUT_SPEED = GPIO_SPEED_2MHz;
	
	GPIO_t *GPIOx9 = GPIOB;
	MCAL_GPIO_Init(GPIOx9, &PinConfig9);
	
	GPIO_PIN_CONFIG_T PinConfig10;
	PinConfig10.GPIO_PIN_NUMBER = GPIO_PIN_5;
	PinConfig10.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig10.GPIO_OUTPUT_SPEED = GPIO_SPEED_2MHz;
	
	GPIO_t *GPIOx10 = GPIOB;
	MCAL_GPIO_Init(GPIOx10, &PinConfig10);
	
	GPIO_PIN_CONFIG_T PinConfig11;
	PinConfig11.GPIO_PIN_NUMBER = GPIO_PIN_6;
	PinConfig11.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig11.GPIO_OUTPUT_SPEED = GPIO_SPEED_2MHz;
	
	GPIO_t *GPIOx11 = GPIOB;
	MCAL_GPIO_Init(GPIOx11, &PinConfig11);
	
	GPIO_PIN_CONFIG_T PinConfig12;
	PinConfig12.GPIO_PIN_NUMBER = GPIO_PIN_7;
	PinConfig12.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig12.GPIO_OUTPUT_SPEED = GPIO_SPEED_2MHz;
	
	GPIO_t *GPIOx12 = GPIOB;
	MCAL_GPIO_Init(GPIOx12, &PinConfig12);
	
	lcd_set_position(FIRST_LINE, 5);
	lcd_send_string("IEEE");
	while(1)
	{
		// implementation
		/*lcd_set_position(FIRST_LINE, 5);
		lcd_send_string("IEEE");*/
		wait_ms(500);
		lcd_clear();
		lcd_send_string("Ramadan Kareem");
		MCAL_GPIO_TogglePin(GPIOx, GPIO_PIN_1) ;
		MCAL_GPIO_TogglePin(GPIOx2, GPIO_PIN_12);
		MCAL_GPIO_TogglePin(GPIOx3, GPIO_PIN_3);
		MCAL_GPIO_TogglePin(GPIOx4, GPIO_PIN_13);
		MCAL_GPIO_TogglePin(GPIOx5, GPIO_PIN_14);
		MCAL_GPIO_TogglePin(GPIOx6, GPIO_PIN_11);
		MCAL_GPIO_TogglePin(GPIOx7, GPIO_PIN_10);
		MCAL_GPIO_TogglePin(GPIOx8, GPIO_PIN_15);
		MCAL_GPIO_TogglePin(GPIOx9, GPIO_PIN_4);
		MCAL_GPIO_TogglePin(GPIOx10, GPIO_PIN_5);
		MCAL_GPIO_TogglePin(GPIOx11, GPIO_PIN_6);
		MCAL_GPIO_TogglePin(GPIOx12, GPIO_PIN_7);
		/*wait_ms(500);
		MCAL_GPIO_WritePin(GPIOx, GPIO_PIN_12, GPIO_PIN_RESET);
		wait_ms(500);
		MCAL_GPIO_WritePin(GPIOx2, GPIO_PIN_12, GPIO_PIN_SET);
		wait_ms(500);
		MCAL_GPIO_WritePin(GPIOx2, GPIO_PIN_12, GPIO_PIN_RESET);
		wait_ms(500);
		MCAL_GPIO_WritePin(GPIOx3, GPIO_PIN_3, GPIO_PIN_SET);
		wait_ms(500);
		MCAL_GPIO_WritePin(GPIOx3, GPIO_PIN_3, GPIO_PIN_RESET);
		wait_ms(500);
		*/
	}

}