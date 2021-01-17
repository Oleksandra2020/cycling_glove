/*******************************************************************************
* File Name: PinRight.h  
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

#if !defined(CY_PINS_PinRight_H) /* Pins PinRight_H */
#define CY_PINS_PinRight_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PinRight_aliases.h"


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
} PinRight_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PinRight_Read(void);
void    PinRight_Write(uint8 value);
uint8   PinRight_ReadDataReg(void);
#if defined(PinRight__PC) || (CY_PSOC4_4200L) 
    void    PinRight_SetDriveMode(uint8 mode);
#endif
void    PinRight_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinRight_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PinRight_Sleep(void); 
void PinRight_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PinRight__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PinRight_DRIVE_MODE_BITS        (3)
    #define PinRight_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PinRight_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PinRight_SetDriveMode() function.
         *  @{
         */
        #define PinRight_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PinRight_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PinRight_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PinRight_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PinRight_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PinRight_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PinRight_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PinRight_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PinRight_MASK               PinRight__MASK
#define PinRight_SHIFT              PinRight__SHIFT
#define PinRight_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinRight_SetInterruptMode() function.
     *  @{
     */
        #define PinRight_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PinRight_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PinRight_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PinRight_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PinRight__SIO)
    #define PinRight_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PinRight__PC) && (CY_PSOC4_4200L)
    #define PinRight_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PinRight_USBIO_DISABLE              ((uint32)(~PinRight_USBIO_ENABLE))
    #define PinRight_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PinRight_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PinRight_USBIO_ENTER_SLEEP          ((uint32)((1u << PinRight_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PinRight_USBIO_SUSPEND_DEL_SHIFT)))
    #define PinRight_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PinRight_USBIO_SUSPEND_SHIFT)))
    #define PinRight_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PinRight_USBIO_SUSPEND_DEL_SHIFT)))
    #define PinRight_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PinRight__PC)
    /* Port Configuration */
    #define PinRight_PC                 (* (reg32 *) PinRight__PC)
#endif
/* Pin State */
#define PinRight_PS                     (* (reg32 *) PinRight__PS)
/* Data Register */
#define PinRight_DR                     (* (reg32 *) PinRight__DR)
/* Input Buffer Disable Override */
#define PinRight_INP_DIS                (* (reg32 *) PinRight__PC2)

/* Interrupt configuration Registers */
#define PinRight_INTCFG                 (* (reg32 *) PinRight__INTCFG)
#define PinRight_INTSTAT                (* (reg32 *) PinRight__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PinRight_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PinRight__SIO)
    #define PinRight_SIO_REG            (* (reg32 *) PinRight__SIO)
#endif /* (PinRight__SIO_CFG) */

/* USBIO registers */
#if !defined(PinRight__PC) && (CY_PSOC4_4200L)
    #define PinRight_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PinRight_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PinRight_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PinRight_DRIVE_MODE_SHIFT       (0x00u)
#define PinRight_DRIVE_MODE_MASK        (0x07u << PinRight_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PinRight_H */


/* [] END OF FILE */
