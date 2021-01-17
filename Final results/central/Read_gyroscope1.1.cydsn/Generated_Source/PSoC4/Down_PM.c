/*******************************************************************************
* File Name: Down.c  
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
#include "Down.h"

static Down_BACKUP_STRUCT  Down_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Down_Sleep
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
*  \snippet Down_SUT.c usage_Down_Sleep_Wakeup
*******************************************************************************/
void Down_Sleep(void)
{
    #if defined(Down__PC)
        Down_backup.pcState = Down_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Down_backup.usbState = Down_CR1_REG;
            Down_USB_POWER_REG |= Down_USBIO_ENTER_SLEEP;
            Down_CR1_REG &= Down_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Down__SIO)
        Down_backup.sioState = Down_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Down_SIO_REG &= (uint32)(~Down_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Down_Wakeup
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
*  Refer to Down_Sleep() for an example usage.
*******************************************************************************/
void Down_Wakeup(void)
{
    #if defined(Down__PC)
        Down_PC = Down_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Down_USB_POWER_REG &= Down_USBIO_EXIT_SLEEP_PH1;
            Down_CR1_REG = Down_backup.usbState;
            Down_USB_POWER_REG &= Down_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Down__SIO)
        Down_SIO_REG = Down_backup.sioState;
    #endif
}


/* [] END OF FILE */
