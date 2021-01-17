/*******************************************************************************
* File Name: LedScanningStatus.h  
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

#if !defined(CY_PINS_LedScanningStatus_H) /* Pins LedScanningStatus_H */
#define CY_PINS_LedScanningStatus_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LedScanningStatus_aliases.h"


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
} LedScanningStatus_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   LedScanningStatus_Read(void);
void    LedScanningStatus_Write(uint8 value);
uint8   LedScanningStatus_ReadDataReg(void);
#if defined(LedScanningStatus__PC) || (CY_PSOC4_4200L) 
    void    LedScanningStatus_SetDriveMode(uint8 mode);
#endif
void    LedScanningStatus_SetInterruptMode(uint16 position, uint16 mode);
uint8   LedScanningStatus_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void LedScanningStatus_Sleep(void); 
void LedScanningStatus_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(LedScanningStatus__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define LedScanningStatus_DRIVE_MODE_BITS        (3)
    #define LedScanningStatus_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LedScanningStatus_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the LedScanningStatus_SetDriveMode() function.
         *  @{
         */
        #define LedScanningStatus_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define LedScanningStatus_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define LedScanningStatus_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define LedScanningStatus_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define LedScanningStatus_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define LedScanningStatus_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define LedScanningStatus_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define LedScanningStatus_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define LedScanningStatus_MASK               LedScanningStatus__MASK
#define LedScanningStatus_SHIFT              LedScanningStatus__SHIFT
#define LedScanningStatus_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LedScanningStatus_SetInterruptMode() function.
     *  @{
     */
        #define LedScanningStatus_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define LedScanningStatus_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define LedScanningStatus_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define LedScanningStatus_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(LedScanningStatus__SIO)
    #define LedScanningStatus_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(LedScanningStatus__PC) && (CY_PSOC4_4200L)
    #define LedScanningStatus_USBIO_ENABLE               ((uint32)0x80000000u)
    #define LedScanningStatus_USBIO_DISABLE              ((uint32)(~LedScanningStatus_USBIO_ENABLE))
    #define LedScanningStatus_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define LedScanningStatus_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define LedScanningStatus_USBIO_ENTER_SLEEP          ((uint32)((1u << LedScanningStatus_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << LedScanningStatus_USBIO_SUSPEND_DEL_SHIFT)))
    #define LedScanningStatus_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << LedScanningStatus_USBIO_SUSPEND_SHIFT)))
    #define LedScanningStatus_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << LedScanningStatus_USBIO_SUSPEND_DEL_SHIFT)))
    #define LedScanningStatus_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(LedScanningStatus__PC)
    /* Port Configuration */
    #define LedScanningStatus_PC                 (* (reg32 *) LedScanningStatus__PC)
#endif
/* Pin State */
#define LedScanningStatus_PS                     (* (reg32 *) LedScanningStatus__PS)
/* Data Register */
#define LedScanningStatus_DR                     (* (reg32 *) LedScanningStatus__DR)
/* Input Buffer Disable Override */
#define LedScanningStatus_INP_DIS                (* (reg32 *) LedScanningStatus__PC2)

/* Interrupt configuration Registers */
#define LedScanningStatus_INTCFG                 (* (reg32 *) LedScanningStatus__INTCFG)
#define LedScanningStatus_INTSTAT                (* (reg32 *) LedScanningStatus__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define LedScanningStatus_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(LedScanningStatus__SIO)
    #define LedScanningStatus_SIO_REG            (* (reg32 *) LedScanningStatus__SIO)
#endif /* (LedScanningStatus__SIO_CFG) */

/* USBIO registers */
#if !defined(LedScanningStatus__PC) && (CY_PSOC4_4200L)
    #define LedScanningStatus_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define LedScanningStatus_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define LedScanningStatus_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define LedScanningStatus_DRIVE_MODE_SHIFT       (0x00u)
#define LedScanningStatus_DRIVE_MODE_MASK        (0x07u << LedScanningStatus_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins LedScanningStatus_H */


/* [] END OF FILE */
