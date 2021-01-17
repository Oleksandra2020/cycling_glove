/*******************************************************************************
* File Name: Down.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Down_H) /* Pins Down_H */
#define CY_PINS_Down_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Down_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} Down_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Down_Read(void);
void    Down_Write(uint8 value);
uint8   Down_ReadDataReg(void);
#if defined(Down__PC) || (CY_PSOC4_4200L) 
    void    Down_SetDriveMode(uint8 mode);
#endif
void    Down_SetInterruptMode(uint16 position, uint16 mode);
uint8   Down_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Down_Sleep(void); 
void Down_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Down__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Down_DRIVE_MODE_BITS        (3)
    #define Down_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Down_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Down_SetDriveMode() function.
         *  @{
         */
        #define Down_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Down_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Down_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Down_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Down_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Down_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Down_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Down_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Down_MASK               Down__MASK
#define Down_SHIFT              Down__SHIFT
#define Down_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Down_SetInterruptMode() function.
     *  @{
     */
        #define Down_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Down_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Down_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Down_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Down__SIO)
    #define Down_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Down__PC) && (CY_PSOC4_4200L)
    #define Down_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Down_USBIO_DISABLE              ((uint32)(~Down_USBIO_ENABLE))
    #define Down_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Down_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Down_USBIO_ENTER_SLEEP          ((uint32)((1u << Down_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Down_USBIO_SUSPEND_DEL_SHIFT)))
    #define Down_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Down_USBIO_SUSPEND_SHIFT)))
    #define Down_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Down_USBIO_SUSPEND_DEL_SHIFT)))
    #define Down_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Down__PC)
    /* Port Configuration */
    #define Down_PC                 (* (reg32 *) Down__PC)
#endif
/* Pin State */
#define Down_PS                     (* (reg32 *) Down__PS)
/* Data Register */
#define Down_DR                     (* (reg32 *) Down__DR)
/* Input Buffer Disable Override */
#define Down_INP_DIS                (* (reg32 *) Down__PC2)

/* Interrupt configuration Registers */
#define Down_INTCFG                 (* (reg32 *) Down__INTCFG)
#define Down_INTSTAT                (* (reg32 *) Down__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Down_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Down__SIO)
    #define Down_SIO_REG            (* (reg32 *) Down__SIO)
#endif /* (Down__SIO_CFG) */

/* USBIO registers */
#if !defined(Down__PC) && (CY_PSOC4_4200L)
    #define Down_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Down_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Down_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Down_DRIVE_MODE_SHIFT       (0x00u)
#define Down_DRIVE_MODE_MASK        (0x07u << Down_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Down_H */


/* [] END OF FILE */
