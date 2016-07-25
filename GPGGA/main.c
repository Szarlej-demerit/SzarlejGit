/*
 * main.c
 *
 *  Created on: 8.7.2016
 *      Author: Szarlej
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graphics.h"

#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_int.h"
#include "em_cryotimer.h"
#include "em_burtc.h"
#include "em_rtc.h"
#include "em_rmu.h"

#include "gpgga.h"

void configLED(void){

	CMU_ClockEnable(cmuClock_GPIO, true);
	GPIO_PinModeSet(gpioPortF, 4, gpioModePushPull, 0);
	GPIO_PinModeSet(gpioPortF, 5, gpioModePushPull, 0);

}

void DISP_Init(void){
	GRAPHICS_Init();
	GRAPHICS_Clear();
	GRAPHICS_AppendString("Ok!");
	GRAPHICS_Update();
}



int main(void){

	DISP_Init();

	char link[56] = "";
	uint8_t bin[17];
	GPGGA_Struct_t data, data_out;

	strcpy(data.Time, "082002.00");
	strcpy(data.Latitude, "5355.0771");
	data.NS='N';
	strcpy(data.Longitude, "02729.8732");
	data.EW='E';
	data.ReceiverMode='1';
	strcpy(data.SatelliteNum, "4");
	strcpy(data.Altitude, "3");
	strcpy(data.Data, "130416");
	data.checksum=202;

	//Упаковка и распаковка данных
	GPGGA_Data2Bin(&data, bin);
	GPGGA_Bin2Data(&data_out, bin);
	GPGGA_Data2Google(&data, link);

	//Для проверки вывод на дисплей
	char NS[2];
	sprintf(NS, "%c", data_out.NS);
	char EW[2];
	sprintf(EW, "%c", data_out.EW);
	char ReceiverMode[2];
	sprintf(ReceiverMode, "%c", data_out.ReceiverMode);

	GRAPHICS_AppendString(data_out.Time);
	GRAPHICS_AppendString(data_out.Latitude);
	GRAPHICS_AppendString(NS);
	GRAPHICS_AppendString(data_out.Longitude);
	GRAPHICS_AppendString(EW);
	GRAPHICS_AppendString(ReceiverMode);
	GRAPHICS_AppendString(data_out.SatelliteNum);
	GRAPHICS_AppendString(data_out.Altitude);
	GRAPHICS_AppendString(data_out.Data);

	GRAPHICS_AppendString(link);

	GRAPHICS_Update();
}

