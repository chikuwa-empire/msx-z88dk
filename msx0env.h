/*
  Copyright 2023 CHIKUWA TEIKOKU
*/
#define SLAVE_ADDR_SHT30			"44"

//
// �f�o�C�X���g�p�\�ɂ��܂��B
//
int env_begin(char* addr);

//
// �C��(��)���擾���܂��B
//
double env_temperature();

//
// ���x(��)���擾���܂��B
//
double env_humidity();

//
// �����x�Z���T�[����f�[�^���擾���܂��B
//
void get_env();
