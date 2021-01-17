/*******************************************************************************
* File Name: LedServiceDiscoveryStatus.h  
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

#if !defined(CY_PINS_LedServiceDiscoveryStatus_H) /* Pins LedServiceDiscoveryStatus_H */
#define CY_PINS_LedServiceDiscoveryStatus_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LedServiceDiscoveryStatus_aliases.h"


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
} LedServiceDiscoveryStatus_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   LedServiceDiscoveryStatus_Read(void);
void    LedServiceDiscoveryStatus_Write(uint8 value);
uint8   LedServiceDiscoveryStatus_ReadDataReg(void);
#if defined(LedServiceDiscoveryStatus__PC) || (CY_PSOC4_4200L) 
    void    LedServiceDiscoveryStatus_SetDriveMode(uint8 mode);
#endif
void    LedServiceDiscoveryStatus_SetInterruptMode(uint16 position, uint16 mode);
uint8   LedServiceDiscoveryStatus_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void LedServiceDiscoveryStatus_Sleep(void); 
void LedServiceDiscoveryStatus_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(LedServiceDiscoveryStatus__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define LedServiceDiscoveryStatus_DRIVE_MODE_BITS        (3)
    #define LedServiceDiscoveryStatus_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LedServiceDiscoveryStatus_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the LedServiceDiscoveryStatus_SetDriveMode() function.
         *  @{
         */
        #define LedServiceDiscoveryStatus_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define LedServiceDiscoveryStatus_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define LedServiceDiscoveryStatus_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define LedServiceDiscoveryStatus_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define LedServiceDiscoveryStatus_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define LedServiceDiscoveryStatus_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define LedServiceDiscoveryStatus_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define LedServiceDiscoveryStatus_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define LedServiceDiscoveryStatus_MASK               LedServiceDiscoveryStatus__MASK
#define LedServiceDiscoveryStatus_SHIFT              LedServiceDiscoveryStatus__SHIFT
#define LedServiceDiscoveryStatus_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LedServiceDiscoveryStatus_SetInterruptMode() function.
     *  @{
     */
        #define LedServiceDiscoveryStatus_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define LedServiceDiscoveryStatus_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define LedServiceDiscoveryStatus_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define LedServiceDiscoveryStatus_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(LedServiceDiscoveryStatus__SIO)
    #define LedServiceDiscoveryStatus_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(LedServiceDiscoveryStatus__PC) && (CY_PSOC4_4200L)
    #define LedServiceDiscoveryStatus_USBIO_ENABLE               ((uint32)0x80000000u)
    #define LedServiceDiscoveryStatus_USBIO_DISABLE              ((uint32)(~LedServiceDiscoveryStatus_USBIO_ENABLE))
    #define LedServiceDiscoveryStatus_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define LedServiceDiscoveryStatus_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define LedServiceDiscoveryStatus_USBIO_ENTER_SLEEP          ((uint32)((1u << LedServiceDiscoveryStatus_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << LedServiceDiscoveryStatus_USBIO_SUSPEND_DEL_SHIFT)))
    #define LedServiceDiscoveryStatus_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << LedServiceDiscoveryStatus_USBIO_SUSPEND_SHIFT)))
    #define LedServiceDiscoveryStatus_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << LedServiceDiscoveryStatus_USBIO_SUSPEND_DEL_SHIFT)))
    #define LedServiceDiscoveryStatus_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(LedServiceDiscoveryStatus__PC)
    /* Port Configuration */
    #define LedServiceDiscoveryStatus_PC                 (* (reg32 *) LedServiceDiscoveryStatus__PC)
#endif
/* Pin State */
#define LedServiceDiscoveryStatus_PS                     (* (reg32 *) LedServiceDiscoveryStatus__PS)
/* Data Register */
#define LedServiceDiscoveryStatus_DR                     (* (reg32 *) LedServiceDiscoveryStatus__DR)
/* Input Buffer Disable Override */
#define LedServiceDiscoveryStatus_INP_DIS                (* (reg32 *) LedServiceDiscoveryStatus__PC2)

/* Interrupt configuration Registers */
#define LedServiceDiscoveryStatus_INTCFG                 (* (reg32 *) LedServiceDiscoveryStatus__INTCFG)
#define LedServiceDiscoveryStatus_INTSTAT                (* (reg32 *) LedServiceDiscoveryStatus__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define LedServiceDiscoveryStatus_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(LedServiceDiscoveryStatus__SIO)
    #define LedServiceDiscoveryStatus_SIO_REG            (* (reg32 *) LedServiceDiscoveryStatus__SIO)
#endif /* (LedServiceDiscoveryStatus__SIO_CFG) */

/* USBIO registers */
#if !defined(LedServiceDiscoveryStatus__PC) && (CY_PSOC4_4200L)
    #define LedServiceDiscoveryStatus_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define LedServiceDiscoveryStatus_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define LedServiceDiscoveryStatus_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define LedServiceDiscoveryStatus_DRIVE_MODE_SHIFT       (0x00u)
#define LedServiceDiscoveryStatus_DRIVE_MODE_MASK        (0x07u << LedServiceDiscoveryStatus_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins LedServiceDiscoveryStatus_H */


/* [] END OF FILE */
