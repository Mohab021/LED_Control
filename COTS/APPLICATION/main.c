/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 * 	File:				main.c
 *  Module:				APPLICATION
 *  Description:  		main fucntion that contains the application for the project
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
#include "LED.h"
#include "Button.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

volatile uint8 TIME_ON = 0;
volatile uint8 TIME_OFF = 0;
uint8 counter1 = 0;
uint8 counter2 = 0;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

Timer_Flag TIMER1A_ISR();
void One_Second_Delay(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

int main()
{ 
	//Configure DIO Channel PORTF PIN1 for LED
	DIO_ChannelConfig LED;

	LED.Port = PORTF;
	LED.Pin = PIN1;
	LED.Direction = OUTPUT;
	LED.Level = LOW;
	LED.Mode = NORMAL_MODE;
	LED.Analog_Mode = ANALOG_MODE_DEACTIVATED;
	LED.DIO_Mode = DIO_MODE_ACTIVATED;
	LED.Commit_State = CHANGES_IS_ALLOWED;
	LED.PCTL_State = CLEARED;
	
	//Init PIN1 of PORTF as LED
	LED_Init(LED);
	
	//Configure DIO Channel PORTF PIN0 for ON_Button
	DIO_ChannelConfig ON_Button;

	ON_Button.Port = PORTF;
	ON_Button.Pin = PIN0;
	ON_Button.Direction = INPUT;
	ON_Button.Mode = NORMAL_MODE;
	ON_Button.Analog_Mode = ANALOG_MODE_DEACTIVATED;
	ON_Button.DIO_Mode = DIO_MODE_ACTIVATED;
	ON_Button.Commit_State = CHANGES_IS_ALLOWED;
	ON_Button.PCTL_State = CLEARED;
	ON_Button.IntAttach = PULL_UP;
	
	//Init PIN0 of PORTF as ON_Button
	Button_Init(ON_Button);
	

	//Configure DIO Channel PORTF PIN4 for OFF_Button
	DIO_ChannelConfig OFF_Button;

	OFF_Button.Port = PORTF;
	OFF_Button.Pin = PIN4;
	OFF_Button.Direction = INPUT;
	OFF_Button.Mode = NORMAL_MODE;
	OFF_Button.Analog_Mode = ANALOG_MODE_DEACTIVATED;
	OFF_Button.DIO_Mode = DIO_MODE_ACTIVATED;
	OFF_Button.Commit_State = CHANGES_IS_ALLOWED;
	OFF_Button.PCTL_State = CLEARED;
	LED.IntAttach = PULL_UP;
	
	//Init PIN4 of PORTF as OFF_Button
	Button_Init(OFF_Button);
	
	//Init PIN0 and PIN4 of PORTF as External Interrupts (falling edge trigger interrupt)
	Ext_Interrupt_GPIOF_Init();
	
	//A pointer to ISR function in APP layer
	Timer_Flag (*ptr_ISR)() = &TIMER1A_ISR;

	while(1){
		for(counter1=0 ; counter1<TIME_ON ; counter1++){
			LED.Level = HIGH;
			LED_Change_Status(LED);
			//GPTM_Delay_1sec(ptr_ISR);
			One_Second_Delay(); //using SysTick timer
		}
		
		for(counter2=0 ; counter2<TIME_OFF ; counter2++){
			LED.Level = LOW;
			LED_Change_Status(LED);
			//GPTM_Delay_1sec(ptr_ISR);		
			One_Second_Delay(); //using SysTick timer
		}
	}
}

Timer_Flag TIMER1A_ISR()
{
	if (TIMER1_MIS_R & 0x01)
	{
		//Clear Timer1A timeout flag bit
		TIMER1_ICR_R = CLEARED;
		
		return TIMER_FINISHED;
	}
	return TIMER_NOT_FINISHED;
}

GPIOF_Handler()
{	
	if(GPIO_PORTF_MIS_R & 0x01) //Check if interrupt is caused by PIN0 of PORTB //ON_Button
    {   
		TIME_ON++;
		//Clear the interrupt flag bit
		GPIO_PORTF_ICR_R |= 0x01;
    } 
    else if(GPIO_PORTF_MIS_R & 0x10) //Check if interrupt is caused by PIN4 of PORTB //OFF_Button
    {   
		TIME_OFF++;
		//Clear the interrupt flag bit
		GPIO_PORTF_ICR_R |= 0x10;
    }
	else
	{
		//do nothing
	}
}

void One_Second_Delay(void)
{
	//Disable SysTick during init
	NVIC_ST_CTRL_R = 0;
    
	//Reload required value for 1 second
	NVIC_ST_RELOAD_R = 15999999;
	
	//Enable SysTick with core clock
  NVIC_ST_CTRL_R |= 0x5;
	
	//Monitoring 16-bit
  while( (NVIC_ST_CTRL_R & (1<<16) ) == 0);
	
	//Disable SysTick
  NVIC_ST_CTRL_R = 0;
}

/**********************************************************************************************************************
 *  END OF FILE:	main.c
 *********************************************************************************************************************/