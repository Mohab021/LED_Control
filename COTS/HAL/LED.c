/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 * 	File:				LED.c
 *  Module:				HAL
 *  Description:  		LED implementation file for the project
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
#include "LED.h"

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
* \Syntax          : void LED_Init(DIO_ChannelConfig ChannelConfig)
* \Description     : Initialize LED Channel 
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : DIO_ChannelConfig ChannelConfig
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void LED_Init(DIO_ChannelConfig ChannelConfig)
{
	//Init LED Channel from DIO_Channel_Init in GPIO file (MCAL)
	DIO_Channel_Init(ChannelConfig);
}

/******************************************************************************
* \Syntax          : void LED_Change_Status(DIO_ChannelConfig ChannelConfig)
* \Description     : Change status of LED Channel 
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : DIO_ChannelConfig ChannelConfig
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void LED_Change_Status(DIO_ChannelConfig ChannelConfig)
{
	//Change Status of LED Channel from DIO_Write_Channel in GPIO file (MCAL)
	DIO_Write_Channel(ChannelConfig);
}

/**********************************************************************************************************************
 *  END OF FILE:	LED.c
 *********************************************************************************************************************/