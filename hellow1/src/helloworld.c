/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
//#include "xil_printf.h"
#include "xgpiops.h"
#include "sleep.h"
#include "xparameters.h"
#include "xil_types.h"
#include "PWM_Generator.h"


int gpio_T()

{

	static XGpioPs psGpioInstancePtr;

	XGpioPs_Config* GpioConfigPtr;

	int xStatus;

//-- EMIO的初始化

	GpioConfigPtr = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);

	if (GpioConfigPtr == NULL)

		return XST_FAILURE;

	xStatus = XGpioPs_CfgInitialize(&psGpioInstancePtr, GpioConfigPtr,
			GpioConfigPtr->BaseAddr);

	if (XST_SUCCESS != xStatus)

		print(" PS GPIO INIT FAILED \n\r");

//--EMIO的输入输出操作

	//XGpioPs_SetDirectionPin(&psGpioInstancePtr, 0, 1);  //1--output  0--input

	XGpioPs_SetDirectionPin(&psGpioInstancePtr, 37, 1);

	XGpioPs_SetDirectionPin(&psGpioInstancePtr, 38, 1);

	XGpioPs_SetDirectionPin(&psGpioInstancePtr, 15, 1);

	XGpioPs_SetDirectionPin(&psGpioInstancePtr, 54, 1);

	XGpioPs_SetDirectionPin(&psGpioInstancePtr, 55, 1);
	XGpioPs_SetDirectionPin(&psGpioInstancePtr, 56, 1);
	XGpioPs_SetDirectionPin(&psGpioInstancePtr, 57, 1);

	//使能EMIO输出

	//XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, 0, 1);

	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, 37, 1);

	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, 38, 1);

	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, 15, 1);

	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, 54, 1);

	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, 55, 1);
	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, 56, 1);
	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, 57, 1);

	XGpioPs_SetDirectionPin(&psGpioInstancePtr, 39, 1);
	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, 39, 1);

	while (1)

	{

		XGpioPs_WritePin(&psGpioInstancePtr, 39, 1);  //MIO的第0位输出1

		usleep(200000);  //延时

		XGpioPs_WritePin(&psGpioInstancePtr, 39, 0);  //MIO的第0位输出0

		usleep(200000);  //延时

		XGpioPs_WritePin(&psGpioInstancePtr, 37, 1);  //MIO的第13位输出1

		usleep(200000);  //延时

		XGpioPs_WritePin(&psGpioInstancePtr, 37, 0);  //MIO的第13位输出0

		usleep(200000);  //延时

		XGpioPs_WritePin(&psGpioInstancePtr, 38, 1);  //EMIO的第0位输出1

		usleep(200000);  //延时

		XGpioPs_WritePin(&psGpioInstancePtr, 38, 0);  //EMIO的第0位输出0

		usleep(200000);  //延时

		XGpioPs_WritePin(&psGpioInstancePtr, 15, 1);  //EMIO的第1位输出1

		usleep(200000);  //延时

		XGpioPs_WritePin(&psGpioInstancePtr, 15, 0);  //EMIO的第1位输出0

		usleep(200000);  //延时

		XGpioPs_WritePin(&psGpioInstancePtr, 54, 1);  //EMIO的第2位输出1

		usleep(200000);  //延时

		XGpioPs_WritePin(&psGpioInstancePtr, 54, 0);  //EMIO的第2位输出0

		usleep(200000);  //延时

		XGpioPs_WritePin(&psGpioInstancePtr, 55, 1);  //EMIO的第3位输出1
		XGpioPs_WritePin(&psGpioInstancePtr, 56, 1);  //EMIO的第3位输出1
		XGpioPs_WritePin(&psGpioInstancePtr, 57, 1);  //EMIO的第3位输出1

		usleep(200000);  //延时

		XGpioPs_WritePin(&psGpioInstancePtr, 55, 0);  //EMIO的第3位输出0
		XGpioPs_WritePin(&psGpioInstancePtr, 56, 0);  //EMIO的第3位输出0
		XGpioPs_WritePin(&psGpioInstancePtr, 57, 0);  //EMIO的第3位输出0

		usleep(200000);  //延时

	}

	return 0;

}

int main()
{
    init_platform();
    print("Hello World00000\n\r");

	PWM_GENERATOR_mDisableOutput(XPAR_M_PWM_0_S00_AXI_BASEADDR);
	PWM_GENERATOR_mSetLoad(XPAR_M_PWM_0_S00_AXI_BASEADDR, 50000000);//1sec period
	PWM_GENERATOR_mSetCompare(XPAR_M_PWM_0_S00_AXI_BASEADDR, 25000000);// 50% duty cycle
	PWM_GENERATOR_mEnableOutput(XPAR_M_PWM_0_S00_AXI_BASEADDR);

	PWM_GENERATOR_mSetLoad(XPAR_M_PWM_0_S00_AXI_BASEADDR, 5000000);//100microsec period
	int duty_cycle = 5000000;
	while(1){

		PWM_GENERATOR_mSetCompare(XPAR_M_PWM_0_S00_AXI_BASEADDR, duty_cycle);// 50% duty cycle
		if(duty_cycle <= 0) duty_cycle = 5000000;
		duty_cycle-=1000;
		usleep(10);
	}

    //gpio_T();
while(0){
    print("Hello World\n\r");
    sleep(1);
}
    print("Successfully ran Hello World application");
    cleanup_platform();
    return 0;
}
