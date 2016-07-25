/*
 * gpgga.c
 *
 *  Created on: 19.7.2016
 *      Author: Szarlej
 */
#include "gpgga.h"

void   GPGGA_Data2Bin(GPGGA_Struct_t *data, uint8_t *gpsbin){
	char buff[10];
	uint32_t Time, Latitude, Longitude, ReceiverMode, SatelliteNum, Altitude, Data;
	_Bool NS, EW;
	uint16_t checksum;
	uint8_t i,j;

	//Time - отброшены мс
	for(i=0; data->Time[i] != '.'; i++){
		buff[i] = data->Time[i];
	}

	buff[i] = 0;
	Time = atoi(buff);

	//Latitude
	j=0;
	for(i=0; data->Latitude[i] != 0; i++){
		if(data->Latitude[i] != '.'){
			buff[j] = data->Latitude[i];
			j++;
		}
	}
	buff[j] = 0;
	Latitude = atoi(buff);

	//NS
	if(data->NS == 'N'){
		NS = 0;
	} else {
		NS = 1;
	}

	//Longitude
	j=0;
	for(i=0; data->Longitude[i] != 0; i++){
		if(data->Longitude[i] != '.'){
			buff[j] = data->Longitude[i];
			j++;
		}
	}
	buff[j] = 0;
	Longitude = atoi(buff);

	//EW
	if(data->EW == 'E'){
		EW = 0;
	} else {
		EW = 1;
	}

	//ReceiverMode
	ReceiverMode = data->ReceiverMode - '0';

	//SatelliteNum
	SatelliteNum = atoi(data->SatelliteNum);

	//Altitude - отбрасывается дробная часть
	for(i=0; (data->Altitude[i] != 0) & (data->Altitude[i] != '.'); i++){
		buff[i] = data->Altitude[i];
	}
	buff[i] = 0;
	Altitude = atoi(buff);

	//Data
	Data = atoi(data->Data);

	checksum = data->checksum;

	//BIN
	gpsbin[0] = (Time & 0x3FC00) >> 10;
	gpsbin[1] = (Time & 0x3FC) >> 2;
	gpsbin[2] = ((Time & 0x3) << 6) | ((Latitude & 0x7E00000) >> 21);
	gpsbin[3] = (Latitude & 0x1FE000) >> 13;
	gpsbin[4] = (Latitude & 0x1FE0) >> 5;
	gpsbin[5] = ((Latitude & 0x1F) << 3) | (NS << 2) | ((Longitude & 0xC000000) >> 26);
	gpsbin[6] = (Longitude & 0x3FC0000) >> 18;
	gpsbin[7] = (Longitude & 0x3FC00) >> 10;
	gpsbin[8] = (Longitude & 0x3FC) >> 2;
	gpsbin[9] = ((Longitude & 0x3) << 6) | (EW << 5) | ((ReceiverMode & 0x3) << 3) | ((SatelliteNum & 0xe) >> 1);
	gpsbin[10] = ((SatelliteNum & 0x1) << 7) | ((Altitude & 0x1FC00) >> 10);
	gpsbin[11] = (Altitude & 0x3FC) >> 2;
	gpsbin[12] = ((Altitude & 0x3) << 6) | ((Data & 0x3F0000) >> 16);
	gpsbin[13] = (Data & 0xFF00) >> 8;
	gpsbin[14] = Data & 0xFF;
	gpsbin[15] = checksum & 0xFF00;
	gpsbin[16] = checksum & 0xFF;

}

void   GPGGA_Bin2Data(GPGGA_Struct_t *data, uint8_t *gpsbin){
	//char buff[10];
	uint32_t Time, Latitude, Longitude, ReceiverMode, SatelliteNum, Altitude, Data;
	_Bool NS, EW;
	uint16_t checksum;
	uint8_t i;
	//char *str, ch;

	//BIN
	Time = (gpsbin[0] << 10) | (gpsbin[1] << 2) | ((gpsbin[2] & 0xC0) >> 6);
	Latitude = ((gpsbin[2] & 0x3F) << 21) | (gpsbin[3] << 13) | (gpsbin[4] << 5) | ((gpsbin[5] & 0xF8) >> 3);
	NS = (gpsbin[5] & 0x4) >> 2;
	Longitude = ((gpsbin[5] & 0x3) << 26) | (gpsbin[6] << 18) | (gpsbin[7] << 10) | (gpsbin[8] << 2) | ((gpsbin[9] & 0xC0) >> 6);
	EW = (gpsbin[9] & 0x20) >> 6;
	ReceiverMode = (gpsbin[9] & 0x18) >> 3;
	SatelliteNum = ((gpsbin[9] & 0x7) << 1) | ((gpsbin[10] & 0x80) >> 7);
	Altitude = ((gpsbin[10] & 0x7F) << 10) | (gpsbin[11] << 2) | ((gpsbin[12] & 0xC0) >> 6);
	Data = ((gpsbin[12] & 0x3F) << 16) | (gpsbin[13] << 8) | gpsbin[14];
	checksum = (gpsbin[15] << 8) | gpsbin[16];


	//Time
	data->Time[9] = 0;
	data->Time[8] = '0';
	data->Time[7] = '0';
	data->Time[6] = '.';
	for(i = 6; i>0; i--){
		data->Time[i-1] = Time % 10 + '0';
		Time /= 10;
	}

	//Latitude
	data->Latitude[9]=0;
	for(i = 9; i>0; i--){
		if(i == 5){
			data->Latitude[i-1] = '.';
		} else {
			data->Latitude[i-1] = Latitude % 10 + '0';
			Latitude /= 10;
		}
	}

	//NS
	if(NS){
		data->NS = 'S';
	} else {
		data->NS = 'N';
	}

	//Longitude
	data->Longitude[10]=0;
	for(i = 10; i>0; i--){
		if(i == 6){
			data->Longitude[i-1] = '.';
		} else {
			data->Longitude[i-1] = Longitude % 10 + '0';
			Longitude /= 10;
		}
	}

	//EW
	if(EW){
		data->EW = 'W';
	} else {
		data->EW = 'E';
	}

	//ReceiverMode
	data->ReceiverMode = ReceiverMode + '0';

	//SatelliteNum
	if(SatelliteNum>=10){
		data->SatelliteNum[0] = SatelliteNum / 10 + '0';
		data->SatelliteNum[1] = SatelliteNum % 10 + '0';
		data->SatelliteNum[2] = 0;
	} else {
		data->SatelliteNum[0] = SatelliteNum + '0';
		data->SatelliteNum[1] = 0;
	}

	//Altitude
	data->Altitude[7]=0;
	data->Altitude[6] = '0';
	data->Altitude[5] = '.';
	for(i = 5; i>0; i--){
		data->Altitude[i-1] = Altitude % 10 + '0';
		Altitude /= 10;
	}

	//Data
	data->Data[6]=0;
	for(i = 6; i>0; i--){
		data->Data[i-1] = Data % 10 + '0';
		Data /= 10;
	}

	data->checksum = checksum;

}

void   GPGGA_Data2Google(GPGGA_Struct_t *data, char *link){

	char *x, tmp[4], Latitude[11], Longitude[12], Lat_out[11]="", Lon_out[11]="";
	int Lai, Lti;
	double Laf, Ltf;

	x = data->Latitude; //Широта

	tmp[0] = *x;
	x++;
	tmp[1] = *x;
	x++;
	tmp[2] = 0;
	Lai = atoi(tmp);
	Laf = atof(x);
	Laf = Laf/60 + Lai;
	ftoa(Laf, Latitude, 6);
	if(data->NS == 'S'){
		strcat(Lat_out, "-");
		strcat(Lat_out, Latitude);
	} else {
		strcat(Lat_out, Latitude);
	}


	x = data->Longitude; //Долгота
	tmp[0] = *x;
	x++;
	tmp[1] = *x;
	x++;
	tmp[2] = *x;
	x++;
	tmp[3] = 0;

	Lti = atoi(tmp);
	Ltf = atof(x);

	Ltf = Ltf/60 + Lti;
	ftoa(Ltf, Longitude, 6);
	if(data->EW == 'W'){
		strcat(Lon_out, "-");
		strcat(Lon_out, Longitude);
	} else {
		strcat(Lon_out, Longitude);
	}
	strcat(link, "https://www.google.com/maps/@");
	strcat(link, Lat_out);
	strcat(link, ",");
	strcat(link, Lon_out);
	strcat(link, ",18z");
}


//Функции для перевода float в string
// reverses a string 'str' of length 'len'
void reverse(char *str, int len)
{
    int i=0, j=len-1, temp;
    while (i<j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
}

 // Converts a given integer x to string str[].  d is the number
 // of digits required in output. If d is more than the number
 // of digits in x, then 0s are added at the beginning.
int itoa(int x, char str[], int d)
{
    int i = 0;
    while (x)
    {
        str[i++] = (x%10) + '0';
        x = x/10;
    }

    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';
    return i;
}

// Converts a floating point number to string.
void ftoa(float n, char *res, int afterpoint)
{
    int ipart = (int)n;
    float fpart = n - (float)ipart;
    int i = itoa(ipart, res, 0);

    if (afterpoint != 0)
    {
        res[i] = '.';
        fpart = fpart * pow(10, afterpoint);
        itoa((int)fpart, res + i + 1, afterpoint);
    }
}
