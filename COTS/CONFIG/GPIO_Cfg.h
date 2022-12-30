/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 * 	File:				GPIO_Cfg.h
 *  Module:				CONFIG
 *  Description:  		GPIO Configuration file for the project
 *  
 *********************************************************************************************************************/

#ifndef GPIO_CFG_H
#define GPIO_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

//PORTA to PORTF
typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF
} DIO_Port;

//PIN0 TO PIN7
typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7 
} DIO_Channel;

//GPIO_PORTX_DIR_R
typedef enum
{
	INPUT,
	OUTPUT 
} Channel_Direction;

//PIN LEVEL
typedef  enum
{
	LOW,
	HIGH
} DIO_ChannelLevel;

//GPIO_PORTX_AFSEL_R
typedef enum
{
	ALTERNATIVE_MODE,
	NORMAL_MODE
} Channel_Mode;

//GPIO_PORTX_DEN_R
typedef enum
{
	DIO_MODE_DEACTIVATED,
	DIO_MODE_ACTIVATED
} Channel_Analog_Mode;

//GPIO_PORTX_AMSEL_R
typedef enum
{
	ANALOG_MODE_DEACTIVATED,
	ANALOG_MODE_ACTIVATED
} Channel_DIO_Mode;

//GPIO_PORTX_CR_R
typedef enum
{
	CHANGES_IS_NOT_ALLOWED,
	CHANGES_IS_ALLOWED
} Channel_Commit_State;

//GPIO_PORTX_PCTL_R
typedef enum
{
	NOT_CLEARED,
	CLEARED
} Channel_PCTL_State;

typedef enum
{
	PULL_DOWN,
	PULL_UP
} Channel_IntAttach;

//PIN Configuration
typedef struct 
{
	DIO_Port Port;
	DIO_Channel Pin;
	Channel_Direction Direction;
	DIO_ChannelLevel Level;
	Channel_Mode Mode;
	Channel_Analog_Mode Analog_Mode;
	Channel_DIO_Mode DIO_Mode;
	Channel_Commit_State Commit_State;
	Channel_PCTL_State PCTL_State;
	Channel_IntAttach IntAttach;
} DIO_ChannelConfig;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* GPIO_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE:	GPIO_Cfg.h
 *********************************************************************************************************************/