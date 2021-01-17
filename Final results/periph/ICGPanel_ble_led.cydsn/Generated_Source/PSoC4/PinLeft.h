/*******************************************************************************
* File Name: PinLeft.h  
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

#if !defined(CY_PINS_PinLeft_H) /* Pins PinLeft_H */
#define CY_PINS_PinLeft_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PinLeft_aliases.h"


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
} PinLeft_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PinLeft_Read(void);
void    PinLeft_Write(uint8 value);
uint8   PinLeft_ReadDataReg(void);
#if defined(PinLeft__PC) || (CY_PSOC4_4200L) 
    void    PinLeft_SetDriveMode(uint8 mode);
#endif
void    PinLeft_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinLeft_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PinLeft_Sleep(void); 
void PinLeft_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PinLeft__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PinLeft_DRIVE_MODE_BITS        (3)
    #define PinLeft_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PinLeft_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PinLeft_SetDriveMode() function.
         *  @{
         */
        #define PinLeft_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PinLeft_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PinLeft_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PinLeft_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PinLeft_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PinLeft_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PinLeft_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PinLeft_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PinLeft_MASK               PinLeft__MASK
#define PinLeft_SHIFT              PinLeft__SHIFT
#define PinLeft_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinLeft_SetInterruptMode() function.
     *  @{
     */
        #define PinLeft_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PinLeft_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PinLeft_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PinLeft_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PinLeft__SIO)
    #define PinLeft_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PinLeft__PC) && (CY_PSOC4_4200L)
    #define PinLeft_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PinLeft_USBIO_DISABLE              ((uint32)(~PinLeft_USBIO_ENABLE))
    #define PinLeft_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PinLeft_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PinLeft_USBIO_ENTER_SLEEP          ((uint32)((1u << PinLeft_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PinLeft_USBIO_SUSPEND_DEL_SHIFT)))
    #define PinLeft_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PinLeft_USBIO_SUSPEND_SHIFT)))
    #define PinLeft_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PinLeft_USBIO_SUSPEND_DEL_SHIFT)))
    #define PinLeft_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PinLeft__PC)
    /* Port Configuration */
    #define PinLeft_PC                 (* (reg32 *) PinLeft__PC)
#endif
/* Pin State */
#define PinLeft_PS                     (* (reg32 *) PinLeft__PS)
/* Data Register */
#define PinLeft_DR                     (* (reg32 *) PinLeft__DR)
/* Input Buffer Disable Override */
#define PinLeft_INP_DIS                (* (reg32 *) PinLeft__PC2)

/* Interrupt configuration Registers */
#define PinLeft_INTCFG                 (* (reg32 *) PinLeft__INTCFG)
#define PinLeft_INTSTAT                (* (reg32 *) PinLeft__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PinLeft_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PinLeft__SIO)
    #define PinLeft_SIO_REG            (* (reg32 *) PinLeft__SIO)
#endif /* (PinLeft__SIO_CFG) */

/* USBIO registers */
#if !defined(PinLeft__PC) && (CY_PSOC4_4200L)
    #define PinLeft_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PinLeft_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PinLeft_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PinLeft_DRIVE_MODE_SHIFT       (0x00u)
#define PinLeft_DRIVE_MODE_MASK        (0x07u << PinLeft_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PinLeft_H */


/* [] END OF FILE */
