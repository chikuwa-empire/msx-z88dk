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
    if (lcd_begin(SLAVE_ADDR_LCD1602) == -1) return 1;

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
