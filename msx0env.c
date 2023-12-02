/*
  Copyright 2023 CHIKUWA TEIKOKU
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "msx0.h"
#include "msx0env.h"

char* _addr;
double _temp;
double _humi;

int env_begin(char* addr)
{
    int i;
    int ret;
    int cnt;
    char** dname;
    char found_sht30;

	_addr = addr;

    cnt = iotfindc("device/i2c_a");
    if (cnt == -1) return -1;

    dname = (char**)malloc(sizeof(char*) * cnt);

    cnt = iotfind("device/i2c_a", dname);
    if (cnt == -1) return -1;

    found_sht30 = 0;
    for (i = 0; i < cnt; i++)
    {
        if (strcmp(dname[i], _addr) == 0) found_sht30 = 1;
        free(dname[i]);
    }

    free(dname);

    if (found_sht30 == 0)
    {
        printf("SHT30(0x%s) not found.", _addr);
        return -1;
    }
}

double env_temperature()
{
	get_env();
	return _temp;
}

double env_humidity()
{
	get_env();
	return _humi;
}

void get_env()
{
    int ret;
    char dev_str[20];
    char buf[20]; // MSX0がデータ長を16で返却してくるので応急処置

    sprintf(dev_str, "device/i2c_a/%s", _addr);

    buf[0] = 0x2C;
    buf[1] = 0x06;
    ret = iotputb(dev_str, buf, 2);

    ret = iotgetb(dev_str, buf);

    // 6バイト返却してきます。
    // printf("[0] %02X\n", buf[0]); // 気温MSB
    // printf("[1] %02X\n", buf[1]); // 気温LSB
    // printf("[2] %02X\n", buf[2]); // チェックサム
    // printf("[3] %02X\n", buf[3]); // 湿度MSB
    // printf("[4] %02X\n", buf[4]); // 湿度LSB
    // printf("[5] %02X\n", buf[5]); // チェックサム

    _temp = (buf[0] * 256.0f + buf[1]) * (175.0f / 65535.0f) - 45.0f;
    _humi = 100.0f * (buf[3] * 256.0f + buf[4]) / 65535.0f;
}
