/*******************************************************************************
* File Name: LedConnectedStatus.h  
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

#if !defined(CY_PINS_LedConnectedStatus_H) /* Pins LedConnectedStatus_H */
#define CY_PINS_LedConnectedStatus_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LedConnectedStatus_aliases.h"


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
} LedConnectedStatus_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   LedConnectedStatus_Read(void);
void    LedConnectedStatus_Write(uint8 value);
uint8   LedConnectedStatus_ReadDataReg(void);
#if defined(LedConnectedStatus__PC) || (CY_PSOC4_4200L) 
    void    LedConnectedStatus_SetDriveMode(uint8 mode);
#endif
void    LedConnectedStatus_SetInterruptMode(uint16 position, uint16 mode);
uint8   LedConnectedStatus_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void LedConnectedStatus_Sleep(void); 
void LedConnectedStatus_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(LedConnectedStatus__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define LedConnectedStatus_DRIVE_MODE_BITS        (3)
    #define LedConnectedStatus_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LedConnectedStatus_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the LedConnectedStatus_SetDriveMode() function.
         *  @{
         */
        #define LedConnectedStatus_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define LedConnectedStatus_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define LedConnectedStatus_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define LedConnectedStatus_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define LedConnectedStatus_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define LedConnectedStatus_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define LedConnectedStatus_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define LedConnectedStatus_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define LedConnectedStatus_MASK               LedConnectedStatus__MASK
#define LedConnectedStatus_SHIFT              LedConnectedStatus__SHIFT
#define LedConnectedStatus_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LedConnectedStatus_SetInterruptMode() function.
     *  @{
     */
        #define LedConnectedStatus_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define LedConnectedStatus_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define LedConnectedStatus_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define LedConnectedStatus_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(LedConnectedStatus__SIO)
    #define LedConnectedStatus_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(LedConnectedStatus__PC) && (CY_PSOC4_4200L)
    #define LedConnectedStatus_USBIO_ENABLE               ((uint32)0x80000000u)
    #define LedConnectedStatus_USBIO_DISABLE              ((uint32)(~LedConnectedStatus_USBIO_ENABLE))
    #define LedConnectedStatus_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define LedConnectedStatus_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define LedConnectedStatus_USBIO_ENTER_SLEEP          ((uint32)((1u << LedConnectedStatus_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << LedConnectedStatus_USBIO_SUSPEND_DEL_SHIFT)))
    #define LedConnectedStatus_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << LedConnectedStatus_USBIO_SUSPEND_SHIFT)))
    #define LedConnectedStatus_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << LedConnectedStatus_USBIO_SUSPEND_DEL_SHIFT)))
    #define LedConnectedStatus_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(LedConnectedStatus__PC)
    /* Port Configuration */
    #define LedConnectedStatus_PC                 (* (reg32 *) LedConnectedStatus__PC)
#endif
/* Pin State */
#define LedConnectedStatus_PS                     (* (reg32 *) LedConnectedStatus__PS)
/* Data Register */
#define LedConnectedStatus_DR                     (* (reg32 *) LedConnectedStatus__DR)
/* Input Buffer Disable Override */
#define LedConnectedStatus_INP_DIS                (* (reg32 *) LedConnectedStatus__PC2)

/* Interrupt configuration Registers */
#define LedConnectedStatus_INTCFG                 (* (reg32 *) LedConnectedStatus__INTCFG)
#define LedConnectedStatus_INTSTAT                (* (reg32 *) LedConnectedStatus__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define LedConnectedStatus_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(LedConnectedStatus__SIO)
    #define LedConnectedStatus_SIO_REG            (* (reg32 *) LedConnectedStatus__SIO)
#endif /* (LedConnectedStatus__SIO_CFG) */

/* USBIO registers */
#if !defined(LedConnectedStatus__PC) && (CY_PSOC4_4200L)
    #define LedConnectedStatus_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define LedConnectedStatus_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define LedConnectedStatus_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define LedConnectedStatus_DRIVE_MODE_SHIFT       (0x00u)
#define LedConnectedStatus_DRIVE_MODE_MASK        (0x07u << LedConnectedStatus_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins LedConnectedStatus_H */


/* [] END OF FILE */
