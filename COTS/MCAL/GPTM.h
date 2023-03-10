/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 * 	File:				GPTM.h
 *  Module:				MCAL
 *  Description:  		GPTM Header file for the project
 *  
 *********************************************************************************************************************/

#ifndef GPTM_H
#define GPTM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"
#include "Common_Macros.h"
#include "SYSCTRL_Regs.h"
#include "GPIO_Regs.h"
#include "GPTM_Regs.h"
#include "NVIC_Regs.h"
#include "GPIO_Cfg.h"
#include "GPTM_Cfg.h"
#include "NVIC_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void GPTM_Delay_1sec( Timer_Flag (*ptr_ISR)() );

#endif  /* GPTM_H */

/**********************************************************************************************************************
 *  END OF FILE:	GPTM.h
 *********************************************************************************************************************/