/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 * 	File:				Button.c
 *  Module:				HAL
 *  Description:  		Button implementation file for the project
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
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
* \Syntax          : void Button_Init(DIO_ChannelConfig ChannelConfig)
* \Description     : Initialize Button Channel 
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : DIO_ChannelConfig ChannelConfig
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Button_Init(DIO_ChannelConfig ChannelConfig)
{
	//Init Button Channel from DIO_Channel_Init in GPIO file (MCAL)
	DIO_Channel_Init(ChannelConfig);
}

/**********************************************************************************************************************
 *  END OF FILE:	Button.c
 *********************************************************************************************************************/