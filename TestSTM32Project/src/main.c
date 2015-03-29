#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_cortex.h"
#include "stm32f4xx_hal_gpio.h"
int main(int argc, char* argv[])
{
	  HAL_Init();
	  HAL_SuspendTick();
	  //configure_system_clock();
	  __GPIOD_CLK_ENABLE();
	  GPIO_InitTypeDef GPIO_D;
	  GPIO_D.Pin = GPIO_PIN_15;
	  GPIO_D.Pull = GPIO_PULLUP;
	  GPIO_D.Alternate = GPIO_AF0_RTC_50Hz;
	  GPIO_D.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_D.Speed = GPIO_SPEED_LOW;
	  HAL_GPIO_Init(GPIOD,&GPIO_D);
	  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_SET);
	  int i = 0;
	  int toggle = 0;
	  while(1){
		  if(toggle == 0){
			  toggle = 1;
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_SET);

		  }
		  else{
			  toggle = 0;
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_RESET);
		  }
		  for(i = 0;i<1000;i++);
	  }

}
