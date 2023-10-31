/*
  Copyright 2023 CHIKUWA TEIKOKU
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "msx0.h"


#define SLAVE_ADDR_SHT30			"44"


int main(int argc, char* argv)
{
    int i;
    int ret;
    int cnt;
    char** dname;
    char found_sht30;
    char dev_str[20];
    char buf[10];
    unsigned char press[3];
    double pres;
    double temp;
    double humi;

    cnt = iotfindc("device/i2c_a");
    if (cnt == -1) return 1;

    dname = (char**)malloc(sizeof(char*) * cnt);

    cnt = iotfind("device/i2c_a", dname);
    if (cnt == -1) return 1;

    found_sht30 = 0;
    for (i = 0; i < cnt; i++)
    {
        if (strcmp(dname[i], SLAVE_ADDR_SHT30) == 0) found_sht30 = 1;
        free(dname[i]);
    }

    free(dname);

    if (found_sht30 == 0)
    {
        printf("SHT30(0x44) not found.");
        return 1;
    }

    sprintf(dev_str, "device/i2c_a/%s", SLAVE_ADDR_SHT30);

    buf[0] = 0x2C;
    buf[1] = 0x06;
    ret = iotputb(dev_str, buf, 2);
    if (ret == -1) return 1;

    ret = iotgetb(dev_str, buf);
    if (ret == -1) return 1;

    // 6バイト返却してきます。
    // printf("[0] %02X\n", buf[0]); // 気温MSB
    // printf("[1] %02X\n", buf[1]); // 気温LSB
    // printf("[2] %02X\n", buf[2]); // チェックサム
    // printf("[3] %02X\n", buf[3]); // 湿度MSB
    // printf("[4] %02X\n", buf[4]); // 湿度LSB
    // printf("[5] %02X\n", buf[5]); // チェックサム

    temp = (buf[0] * 256.0 + buf[1]) * (175.0 / 65535.0) - 45.0;
    humi = 100.0 * (buf[3] * 256.0 + buf[4]) / 65535.0;

    printf("temperature:%4.1lf%cC\n", temp, 0xDF);
    printf("humidity:%4.1lf%c", humi, 0x25);

	return 0;
}
