/*******************************************************************************
* File Name: Up.c  
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
#include "Up.h"

static Up_BACKUP_STRUCT  Up_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Up_Sleep
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
*  \snippet Up_SUT.c usage_Up_Sleep_Wakeup
*******************************************************************************/
void Up_Sleep(void)
{
    #if defined(Up__PC)
        Up_backup.pcState = Up_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Up_backup.usbState = Up_CR1_REG;
            Up_USB_POWER_REG |= Up_USBIO_ENTER_SLEEP;
            Up_CR1_REG &= Up_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Up__SIO)
        Up_backup.sioState = Up_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Up_SIO_REG &= (uint32)(~Up_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Up_Wakeup
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
*  Refer to Up_Sleep() for an example usage.
*******************************************************************************/
void Up_Wakeup(void)
{
    #if defined(Up__PC)
        Up_PC = Up_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Up_USB_POWER_REG &= Up_USBIO_EXIT_SLEEP_PH1;
            Up_CR1_REG = Up_backup.usbState;
            Up_USB_POWER_REG &= Up_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Up__SIO)
        Up_SIO_REG = Up_backup.sioState;
    #endif
}


/* [] END OF FILE */
