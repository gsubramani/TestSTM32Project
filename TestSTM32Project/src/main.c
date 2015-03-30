#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_cortex.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_tim.h"
int main(int argc, char* argv[])
{
	//pwm_gen();
	HAL_Init();
	  HAL_SuspendTick();
	  //configure_system_clock();
	  __GPIOD_CLK_ENABLE(); // Not sure if this is necessary
	  //////GPIO configuration
	  GPIO_InitTypeDef GPIO_D;	// SEE 19.2.2 of HAL driver manual
	  GPIO_D.Pin = GPIO_PIN_15;
	  GPIO_D.Pull = GPIO_PULLUP;
	  GPIO_D.Alternate = GPIO_AF0_RTC_50Hz;
	  GPIO_D.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_D.Speed = GPIO_SPEED_LOW;
	  HAL_GPIO_Init(GPIOD,&GPIO_D);
	  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_SET);
	  //////// Toggle LED code, for blinking blue LED
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

/*void pwm_gen()
{
	//HAL_TIM_PWM_MspInit();
	__TIM1_CLK_ENABLE(); // Use __TIMx_CLK_ENABLE();
	__GPIOD_CLK_ENABLE();
	  GPIO_InitTypeDef GPIO_D;	// SEE 19.2.2 of HAL driver manual
	  GPIO_D.Pin = GPIO_PIN_15;
	  GPIO_D.Pull = GPIO_PULLUP;
	  GPIO_D.Alternate = GPIO_AF0_RTC_50Hz;
	  GPIO_D.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_D.Speed = GPIO_SPEED_LOW;
	  HAL_GPIO_Init(GPIOD,&GPIO_D);
	  HAL_TIM_PWM_Init();//
	  TIM_HandleTypeDef TIM_handle;
	  TIM_handle.Init.Prescaler = 0x0000;
	  TIM_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	  TIM_handle.Init.Period = 0x0FFF;
	  TIM_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  TIM_handle.Init.RepetitionCounter = 0.00;
	  TIM_OC_InitTypeDef TIM_OC_type_def;
	  TIM_OC_type_def.OCFastMode = TIM_OCMODE_TOGGLE (TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_1);
	  TIM_OC_type_def.Pulse = 0x0FFF;
	  TIM_OC_type_def.OCPolarity = TIM_OCPOLARITY_HIGH;
	  TIM_OC_type_def.OCNPolarity = TIM_OCNPOLARITY_LOW;
	  TIM_OC_type_def.OCFastMode = TIM_OCFAST_DISABLE;
	  TIM_OC_type_def.OCIdleState = TIM_OCIDLESTATE_SET (TIM_CR2_OIS1);
	  TIM_OC_type_def.OCNIdleState = TIM_OCNIDLESTATE_SET (TIM_CR2_OIS1N);
	  //TIM_TypeDef TIM_def_struct;
	  //TIM_def_struct

	  HAL_TIM_PWM_ConfigChannel(&TIM_handle,TIM_OC_type_def,TIM_CHANNEL_1);//
	  HAL_TIM_PWM_Start();//

}*/
