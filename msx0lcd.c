/*
  Copyright 2023 CHIKUWA TEIKOKU
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "msx0.h"
#include "msx0lcd.h"


char* _addr;
char _bkl;
char _disp;
char _cursor;
char _blink;
char _dl;
char _nol;
char _font;
char _dir;
char _shift;
char _dev_str[20];

int lcd_begin(char* addr)
{
    int i;
    int ret;
    int cnt;
    char** dname;
    char found_lcd1602;

    _addr = addr;

    cnt = iotfindc("device/i2c_a");
    if (cnt == -1) return -1;

    dname = (char**)malloc(sizeof(char*) * cnt);

    cnt = iotfind("device/i2c_a", dname);
    if (cnt == -1) return -1;

    found_lcd1602 = 0;
    for (i = 0; i < cnt; i++)
    {
        if (strcmp(dname[i], _addr) == 0) found_lcd1602 = 1;
        free(dname[i]);
    }

    free(dname);

    if (found_lcd1602 == 0)
    {
        printf("LCD 1602(0x%s) not found.", _addr);
        return -1;
    }

    sprintf(_dev_str, "device/i2c_a/%s", _addr);
}


void lcd_init()
{

    lcd_send(0x34);
    lcd_send(0x30);
    lcd_send(0x34);
    lcd_send(0x30);
    lcd_send(0x34);
    lcd_send(0x30);
    lcd_send(0x24);
    lcd_send(0x20);
}

void lcd_bklight(char bkl)
{
    _bkl = bkl;

    lcd_setdisp(_disp, _cursor, _blink);
}

void lcd_setdisp(char disp, char cursor, char blink)
{
    _disp = disp;
    _cursor = cursor;
    _blink = blink;

    lcd_send(0x04 | _bkl << 3);
    lcd_send(0x00 | _bkl << 3);
    lcd_send(0x84 | disp << 6 | cursor << 5 | blink << 4 | _bkl << 3);
    lcd_send(0x80 | disp << 6 | cursor << 5 | blink << 4 | _bkl << 3);
}

void lcd_funcset(char dl, char nol, char font)
{
    _dl = dl;
    _nol = nol;
    _font = font;

    lcd_send(0x24 | dl << 4 | _bkl << 3);
    lcd_send(0x20 | dl << 4 | _bkl << 3);
    lcd_send(0x44 | nol << 7 | font << 6 | _bkl << 3);
    lcd_send(0x40 | nol << 7 | font << 6 | _bkl << 3);
}

void lcd_clear()
{
    lcd_send(0x04 | _bkl << 3);
    lcd_send(0x00 | _bkl << 3);
    lcd_send(0x14 | _bkl << 3);
    lcd_send(0x10 | _bkl << 3);
}

void lcd_entrymode(char dir, char shift)
{
    _dir = dir;
    _shift = shift;

    lcd_send(0x04 | _bkl << 3);
    lcd_send(0x00 | _bkl << 3);
    lcd_send(0x44 | dir << 5 | shift << 4 | _bkl << 3);
    lcd_send(0x40 | dir << 5 | shift << 4 | _bkl << 3);
}

void lcd_home()
{
    lcd_send(0x04 | _bkl << 3);
    lcd_send(0x00 | _bkl << 3);
    lcd_send(0x24 | _bkl << 3);
    lcd_send(0x20 | _bkl << 3);
}

void lcd_setddaddr(unsigned char addr)
{
    lcd_send(0x84 | addr & 0x70 | _bkl << 3);
    lcd_send(0x80 | addr & 0x70 | _bkl << 3);
    lcd_send(0x04 | addr << 4 & 0xF0 | _bkl << 3);
    lcd_send(0x00 | addr << 4 & 0xF0 | _bkl << 3);
}

void lcd_setcursor(char x, char y)
{
    lcd_setddaddr(0x40 * y + x);
}
//
// CGRAMのアドレスを設定します。
//
void lcd_setcgaddr(unsigned char addr)
{
    lcd_send(0x44 | addr & 0x30 | _bkl << 3);
    lcd_send(0x40 | addr & 0x30 | _bkl << 3);
    lcd_send(0x04 | addr << 4 & 0xF0 | _bkl << 3);
    lcd_send(0x00 | addr << 4 & 0xF0 | _bkl << 3);
}

void lcd_writechr(char data)
{
    lcd_send(0x05 | data & 0xF0 | _bkl << 3);
    lcd_send(0x01 | data & 0xF0 | _bkl << 3);
    lcd_send(0x05 | data << 4 & 0xF0 | _bkl << 3);
    lcd_send(0x01 | data << 4 & 0xF0 | _bkl << 3);
}

void lcd_writestr(const char* data)
{
    int len = strlen(data);
    int i;
    for (i = 0; i < len; i++)
    {
        lcd_writechr(data[i]);
    }
}

void lcd_send(char data)
{
    iotputb(_dev_str, &data, 1);
}
