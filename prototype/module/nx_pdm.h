/*
 * Copyright (C) 2016  Nexell Co., Ltd.
 * Author: Sangjong, Han <hans@nexell.co.kr>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __NX_PDM_H__
#define __NX_PDM_H__

#include "../base/nx_prototype.h"

#ifdef	__cplusplus
extern "C"
{
#endif

//------------------------------------------------------------------------------
/// @defgroup	PDM
//------------------------------------------------------------------------------
//@{

//--------------------------------------------------------------------------
/// @brief	register map
struct NX_PDM_RegisterSet
{
    volatile U32 PDM_CTRL	    ;
    volatile U32 PDM_GAIN0	    ;
    volatile U32 PDM_GAIN1	    ;
    volatile U32 PDM_COEFF	    ;
    volatile U32 PDM_DATA	    ;
    volatile U32 PDM_CTRL1      ;
    volatile U32 PDM_IRQCTRL	;
};

//------------------------------------------------------------------------------
///	@name	PDM Interface
//------------------------------------------------------------------------------
//@{
//U32   NX_PDM_GetTEMP( U32 ModuleIndex );
//@}

//------------------------------------------------------------------------------
///	@name	Basic Interface
//------------------------------------------------------------------------------
//@{
CBOOL NX_PDM_Initialize( void );
U32   NX_PDM_GetNumberOfModule( void );

U32   NX_PDM_GetSizeOfRegisterSet( void );
void  NX_PDM_SetBaseAddress( U32 ModuleIndex, void* BaseAddress );
void*  NX_PDM_GetBaseAddress( U32 ModuleIndex );
U32   NX_PDM_GetPhysicalAddress ( U32 ModuleIndex );
CBOOL NX_PDM_OpenModule( U32 ModuleIndex );
CBOOL NX_PDM_CloseModule( U32 ModuleIndex );
//CBOOL NX_PDM_CheckBusy( U32 ModuleIndex );
//@}

//------------------------------------------------------------------------------
///	@name	clock Interface
//------------------------------------------------------------------------------
U32 NX_PDM_GetClockNumber (U32 ModuleIndex);

//------------------------------------------------------------------------------
///	@name	reset Interface
//------------------------------------------------------------------------------
//@{
U32 NX_PDM_GetResetNumber ( U32 ModuleIndex );
//@}

//------------------------------------------------------------------------------
///	@name	Interrupt Interface
//------------------------------------------------------------------------------
//@{
/// @brief	interrupt index for IntNum
U32   NX_PDM_GetInterruptNumber ( U32 ModuleIndex );

//-------
// IRQ Count ????. 0???? IRQ Disable
void	NX_PDM_SetInterruptMode( U32 ModuleIndex, U32 Mode );
CBOOL NX_PDM_GetInterruptPendingAll( U32 ModuleIndex );
void  NX_PDM_ClearInterruptPendingAll( U32 ModuleIndex );
//@}

//------------------------------------------------------------------------------
///	@name	DMA Interface
//------------------------------------------------------------------------------
//@{
/// @brief	DMA index for DMAChannelIndex
U32 NX_PDM_GetDMANumber ( U32 ModuleIndex );
U32 NX_PDM_GetDMABusWidth( U32 ModuleIndex );
//@}

//------------------------------------------------------------------------------
///	@name	Basic Use Functions
//------------------------------------------------------------------------------
//@{
void NX_PDM_InitSet( U32 ModuleIndex, U32 Enb);
void NX_PDM_SetGain0( U32 ModuleIndex, S16 Gainx4      , S16 Gainx2 );
void NX_PDM_SetGain1( U32 ModuleIndex, S16 GainxMinus4 , S16 GainxMinus2 );
void NX_PDM_SetCoeff( U32 ModuleIndex, S16 Coeff1      , S16 Coeff0 );
void NX_PDM_SetOverSample( U32 ModuleIndex, U32 OverSample );
void NX_PDM_SetStrobeShift( U32 ModuleIndex, U32 StrobeShift );
void NX_PDM_DMAMode( U32 ModuleIndex, U32 DMAMode );
void NX_PDM_StartEnable( U32 ModuleIndex, CBOOL Enb );


void NX_PDM_SetShiftPerPixel( U32 ModuleIndex, U32 NUM );
void NX_PDM_SetNumOfClock( U32 ModuleIndex, U32 NUM );
void NX_PDM_SetSamplePosition( U32 ModuleIndex, U32 NUM );


void NX_PDM_SetCTRL1( U32 ModuleIndex, U32 Shift, U32 Numof, U32 Sample );


//=================
// Register R/W Test Function
// prototype ???? ????????.
//=================
CBOOL NX_PDM_RegTest( U32 ModuleIndex );


//@}



//@}

#ifdef	__cplusplus
}
#endif


#endif // __NX_PDM_H__
