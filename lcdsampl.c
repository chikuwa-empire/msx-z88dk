/*
  Copyright 2023 CHIKUWA TEIKOKU
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "msx0.h"
#include "msx0lcd.h"


int main(int argc, char* argv)
{
    int i;
    int ret;
    int cnt;
    char** dname;
    char found_lcd1602;
    char buf[10];

    cnt = iotfindc("device/i2c_a");
    if (cnt == -1) return 1;

    dname = (char**)malloc(sizeof(char*) * cnt);

    cnt = iotfind("device/i2c_a", dname);
    if (cnt == -1) return 1;

    found_lcd1602 = 0;
    for (i = 0; i < cnt; i++)
    {
        if (strcmp(dname[i], SLAVE_ADDR_LCD1602) == 0) found_lcd1602 = 1;
        free(dname[i]);
    }

    free(dname);

    if (found_lcd1602 == 0)
    {
        printf("LCD 1602(0x3F) not found.");
        return 1;
    }


    lcd_init();

    lcd_bklight(1);

    lcd_setdisp(SETDISP_DISP_ON, SETDISP_CURSOR_OFF, SETDISP_BLINK_OFF);

    lcd_funcset(FUNCSET_DL_4BIT, FUNCSET_NOL_2LINES, FUNCSET_FONT_5x7);

    lcd_clear();

    lcd_entrymode(ENTRYMODE_MOVDIR_RIGHT, ENTRYMODE_SHIFT_OFF);

    lcd_home();

    lcd_setcursor(0, 0);
    lcd_writestr("HELLO MSX0.");

    lcd_setcursor(0, 1);
    lcd_writechr(0xDC); // ワ
    lcd_writechr(0xB0); // ー
    lcd_writechr(0xB2); // イ
    lcd_writechr(0xDC); // ワ
    lcd_writechr(0xB0); // ー
    lcd_writechr(0xB2); // イ


    return 0;
}
