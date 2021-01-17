/*******************************************************************************
* File Name: PinStop.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "PinStop.h"

static PinStop_BACKUP_STRUCT  PinStop_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: PinStop_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet PinStop_SUT.c usage_PinStop_Sleep_Wakeup
*******************************************************************************/
void PinStop_Sleep(void)
{
    #if defined(PinStop__PC)
        PinStop_backup.pcState = PinStop_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            PinStop_backup.usbState = PinStop_CR1_REG;
            PinStop_USB_POWER_REG |= PinStop_USBIO_ENTER_SLEEP;
            PinStop_CR1_REG &= PinStop_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(PinStop__SIO)
        PinStop_backup.sioState = PinStop_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        PinStop_SIO_REG &= (uint32)(~PinStop_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: PinStop_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to PinStop_Sleep() for an example usage.
*******************************************************************************/
void PinStop_Wakeup(void)
{
    #if defined(PinStop__PC)
        PinStop_PC = PinStop_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            PinStop_USB_POWER_REG &= PinStop_USBIO_EXIT_SLEEP_PH1;
            PinStop_CR1_REG = PinStop_backup.usbState;
            PinStop_USB_POWER_REG &= PinStop_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(PinStop__SIO)
        PinStop_SIO_REG = PinStop_backup.sioState;
    #endif
}


/* [] END OF FILE */
