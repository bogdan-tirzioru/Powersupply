******************************************************************************
* @file    readme.txt
* @author  MCD Application Team
* @version V1.2
* @date    02-October-2018
* @brief   Accelerated Designs multiple EDA CAD tools format (.bxl) files
*          for the STM32F7 MCUs.
******************************************************************************
* COPYRIGHT(c) 2017 STMicroelectronics
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*   2. Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.
*   3. Neither the name of STMicroelectronics nor the names of its contributors
*      may be used to endorse or promote products derived from this software
*      without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************

=======================
How to use .bxl files :
=======================

The Ultra Librarian software is a free reader from Accelerated Designs which
allows the user to view the .bxl files. It also allows the user to create symbols
and footprints for most common CAD tools. For further information, please visit
first http://www.accelerated-designs.com/.

The process to use a .bxl file is detailed below:
1. Download and install the Ultra Librarian reader.
2. Unzip the zip filed of the desired product series.
3. Open the appropriate .bxl ( the Ultra Librarian software will open automatically).
4. Export the file to the desired PCB/CAD format.

The package contains :
   + A .bxl file for each STM32F7x device or generic sub-family (x) in the different existing packages
	  o Check your device part number and select it from the list
   + A .xlsx file containing the correspondance between part number and .bxl file


========================
* V1.2 - 02-October-2018
========================

Changing names assignment for all bxl files directly corresponding to product salestypes.
No more SelectBXLFile file needed.
Here is the new list:

	STM32F722VCTx
	STM32F722VETx
	STM32F732VETx
	STM32F745VETx
	STM32F745VGTx
	STM32F746VETx
	STM32F746VGTx
	STM32F756VGTx
	STM32F765VGTx
	STM32F765VITx
	STM32F767VGTx
	STM32F767VITx
	STM32F777VITx
	STM32F722ZCTx
	STM32F722ZETx	
	STM32F723ZCTx
	STM32F723ZETx
	STM32F732ZETx
	STM32F733ZETx
	STM32F745ZETx
	STM32F745ZGTx
	STM32F746ZETx
	STM32F746ZGTx
	STM32F756ZGTx
	STM32F765ZGTx
	STM32F765ZITx
	STM32F767ZGTx
	STM32F767ZITx
	STM32F777ZITx
	STM32F722ICTx
	STM32F722IETx
	STM32F723ICTx
	STM32F723IETx
	STM32F732IETx
	STM32F733IETx	
	STM32F745IETx
	STM32F745IGTx
	STM32F746IETx
	STM32F746IGTx
	STM32F756IGTx
	STM32F765IGTx
	STM32F765IITx
	STM32F767IGTx
	STM32F767IITx
	STM32F769IGTx
	STM32F769IITx
	STM32F777IITx
	STM32F779IITx
	STM32F746BETx
	STM32F746BGTx
	STM32F756BGTx
	STM32F765BGTx
	STM32F765BITx
	STM32F767BGTx
	STM32F767BITx
	STM32F769BGTx
	STM32F769BITx
	STM32F777BITx
	STM32F779BITx
	STM32F722RCTx
	STM32F722RETx
	STM32F732RETx
	STM32F745VEHx
	STM32F745VGHx
	STM32F746VEHx
	STM32F746VGHx	
	STM32F756VGHx
	STM32F765VGHx
	STM32F765VIHx
	STM32F767VGHx
	STM32F767VIHx
	STM32F777VIHx
	STM32F746NEHx
	STM32F746NGHx
	STM32F756NGHx
	STM32F765NGHx
	STM32F765NIHx
	STM32F767NGHx
	STM32F767NIHx
	STM32F769NGHx
	STM32F769NIHx
	STM32F777NIHx
	STM32F779NIHx
	STM32F723ZCIx
	STM32F723ZEIx
	STM32F733ZEIx
	STM32F722ICKx
	STM32F722IEKx
	STM32F723ICKx
	STM32F723IEKx
	STM32F732IEKx
	STM32F733IEKx
	STM32F745IEKx
	STM32F745IGKx
	STM32F746IEKx
	STM32F746IGKx
	STM32F756IGKx
	STM32F765IGKx
	STM32F765IIKx
	STM32F767IGKx
	STM32F767IIKx
	STM32F777IIKx
	STM32F723VEYx
	STM32F733VEYx
	STM32F746ZEYx
	STM32F746ZGYx
	STM32F756ZGYx
	STM32F769AIYx
	STM32F778AIYx
	STM32F779AIYx
	STM32F730I8Kx
	STM32F730R8Tx
	STM32F730V8Tx
	STM32F730Z8Tx
	STM32F750N8Hx
	STM32F750V8Tx
	STM32F750Z8Tx




========================
* V1.1 - 15-February-2017
========================
  Created.

   + STM32F7x2IxK
   + STM32F7x2IxT
   + STM32F7x2RxT
   + STM32F7x2VxT
   + STM32F7x2ZxT
   + STM32F7x3IxK
   + STM32F7x3IxT
   + STM32F7x3VxY
   + STM32F7x3ZxT
   + STM32F7x3ZxI

========================
* V1.0 - 25-August-2016
========================
  Created.
  
   + STM32F74xBxT
   + STM32F74xIxK
   + STM32F74xIxT
   + STM32F74xNxH
   + STM32F74xVxH
   + STM32F74xVxT
   + STM32F74xZxT
   + STM32F74xZxY
   + STM32F756BxT
   + STM32F756IxK
   + STM32F756IxT
   + STM32F756NxH
   + STM32F756VxH
   + STM32F756VxT
   + STM32F756ZxT
   + STM32F756ZxY
   + STM32F769BxT
   + STM32F769IxT
   + STM32F769NxH
   + STM32F76xAxY
   + STM32F76xBxT
   + STM32F76xIxK
   + STM32F76xIxT
   + STM32F76xNxH
   + STM32F76xVxT
   + STM32F76xZxT
   + STM32F779BxT
   + STM32F779IxT
   + STM32F779NxH
   + STM32F77xAxY
   + STM32F77xBxT
   + STM32F77xIxK
   + STM32F77xIxT
   + STM32F77xNxH
   + STM32F77xVxT
   + STM32F77xZxT

  

******************* (C) COPYRIGHT 2017 STMicroelectronics *****END OF FILE
