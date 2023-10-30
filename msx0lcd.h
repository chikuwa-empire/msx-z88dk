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
// �p�������ʐM���[�h��4bit�ɐݒ肵�܂��B
// �K���ŏ��Ɏ��s���Ă��������B
//
void lcd_init();

//
// �o�b�N���C�g��ON/OFF��؂�ւ��܂��B
//
void lcd_bklight(char bkl);

//
// �f�B�X�v���C�X�C�b�`�̐ݒ�����܂��B
//
void lcd_setdisp(char disp, char cursor, char blink);

//
// �p�������ʐM���[�h�A�f�B�X�v���C�s���A�g�p�t�H���g��ݒ肵�܂��B
// �p�������ʐM���[�h��4bit���w�肵�Ă��������B
//
void lcd_funcset(char dl, char nol, char font);

//
// �X�N���[���I�[���N���A�A�J�[�\���̓z�[���ֈړ����܂��B
//
void lcd_clear();

//
// ���̓��[�h��ݒ肵�܂��B
//
void lcd_entrymode(char dir, char shift);

//
// �J�[�\�����z�[���ֈړ����܂��B
// �V�t�g�͉����A�\���f�[�^�͕ۑ�����܂��B
//
void lcd_home();

//
// DDRAM�̃A�h���X��ݒ肵�܂��B
// 1�s��:0x00�`�A2�s��:0x40�`
//
void lcd_setddaddr(unsigned char addr);

//
// ���W�w���DDRAM�̃A�h���X��ݒ肵�܂��B
// y��0��1�̂ݑΉ����Ă��܂��B
//
void lcd_setcursor(char x, char y);

//
// CGRAM�̃A�h���X��ݒ肵�܂��B
//
void lcd_setcgaddr(unsigned char addr);

//
// �f�[�^��1�o�C�g���������݂܂��B
//
void lcd_writechr(char data);

//
// �f�[�^���o�C�g�z��ł܂Ƃ߂ď������݂܂��B
//
void lcd_writestr(const char* data);

//
// ���C�u�����̓����Ŏg�p�B
//
void lcd_send(char data);
