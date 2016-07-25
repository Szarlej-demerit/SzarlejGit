/*
 * gpgga.h
 *
 *  Created on: 19.7.2016
 *      Author: Szarlej
 */

#ifndef GPGGA_H_
#define GPGGA_H_

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include<math.h>

#include "gpgga.h"


typedef struct
{
    char Time[10];     	// hhmmss.ss
    char Latitude[10]; 	// xxxx.yyyy
    char NS;  			// N or S
    char Longitude[11];    // xxxxx.yyyy
    char EW;  			// E or W
    char ReceiverMode;  // 0-4
    char SatelliteNum[3]; // 0-12
    char Altitude[8];   	// aaaaa.a
    char Data[7];  		//ddmmyy
    uint16_t checksum;
} GPGGA_Struct_t;



void	GPGGA_Data2Google(GPGGA_Struct_t *data, char *link);
void	GPGGA_Data2Bin(GPGGA_Struct_t *data, uint8_t *gpsbin);
void	GPGGA_Bin2Data(GPGGA_Struct_t *data, uint8_t *gpsbin);
void	reverse(char *str, int len);
int		itoa(int x, char str[], int d);
void	ftoa(float n, char *res, int afterpoint);

#endif /* GPGGA_H_ */
