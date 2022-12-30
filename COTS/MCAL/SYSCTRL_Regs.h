/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 * 	File:				SYSCTRL_Regs.h
 *  Module:				MCAL
 *  Description:  		System Control Register definitions file for the project
 *  
 *********************************************************************************************************************/

#ifndef SYSCTRL_REGS_H
#define SYSCTRL_REGS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

// System Control registers (SYSCTL)
#define SYSCTL_RCGC0_R          (*((volatile unsigned long *)0x400FE100))
#define SYSCTL_RCGC1_R          (*((volatile unsigned long *)0x400FE104))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_RCGCWD_R         (*((volatile unsigned long *)0x400FE600))
#define SYSCTL_RCGCTIMER_R      (*((volatile unsigned long *)0x400FE604))
#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))
#define SYSCTL_RCGCDMA_R        (*((volatile unsigned long *)0x400FE60C))
#define SYSCTL_RCGCHIB_R        (*((volatile unsigned long *)0x400FE614))
#define SYSCTL_RCGCUART_R       (*((volatile unsigned long *)0x400FE618))
#define SYSCTL_RCGCSSI_R        (*((volatile unsigned long *)0x400FE61C))
#define SYSCTL_RCGCI2C_R        (*((volatile unsigned long *)0x400FE620))
#define SYSCTL_RCGCUSB_R        (*((volatile unsigned long *)0x400FE628))
#define SYSCTL_RCGCCAN_R        (*((volatile unsigned long *)0x400FE634))
#define SYSCTL_RCGCADC_R        (*((volatile unsigned long *)0x400FE638))
#define SYSCTL_RCGCACMP_R       (*((volatile unsigned long *)0x400FE63C))
#define SYSCTL_RCGCPWM_R        (*((volatile unsigned long *)0x400FE640))
#define SYSCTL_RCGCQEI_R        (*((volatile unsigned long *)0x400FE644))
#define SYSCTL_RCGCEEPROM_R     (*((volatile unsigned long *)0x400FE658))
#define SYSCTL_RCGCWTIMER_R     (*((volatile unsigned long *)0x400FE65C))

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

#endif  /* SYSCTRL_REGS_H */

/**********************************************************************************************************************
 *  END OF FILE:	SYSCTRL_Regs.h
 *********************************************************************************************************************/