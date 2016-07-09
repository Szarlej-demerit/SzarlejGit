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


int main(void){

	GRAPHICS_Init();

	GRAPHICS_Clear();

	GRAPHICS_AppendString("Hello World!");
	GRAPHICS_AppendLine();
	GRAPHICS_AppendString("Promwad");

	GRAPHICS_Update();

}



