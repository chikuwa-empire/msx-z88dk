/*
  Copyright 2023 CHIKUWA TEIKOKU
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "msx0.h"
#include "msx0lcd.h"


//
// CLOCK-IC から日付・時刻を取得します。(MSX2以降)
// 年は1980を足してください。曜日は0～6が返りますが機種依存です。
// 0 秒(1の位)  1 秒(10の位)  2 分(1の位)   3 分(10の位)  4 時(1の位)  5 時(10の位)  6 曜日
// 7 日(1の位)  8 日(10の位)  9 月(1の位)  10 月(10の位) 11 年(1の位) 12 年(10の位)
//
unsigned char msx_redclk(unsigned char r);

//
// 現在時刻をLCDに表示します。
//
void draw_clock();


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
    lcd_writestr("MSX0 LCD CLOCK");

	while (1)
	{
		draw_clock();
	}

    return 0;
}


void draw_clock()
{
    lcd_setcursor(4, 1);

	lcd_writechr(0x30 + msx_redclk(5));
	lcd_writechr(0x30 + msx_redclk(4));
	lcd_writechr(0x3A);
	lcd_writechr(0x30 + msx_redclk(3));
	lcd_writechr(0x30 + msx_redclk(2));
	lcd_writechr(0x3A);
	lcd_writechr(0x30 + msx_redclk(1));
	lcd_writechr(0x30 + msx_redclk(0));
}


unsigned char msx_redclk(unsigned char r)
{
	outp(0xB4, r);
	return inp(0xB5);
}
