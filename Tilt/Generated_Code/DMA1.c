/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : DMA1.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Init_DMA
**     Version     : Component 01.002, Driver 01.02, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-03-27, 16:14, # CodeGen: 58
**     Abstract    :
**          This file implements the DMA (DMA) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : DMA1
**          Device                                         : DMA
**          Clock gate for DMA                             : Enabled
**          Clock gate for DMA multiplexor 0               : Enabled
**          Channels                                       : 
**            Channel 0                                    : Initialize
**              Settings                                   : 
**                Transfer mode                            : Cycle-steal
**                Auto disable external request            : Disabled
**                Asynchronous request                     : Enabled
**                Auto align                               : Disabled
**                Channel links settings                   : 
**                  Link channel control                   : LCH1 after each cycle steal transfer
**                  Link channel 1 (LCH1)                  : DMA channel 1
**                  Link channel 2 (LCH2)                  : DMA channel 0
**                Data source                              : 
**                  External object declaration            : 
**                  Address                                : (uint32_t)&ADC0_RA
**                  Address increment                      : Disabled
**                  Transfer size                          : 16-bit
**                  Address modulo                         : Buffer disabled
**                Data destination                         : 
**                  External object declaration            : 
**                  Address                                : 
**                  Address increment                      : Enabled
**                  Transfer size                          : 16-bit
**                  Address modulo                         : Buffer disabled
**                Byte count                               : 16
**              Pins/Signals                               : 
**                DMA MUX settings                         : 
**                  Channel state                          : Enabled
**                  Channel periodic trigger               : Disabled
**                  Channel request                        : ADC0_DMA_Request
**                  Channel request signal                 : 
**              Interrupts                                 : 
**                DMA transfer done interrupt              : 
**                  Interrupt                              : INT_DMA0
**                  Interrupt request                      : Enabled
**                  Interrupt priority                     : 0 (Highest)
**                  ISR Name                               : ADCint
**                  DMA transfer interrupt                 : Enabled
**              Initialization                             : 
**                External request                         : Enabled
**                Start DMA transfer                       : No
**            Channel 1                                    : Initialize
**              Settings                                   : 
**                Transfer mode                            : Cycle-steal
**                Auto disable external request            : Enabled
**                Asynchronous request                     : Enabled
**                Auto align                               : Disabled
**                Channel links settings                   : 
**                  Link channel control                   : LCH1 after each cycle steal transfer
**                  Link channel 1 (LCH1)                  : DMA channel 2
**                  Link channel 2 (LCH2)                  : DMA channel 0
**                Data source                              : 
**                  External object declaration            : 
**                  Address                                : 0
**                  Address increment                      : Enabled
**                  Transfer size                          : 8-bit
**                  Address modulo                         : Buffer disabled
**                Data destination                         : 
**                  External object declaration            : 
**                  Address                                : &ADC0_CFG2
**                  Address increment                      : Disabled
**                  Transfer size                          : 8-bit
**                  Address modulo                         : Buffer disabled
**                Byte count                               : 8
**              Pins/Signals                               : 
**                DMA MUX settings                         : 
**                  Channel state                          : Enabled
**                  Channel periodic trigger               : Disabled
**                  Channel request                        : Software_DMA_Request
**                  Channel request signal                 : 
**              Interrupts                                 : 
**                DMA transfer done interrupt              : 
**                  Interrupt                              : INT_DMA1
**                  Interrupt request                      : Disabled
**                  Interrupt priority                     : 0 (Highest)
**                  ISR Name                               : 
**                  DMA transfer interrupt                 : Disabled
**              Initialization                             : 
**                External request                         : Enabled
**                Start DMA transfer                       : No
**            Channel 2                                    : Initialize
**              Settings                                   : 
**                Transfer mode                            : Cycle-steal
**                Auto disable external request            : Enabled
**                Asynchronous request                     : Enabled
**                Auto align                               : Disabled
**                Channel links settings                   : 
**                  Link channel control                   : No link
**                  Link channel 1 (LCH1)                  : DMA channel 0
**                  Link channel 2 (LCH2)                  : DMA channel 0
**                Data source                              : 
**                  External object declaration            : 
**                  Address                                : 0
**                  Address increment                      : Enabled
**                  Transfer size                          : 8-bit
**                  Address modulo                         : Buffer disabled
**                Data destination                         : 
**                  External object declaration            : 
**                  Address                                : &ADC0_SC1A
**                  Address increment                      : Disabled
**                  Transfer size                          : 8-bit
**                  Address modulo                         : Buffer disabled
**                Byte count                               : 8
**              Pins/Signals                               : 
**                DMA MUX settings                         : 
**                  Channel state                          : Enabled
**                  Channel request                        : Software_DMA_Request
**                  Channel request signal                 : 
**              Interrupts                                 : 
**                DMA transfer done interrupt              : 
**                  Interrupt                              : INT_DMA2
**                  Interrupt request                      : Disabled
**                  Interrupt priority                     : 0 (Highest)
**                  ISR Name                               : 
**                  DMA transfer interrupt                 : Disabled
**              Initialization                             : 
**                External request                         : Enabled
**                Start DMA transfer                       : No
**            Channel 3                                    : Do not initialize
**          Initialization                                 : 
**            Call Init method                             : no
**     Contents    :
**         Init - void DMA1_Init(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file DMA1.c
** @version 01.02
** @brief
**          This file implements the DMA (DMA) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup DMA1_module DMA1 module documentation
**  @{
*/         

/* MODULE DMA1. */

#include "DMA1.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  DMA1_Init (component Init_DMA)
**     Description :
**         This method initializes registers of the DMA module
**         according to the Peripheral Initialization settings.
**         Call this method in user code to initialize the module. By
**         default, the method is called by PE automatically; see "Call
**         Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void DMA1_Init(void)
{
  /* SIM_SCGC7: DMA=1 */
  SIM_SCGC7 |= SIM_SCGC7_DMA_MASK;
  /* SIM_SCGC6: DMAMUX=1 */
  SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;
  /* DMAMUX0_CHCFG0: ENBL=0,TRIG=0,SOURCE=0 */
  DMAMUX0_CHCFG0 = DMAMUX_CHCFG_SOURCE(0x00);
  /* DMAMUX0_CHCFG1: ENBL=0,TRIG=0,SOURCE=0 */
  DMAMUX0_CHCFG1 = DMAMUX_CHCFG_SOURCE(0x00);
  /* DMAMUX0_CHCFG2: ENBL=0,TRIG=0,SOURCE=0 */
  DMAMUX0_CHCFG2 = DMAMUX_CHCFG_SOURCE(0x00);
  /* DMAMUX0_CHCFG3: ENBL=0,TRIG=0,SOURCE=0 */
  DMAMUX0_CHCFG3 = DMAMUX_CHCFG_SOURCE(0x00);
  /* DMA_DSR_BCR0: DONE=1 */
  DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;
  /* DMA_DSR_BCR1: DONE=1 */
  DMA_DSR_BCR1 |= DMA_DSR_BCR_DONE_MASK;
  /* DMA_DSR_BCR2: DONE=1 */
  DMA_DSR_BCR2 |= DMA_DSR_BCR_DONE_MASK;
  /* DMA_SAR0 = (uint32_t)&ADC0_RA */
  DMA_SAR0 = (uint32_t)((uint32_t)&ADC0_RA);
  /* DMA_SAR1 = 0 */
  DMA_SAR1 = (uint32_t)(0);
  /* DMA_SAR2 = 0 */
  DMA_SAR2 = (uint32_t)(0);
  /* DMA_DAR1 = &ADC0_CFG2 */
  DMA_DAR1 = (uint32_t)(&ADC0_CFG2);
  /* DMA_DAR2 = &ADC0_SC1A */
  DMA_DAR2 = (uint32_t)(&ADC0_SC1A);
  /* DMA_DSR_BCR0: ??=0,CE=0,BES=0,BED=0,??=0,REQ=0,BSY=0,DONE=0,BCR=0x10 */
  DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(0x10);
  /* DMA_DSR_BCR1: ??=0,CE=0,BES=0,BED=0,??=0,REQ=0,BSY=0,DONE=0,BCR=8 */
  DMA_DSR_BCR1 = DMA_DSR_BCR_BCR(0x08);
  /* DMA_DSR_BCR2: ??=0,CE=0,BES=0,BED=0,??=0,REQ=0,BSY=0,DONE=0,BCR=8 */
  DMA_DSR_BCR2 = DMA_DSR_BCR_BCR(0x08);
  /* DMA_DCR0: EINT=1,ERQ=1,CS=1,AA=0,??=0,??=0,??=0,??=0,EADREQ=1,SINC=0,SSIZE=2,DINC=1,DSIZE=2,START=0,SMOD=0,DMOD=0,D_REQ=0,??=0,LINKCC=2,LCH1=1,LCH2=0 */
  DMA_DCR0 = DMA_DCR_EINT_MASK |
             DMA_DCR_ERQ_MASK |
             DMA_DCR_CS_MASK |
             DMA_DCR_EADREQ_MASK |
             DMA_DCR_SSIZE(0x02) |
             DMA_DCR_DINC_MASK |
             DMA_DCR_DSIZE(0x02) |
             DMA_DCR_SMOD(0x00) |
             DMA_DCR_DMOD(0x00) |
             DMA_DCR_LINKCC(0x02) |
             DMA_DCR_LCH1(0x01) |
             DMA_DCR_LCH2(0x00);
  /* DMA_DCR1: EINT=0,ERQ=1,CS=1,AA=0,??=0,??=0,??=0,??=0,EADREQ=1,SINC=1,SSIZE=1,DINC=0,DSIZE=1,START=0,SMOD=0,DMOD=0,D_REQ=1,??=0,LINKCC=2,LCH1=2,LCH2=0 */
  DMA_DCR1 = DMA_DCR_ERQ_MASK |
             DMA_DCR_CS_MASK |
             DMA_DCR_EADREQ_MASK |
             DMA_DCR_SINC_MASK |
             DMA_DCR_SSIZE(0x01) |
             DMA_DCR_DSIZE(0x01) |
             DMA_DCR_SMOD(0x00) |
             DMA_DCR_DMOD(0x00) |
             DMA_DCR_D_REQ_MASK |
             DMA_DCR_LINKCC(0x02) |
             DMA_DCR_LCH1(0x02) |
             DMA_DCR_LCH2(0x00);
  /* DMA_DCR2: EINT=0,ERQ=1,CS=1,AA=0,??=0,??=0,??=0,??=0,EADREQ=1,SINC=1,SSIZE=1,DINC=0,DSIZE=1,START=0,SMOD=0,DMOD=0,D_REQ=1,??=0,LINKCC=0,LCH1=0,LCH2=0 */
  DMA_DCR2 = DMA_DCR_ERQ_MASK |
             DMA_DCR_CS_MASK |
             DMA_DCR_EADREQ_MASK |
             DMA_DCR_SINC_MASK |
             DMA_DCR_SSIZE(0x01) |
             DMA_DCR_DSIZE(0x01) |
             DMA_DCR_SMOD(0x00) |
             DMA_DCR_DMOD(0x00) |
             DMA_DCR_D_REQ_MASK |
             DMA_DCR_LINKCC(0x00) |
             DMA_DCR_LCH1(0x00) |
             DMA_DCR_LCH2(0x00);
  /* DMAMUX0_CHCFG0: ENBL=1,TRIG=0,SOURCE=0x28 */
  DMAMUX0_CHCFG0 = (DMAMUX_CHCFG_ENBL_MASK | DMAMUX_CHCFG_SOURCE(0x28));
  /* DMAMUX0_CHCFG1: ENBL=1,TRIG=0,SOURCE=0 */
  DMAMUX0_CHCFG1 = (DMAMUX_CHCFG_ENBL_MASK | DMAMUX_CHCFG_SOURCE(0x00));
  /* DMAMUX0_CHCFG2: ENBL=1,SOURCE=0 */
  DMAMUX0_CHCFG2 = (uint8_t)((DMAMUX0_CHCFG2 & (uint8_t)~(uint8_t)(
                    DMAMUX_CHCFG_SOURCE(0x3F)
                   )) | (uint8_t)(
                    DMAMUX_CHCFG_ENBL_MASK
                   ));
}

/*
** ###################################################################
**
**  The interrupt service routine(s) must be implemented
**  by user in one of the following user modules.
**
**  If the "Generate ISR" option is enabled, Processor Expert generates
**  ISR templates in the CPU event module.
**
**  User modules:
**      ProcessorExpert.c
**      Events.c
**
** ###################################################################
PE_ISR(ADCint)
{
// NOTE: The routine should include actions to clear the appropriate
//       interrupt flags.
//
}
*/


/* END DMA1. */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
