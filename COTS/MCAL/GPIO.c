/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 * 	File:				GPIO.c
 *  Module:				MCAL
 *  Description:  		GPIO Implementation file for the project
 *  
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
#include "GPIO.h" 

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
* \Syntax          : void DIO_Channel_Init(DIO_ChannelConfig ChannelConfig)
* \Description     : Initialize the GPIO Channel 
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : DIO_ChannelConfig ChannelConfig
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void DIO_Channel_Init(DIO_ChannelConfig ChannelConfig)
{
	DIO_Port PortX = ChannelConfig.Port;
	
	switch(PortX){
		case PORTA:
			//Activate the clock for PortA
			Set_Bit(SYSCTL_RCGCGPIO_R, ChannelConfig.Port);
			
			//Polling (short delay) between activating the port clock and setting up the channels
			//while( (SYSCTL_RCGCGPIO_R & (1<<ChannelConfig.Port)) == 0);
			
			//Select Channel commit state if allowed or not
			if(ChannelConfig.Commit_State == CHANGES_IS_ALLOWED){
				Set_Bit(GPIO_PORTA_CR_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTA_CR_R, ChannelConfig.Pin);
			}
			
			//Select Channel Analog mode if activated or not
			if(ChannelConfig.Analog_Mode == DIO_MODE_ACTIVATED){
				Set_Bit(GPIO_PORTA_AMSEL_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTA_AMSEL_R, ChannelConfig.Pin);
			}
			
			//Select PCTL state if cleared or not
			if(ChannelConfig.PCTL_State == CLEARED){
				Set_Bit(GPIO_PORTA_PCTL_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTA_PCTL_R, ChannelConfig.Pin);
			}
			
			//Select Direction if Input or Output
			if(ChannelConfig.Direction == OUTPUT){
				Set_Bit(GPIO_PORTA_DIR_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTA_DIR_R, ChannelConfig.Pin);
			}
			
			//Select Channel mode if normal or alternative
			if(ChannelConfig.Mode == NORMAL_MODE){
				Set_Bit(GPIO_PORTA_AFSEL_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTA_AFSEL_R, ChannelConfig.Pin);
			}
			
			//Select Channel DIO mode if activated or not
			if(ChannelConfig.DIO_Mode == DIO_MODE_ACTIVATED){
				Set_Bit(GPIO_PORTA_DEN_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTA_DEN_R, ChannelConfig.Pin);
			}
			
			//Select Channel DIO Internal Attach
			if(ChannelConfig.IntAttach == PULL_UP){
				Set_Bit(GPIO_PORTA_PUR_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTA_PUR_R, ChannelConfig.Pin);
			}
			break;
		
		case PORTB:
			//Activate the clock for PortB
			Set_Bit(SYSCTL_RCGCGPIO_R, ChannelConfig.Port);
			
			//Polling (short delay) between activating the port clock and setting up the channels
			while( (SYSCTL_RCGCGPIO_R & (1<<ChannelConfig.Port)) == 0);
			
			//Select Channel commit state if allowed or not
			if(ChannelConfig.Commit_State == CHANGES_IS_ALLOWED){
				Set_Bit(GPIO_PORTB_CR_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTB_CR_R, ChannelConfig.Pin);
			}
			
			//Select Channel Analog mode if activated or not
			if(ChannelConfig.Analog_Mode == DIO_MODE_ACTIVATED){
				Set_Bit(GPIO_PORTB_AMSEL_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTB_AMSEL_R, ChannelConfig.Pin);
			}
			
			//Select PCTL state if cleared or not
			if(ChannelConfig.PCTL_State == CLEARED){
				Set_Bit(GPIO_PORTB_PCTL_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTB_PCTL_R, ChannelConfig.Pin);
			}
			
			//Select Direction if Input or Output
			if(ChannelConfig.Direction == OUTPUT){
				Set_Bit(GPIO_PORTB_DIR_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTB_DIR_R, ChannelConfig.Pin);
			}
			
			//Select Channel mode if normal or alternative
			if(ChannelConfig.Mode == NORMAL_MODE){
				Set_Bit(GPIO_PORTB_AFSEL_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTB_AFSEL_R, ChannelConfig.Pin);
			}
			
			//Select Channel DIO mode if activated or not
			if(ChannelConfig.DIO_Mode == DIO_MODE_ACTIVATED){
				Set_Bit(GPIO_PORTB_DEN_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTB_DEN_R, ChannelConfig.Pin);
			}
			
			//Select Channel DIO Internal Attach
			if(ChannelConfig.IntAttach == PULL_UP){
				Set_Bit(GPIO_PORTB_PUR_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTB_PUR_R, ChannelConfig.Pin);
			}
			break;
	
		case PORTF:
			//Activate the clock for PORTF
			Set_Bit(SYSCTL_RCGCGPIO_R, ChannelConfig.Port);
			
			//Polling (short delay) between activating the port clock and setting up the channels
			//while( (SYSCTL_RCGCGPIO_R & (1<<ChannelConfig.Port)) == 0);

			////Unlock Commit Register for PORTF
			GPIO_PORTF_LOCK_R = 0x4C4F434B;
			
			//Select Channel commit state if allowed or not
			if(ChannelConfig.Commit_State == CHANGES_IS_ALLOWED){
				Set_Bit(GPIO_PORTF_CR_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTF_CR_R, ChannelConfig.Pin);
			}
			
			////Lock Commit Register for PORTF
			GPIO_PORTF_LOCK_R = 0;
			
			//Select Channel Analog mode if activated or not
			if(ChannelConfig.Analog_Mode == DIO_MODE_ACTIVATED){
				Set_Bit(GPIO_PORTF_AMSEL_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTF_AMSEL_R, ChannelConfig.Pin);
			}
			
			//Select PCTL state if cleared or not
			if(ChannelConfig.PCTL_State == CLEARED){
				Set_Bit(GPIO_PORTF_PCTL_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTF_PCTL_R, ChannelConfig.Pin);
			}
			
			//Select Direction if Input or Output
			if(ChannelConfig.Direction == OUTPUT){
				Set_Bit(GPIO_PORTF_DIR_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTF_DIR_R, ChannelConfig.Pin);
			}
			
			//Select Channel mode if normal or alternative
			if(ChannelConfig.Mode == NORMAL_MODE){
				Set_Bit(GPIO_PORTF_AFSEL_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTF_AFSEL_R, ChannelConfig.Pin);
			}
			
			//Select Channel DIO mode if activated or not
			if(ChannelConfig.DIO_Mode == DIO_MODE_ACTIVATED){
				Set_Bit(GPIO_PORTF_DEN_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTF_DEN_R, ChannelConfig.Pin);
			}
			
			//Select Channel DIO Internal Attach
			if(ChannelConfig.IntAttach == PULL_UP){
				Set_Bit(GPIO_PORTF_PUR_R, ChannelConfig.Pin);
			}
			else{
				Clear_Bit(GPIO_PORTF_PUR_R, ChannelConfig.Pin);
			}
			break;
	}
}

/******************************************************************************
* \Syntax          : void DIO_Write_Channel(DIO_ChannelConfig ChannelConfig)
* \Description     : Write the GPIO Channel 
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : DIO_ChannelConfig ChannelConfig
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void DIO_Write_Channel(DIO_ChannelConfig ChannelConfig)
{
	DIO_Port PortX = ChannelConfig.Port;
	
	switch(PortX){
		case PORTA:
			if (ChannelConfig.Level == HIGH){
				//Set Bitx in PortA to one
				Set_Bit(GPIO_PORTA_DATA_R, ChannelConfig.Pin);
			}
			else if(ChannelConfig.Level == LOW){
				//Clear Bitx ib PortA to zero
				Clear_Bit(GPIO_PORTA_DATA_R, ChannelConfig.Pin);
			}
			else{
				//do nothing
			}
			break;
		case PORTB:
			if (ChannelConfig.Level == HIGH){
				//Set Bitx in PortB to one
				Set_Bit(GPIO_PORTB_DATA_R, ChannelConfig.Pin);
			}
			else if(ChannelConfig.Level == LOW){
				//Clear Bitx in PortB to zero
				Clear_Bit(GPIO_PORTB_DATA_R, ChannelConfig.Pin);
			}
			else{
				//do nothing
			}
			break;
		case PORTF:
			if (ChannelConfig.Level == HIGH){
				//Set Bitx in PORTF to one
				Set_Bit(GPIO_PORTF_DATA_R, ChannelConfig.Pin);
			}
			else if(ChannelConfig.Level == LOW){
				//Clear Bitx in PORTF to zero
				Clear_Bit(GPIO_PORTF_DATA_R, ChannelConfig.Pin);
			}
			else{
				//do nothing
			}
			break;
	}
}

/******************************************************************************
* \Syntax          : DIO_ChannelLevel DIO_Read_Channel(DIO_ChannelConfig ChannelConfig)
* \Description     : Read the GPIO Channel
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : DIO_ChannelConfig ChannelConfig
* \Parameters (out): DIO_ChannelLevel
* \Return value:   : return The Channel level, High or Low
*******************************************************************************/
DIO_ChannelLevel DIO_Read_Channel(DIO_ChannelConfig ChannelConfig)
{
	DIO_Port PortX = ChannelConfig.Port;
	DIO_ChannelLevel ChannelLevel;
	
	switch(PortX){
		case PORTA:
			//Read Bitx in PortA
			ChannelLevel = Read_Bit(GPIO_PORTA_DATA_R, ChannelConfig.Pin);
			break;
		case PORTB:
			//Read Bitx in PortB
			ChannelLevel = Read_Bit(GPIO_PORTB_DATA_R, ChannelConfig.Pin);
			break;
		case PORTF:
			//Read Bitx in PORTF
			ChannelLevel = Read_Bit(GPIO_PORTF_DATA_R, ChannelConfig.Pin);
			break;
	}
	
	return ChannelLevel;
}

/******************************************************************************
* \Syntax          : void DIO_Toggle_Channel(DIO_ChannelConfig ChannelConfig)
* \Description     : Toggle the GPIO Channel
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : DIO_ChannelConfig ChannelConfig
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void DIO_Toggle_Channel(DIO_ChannelConfig ChannelConfig)
{
	DIO_Port PortX = ChannelConfig.Port;
	
	switch(PortX){
		case PORTA:
			//Toggle Bitx in PortA
			Toggle_Bit(GPIO_PORTA_DATA_R, ChannelConfig.Pin);
			break;
		case PORTB:
			//Toggle Bitx in PortB
			Toggle_Bit(GPIO_PORTB_DATA_R, ChannelConfig.Pin);
			break;
		case PORTF:
			//Toggle Bitx in PORTF
			Toggle_Bit(GPIO_PORTF_DATA_R, ChannelConfig.Pin);
			break;
	}
}

/**********************************************************************************************************************
 *  END OF FILE:	GPIO.c
 *********************************************************************************************************************/