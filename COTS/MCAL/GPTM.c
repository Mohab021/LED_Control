/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 * 	File:				GPTM.c
 *  Module:				MCAL
 *  Description:  		GPTM Implementation file for the project
 *  
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
#include "GPTM.h" 

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void GPTM_Delay_1sec( Timer_Flag (*ptr_ISR)() )
* \Description     : Delay for 1 second using Interrupt
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Timer_Flag (*ptr_ISR)()
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void GPTM_Delay_1sec( Timer_Flag (*ptr_ISR)() )
{
	//Using Timer1A for delaying 1 second
	
	//Activating Timer1A by enabling its clock
	SYSCTL_RCGCTIMER_R |= (1<<1);
	
	//Disable Timer1A while initializing
	TIMER1_CTL_R = Disabled;
	
	//Select 16-bit mode for Timer1A as configuration
	TIMER1_CFG_R = 0x04;
	
	//Select Periodic Down Counter Mode for Timer1A
	TIMER1_TAMR_R = 0X02;
	
	//Select Prescalar configuration for Timer1A
	TIMER1_TAPR_R = 250-1;
	
	//Select the starting count down value for Timer1A
	TIMER1_TAILR_R = 64000-1;
	
	//Clear Timer1A timeout flag bit
	TIMER1_ICR_R = T_CLEARED;
	
	//Enable Timeout interrupt mask of Timer1A
	TIMER1_IMR_R |= Enabled;
	
	//Enable Timer1A
	TIMER1_CTL_R |= Enabled;
	
	//Enable IRQ21 in NVIC
	NVIC_EN1_R |= 1<<21;
	
	//Calling the Callback function of ISR and wait until interrupt happens
	while( (*ptr_ISR)() != TIMER_FINISHED );
}

/**********************************************************************************************************************
 *  END OF FILE:	GPTM.c
 *********************************************************************************************************************/