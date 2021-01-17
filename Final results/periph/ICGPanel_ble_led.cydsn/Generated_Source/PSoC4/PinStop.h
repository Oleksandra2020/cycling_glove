/*******************************************************************************
* File Name: PinStop.h  
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

#if !defined(CY_PINS_PinStop_H) /* Pins PinStop_H */
#define CY_PINS_PinStop_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PinStop_aliases.h"


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
} PinStop_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PinStop_Read(void);
void    PinStop_Write(uint8 value);
uint8   PinStop_ReadDataReg(void);
#if defined(PinStop__PC) || (CY_PSOC4_4200L) 
    void    PinStop_SetDriveMode(uint8 mode);
#endif
void    PinStop_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinStop_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PinStop_Sleep(void); 
void PinStop_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PinStop__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PinStop_DRIVE_MODE_BITS        (3)
    #define PinStop_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PinStop_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PinStop_SetDriveMode() function.
         *  @{
         */
        #define PinStop_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PinStop_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PinStop_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PinStop_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PinStop_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PinStop_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PinStop_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PinStop_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PinStop_MASK               PinStop__MASK
#define PinStop_SHIFT              PinStop__SHIFT
#define PinStop_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinStop_SetInterruptMode() function.
     *  @{
     */
        #define PinStop_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PinStop_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PinStop_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PinStop_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PinStop__SIO)
    #define PinStop_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PinStop__PC) && (CY_PSOC4_4200L)
    #define PinStop_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PinStop_USBIO_DISABLE              ((uint32)(~PinStop_USBIO_ENABLE))
    #define PinStop_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PinStop_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PinStop_USBIO_ENTER_SLEEP          ((uint32)((1u << PinStop_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PinStop_USBIO_SUSPEND_DEL_SHIFT)))
    #define PinStop_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PinStop_USBIO_SUSPEND_SHIFT)))
    #define PinStop_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PinStop_USBIO_SUSPEND_DEL_SHIFT)))
    #define PinStop_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PinStop__PC)
    /* Port Configuration */
    #define PinStop_PC                 (* (reg32 *) PinStop__PC)
#endif
/* Pin State */
#define PinStop_PS                     (* (reg32 *) PinStop__PS)
/* Data Register */
#define PinStop_DR                     (* (reg32 *) PinStop__DR)
/* Input Buffer Disable Override */
#define PinStop_INP_DIS                (* (reg32 *) PinStop__PC2)

/* Interrupt configuration Registers */
#define PinStop_INTCFG                 (* (reg32 *) PinStop__INTCFG)
#define PinStop_INTSTAT                (* (reg32 *) PinStop__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PinStop_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PinStop__SIO)
    #define PinStop_SIO_REG            (* (reg32 *) PinStop__SIO)
#endif /* (PinStop__SIO_CFG) */

/* USBIO registers */
#if !defined(PinStop__PC) && (CY_PSOC4_4200L)
    #define PinStop_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PinStop_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PinStop_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PinStop_DRIVE_MODE_SHIFT       (0x00u)
#define PinStop_DRIVE_MODE_MASK        (0x07u << PinStop_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PinStop_H */


/* [] END OF FILE */
