/*
  Copyright 2023 CHIKUWA TEIKOKU
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "msx0.h"
#include "msx0lcd.h"


//
// CLOCK-IC ������t�E�������擾���܂��B(MSX2�ȍ~)
// �N��1980�𑫂��Ă��������B�j����0�`6���Ԃ�܂����@��ˑ��ł��B
// 0 �b(1�̈�)  1 �b(10�̈�)  2 ��(1�̈�)   3 ��(10�̈�)  4 ��(1�̈�)  5 ��(10�̈�)  6 �j��
// 7 ��(1�̈�)  8 ��(10�̈�)  9 ��(1�̈�)  10 ��(10�̈�) 11 �N(1�̈�) 12 �N(10�̈�)
//
unsigned char msx_redclk(unsigned char r);

//
// ���ݎ�����LCD�ɕ\�����܂��B
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
