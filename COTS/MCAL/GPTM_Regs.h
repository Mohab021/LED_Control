/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 * 	File:				GPTM_Regs.h
 *  Module:				MCAL
 *  Description:  		GPTM Register definitions file for the project
 *  
 *********************************************************************************************************************/

#ifndef GPTM_REGS_H
#define GPTM_REGS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

// GPTM registers (TIMER0)
#define TIMER0_CFG_R            (*((volatile unsigned long *)0x40030000))
#define TIMER0_TAMR_R           (*((volatile unsigned long *)0x40030004))
#define TIMER0_TBMR_R           (*((volatile unsigned long *)0x40030008))
#define TIMER0_CTL_R            (*((volatile unsigned long *)0x4003000C))
#define TIMER0_SYNC_R           (*((volatile unsigned long *)0x40030010))
#define TIMER0_IMR_R            (*((volatile unsigned long *)0x40030018))
#define TIMER0_RIS_R            (*((volatile unsigned long *)0x4003001C))
#define TIMER0_MIS_R            (*((volatile unsigned long *)0x40030020))
#define TIMER0_ICR_R            (*((volatile unsigned long *)0x40030024))
#define TIMER0_TAILR_R          (*((volatile unsigned long *)0x40030028))
#define TIMER0_TBILR_R          (*((volatile unsigned long *)0x4003002C))
#define TIMER0_TAMATCHR_R       (*((volatile unsigned long *)0x40030030))
#define TIMER0_TBMATCHR_R       (*((volatile unsigned long *)0x40030034))
#define TIMER0_TAPR_R           (*((volatile unsigned long *)0x40030038))
#define TIMER0_TBPR_R           (*((volatile unsigned long *)0x4003003C))
#define TIMER0_TAPMR_R          (*((volatile unsigned long *)0x40030040))
#define TIMER0_TBPMR_R          (*((volatile unsigned long *)0x40030044))
#define TIMER0_TAR_R            (*((volatile unsigned long *)0x40030048))
#define TIMER0_TBR_R            (*((volatile unsigned long *)0x4003004C))
#define TIMER0_TAV_R            (*((volatile unsigned long *)0x40030050))
#define TIMER0_TBV_R            (*((volatile unsigned long *)0x40030054))
#define TIMER0_RTCPD_R          (*((volatile unsigned long *)0x40030058))
#define TIMER0_TAPS_R           (*((volatile unsigned long *)0x4003005C))
#define TIMER0_TBPS_R           (*((volatile unsigned long *)0x40030060))
#define TIMER0_TAPV_R           (*((volatile unsigned long *)0x40030064))
#define TIMER0_TBPV_R           (*((volatile unsigned long *)0x40030068))
#define TIMER0_PP_R             (*((volatile unsigned long *)0x40030FC0))

// Timer registers (TIMER1)
#define TIMER1_CFG_R            (*((volatile unsigned long *)0x40031000))
#define TIMER1_TAMR_R           (*((volatile unsigned long *)0x40031004))
#define TIMER1_TBMR_R           (*((volatile unsigned long *)0x40031008))
#define TIMER1_CTL_R            (*((volatile unsigned long *)0x4003100C))
#define TIMER1_SYNC_R           (*((volatile unsigned long *)0x40031010))
#define TIMER1_IMR_R            (*((volatile unsigned long *)0x40031018))
#define TIMER1_RIS_R            (*((volatile unsigned long *)0x4003101C))
#define TIMER1_MIS_R            (*((volatile unsigned long *)0x40031020))
#define TIMER1_ICR_R            (*((volatile unsigned long *)0x40031024))
#define TIMER1_TAILR_R          (*((volatile unsigned long *)0x40031028))
#define TIMER1_TBILR_R          (*((volatile unsigned long *)0x4003102C))
#define TIMER1_TAMATCHR_R       (*((volatile unsigned long *)0x40031030))
#define TIMER1_TBMATCHR_R       (*((volatile unsigned long *)0x40031034))
#define TIMER1_TAPR_R           (*((volatile unsigned long *)0x40031038))
#define TIMER1_TBPR_R           (*((volatile unsigned long *)0x4003103C))
#define TIMER1_TAPMR_R          (*((volatile unsigned long *)0x40031040))
#define TIMER1_TBPMR_R          (*((volatile unsigned long *)0x40031044))
#define TIMER1_TAR_R            (*((volatile unsigned long *)0x40031048))
#define TIMER1_TBR_R            (*((volatile unsigned long *)0x4003104C))
#define TIMER1_TAV_R            (*((volatile unsigned long *)0x40031050))
#define TIMER1_TBV_R            (*((volatile unsigned long *)0x40031054))
#define TIMER1_RTCPD_R          (*((volatile unsigned long *)0x40031058))
#define TIMER1_TAPS_R           (*((volatile unsigned long *)0x4003105C))
#define TIMER1_TBPS_R           (*((volatile unsigned long *)0x40031060))
#define TIMER1_TAPV_R           (*((volatile unsigned long *)0x40031064))
#define TIMER1_TBPV_R           (*((volatile unsigned long *)0x40031068))
#define TIMER1_PP_R             (*((volatile unsigned long *)0x40031FC0))

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

#endif  /* GPTM_REGS_H */

/**********************************************************************************************************************
 *  END OF FILE:	GPTM_Regs.h
 *********************************************************************************************************************/