/*
  Copyright 2023 CHIKUWA TEIKOKU
*/
#define SLAVE_ADDR_LCD1602			"3F"

#define SETDISP_DISP_OFF			0
#define SETDISP_DISP_ON				1
#define SETDISP_CURSOR_OFF			0
#define SETDISP_CURSOR_ON			1
#define SETDISP_BLINK_OFF			0
#define SETDISP_BLINK_ON			1

#define FUNCSET_DL_4BIT				0
#define FUNCSET_DL_8BIT				1
#define FUNCSET_NOL_1LINE			0
#define FUNCSET_NOL_2LINES			1
#define FUNCSET_FONT_5x7			0
#define FUNCSET_FONT_5x10			1

#define ENTRYMODE_MOVDIR_LEFT		0
#define ENTRYMODE_MOVDIR_RIGHT		1
#define ENTRYMODE_SHIFT_OFF			0
#define ENTRYMODE_SHIFT_ON			1

//
// パラレル通信モードを4bitに設定します。
// 必ず最初に実行してください。
//
void lcd_init();

//
// バックライトのON/OFFを切り替えます。
//
void lcd_bklight(char bkl);

//
// ディスプレイスイッチの設定をします。
//
void lcd_setdisp(char disp, char cursor, char blink);

//
// パラレル通信モード、ディスプレイ行数、使用フォントを設定します。
// パラレル通信モードは4bitを指定してください。
//
void lcd_funcset(char dl, char nol, char font);

//
// スクリーンオールクリア、カーソルはホームへ移動します。
//
void lcd_clear();

//
// 入力モードを設定します。
//
void lcd_entrymode(char dir, char shift);

//
// カーソルをホームへ移動します。
// シフトは解消、表示データは保存されます。
//
void lcd_home();

//
// DDRAMのアドレスを設定します。
// 1行目:0x00～、2行目:0x40～
//
void lcd_setddaddr(unsigned char addr);

//
// 座標指定でDDRAMのアドレスを設定します。
// yは0と1のみ対応しています。
//
void lcd_setcursor(char x, char y);

//
// CGRAMのアドレスを設定します。
//
void lcd_setcgaddr(unsigned char addr);

//
// データを1バイト分書き込みます。
//
void lcd_writechr(char data);

//
// データをバイト配列でまとめて書き込みます。
//
void lcd_writestr(const char* data);

//
// ライブラリの内部で使用。
//
void lcd_send(char data);
