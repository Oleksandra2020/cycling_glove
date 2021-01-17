/*******************************************************************************
* File Name: ControlStatusRegs_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "ControlStatusRegs.h"

/* Check for removal by optimization */
#if !defined(ControlStatusRegs_Sync_ctrl_reg__REMOVED)

static ControlStatusRegs_BACKUP_STRUCT  ControlStatusRegs_backup = {0u};

    
/*******************************************************************************
* Function Name: ControlStatusRegs_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ControlStatusRegs_SaveConfig(void) 
{
    ControlStatusRegs_backup.controlState = ControlStatusRegs_Control;
}


/*******************************************************************************
* Function Name: ControlStatusRegs_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void ControlStatusRegs_RestoreConfig(void) 
{
     ControlStatusRegs_Control = ControlStatusRegs_backup.controlState;
}


/*******************************************************************************
* Function Name: ControlStatusRegs_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ControlStatusRegs_Sleep(void) 
{
    ControlStatusRegs_SaveConfig();
}


/*******************************************************************************
* Function Name: ControlStatusRegs_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ControlStatusRegs_Wakeup(void)  
{
    ControlStatusRegs_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
