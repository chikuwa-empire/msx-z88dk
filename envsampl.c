/*
  Copyright 2023 CHIKUWA TEIKOKU
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "msx0.h"
#include "msx0env.h"

int main(int argc, char* argv)
{
    double temp;
    double humi;

	env_begin(SLAVE_ADDR_SHT30);

	temp = env_temperature();
	humi = env_humidity();

	printf("temperature:%4.1lf%cC\n", temp, 0xDF);
	printf("humidity:%4.1lf%c", humi, 0x25);
}
