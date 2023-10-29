/*
  Copyright 2023 CHIKUWA TEIKOKU
*/
#define IOT_PORT 8

//
// �w�肵���f�o�C�X�p�X�̃m�[�h����ԋp���܂��B
// ���݂��Ȃ��p�X���w�肵���ꍇ��-1���ԋp����܂��B
//
int iotfindc(const char* p_path);

//
// �w�肵���f�o�C�X�p�X�̃m�[�h���̔z���ԋp���܂��B
// �񎟌��z��̐e���͌Ăяo�����ŏ��������Ă����Ă��������B
// ���݂��Ȃ��p�X���w�肵���ꍇ��-1���ԋp����܂��B
//
int iotfind(const char* p_path, char** p_list);

//
// �w�肵���m�[�h���琮���l���擾���܂��B
// ���݂��Ȃ��p�X���w�肵���ꍇ��-1���ԋp����܂��B
//
int iotgeti(const char* p_path, int* p_ret);

//
// �w�肵���m�[�h���當����l(�I�[NULL)���擾���܂��B
// �߂�l�ɂ͎擾���������񒷂��ԋp����܂��B
// ���݂��Ȃ��p�X���w�肵���ꍇ��-1���ԋp����܂��B
//
int iotgets(const char* p_path, char* p_str);

//
// �w�肵���m�[�h����o�C�g�f�[�^���擾���܂��B
// �߂�l�ɂ͎擾�����f�[�^�����ԋp����܂��B
// ���݂��Ȃ��p�X���w�肵���ꍇ��-1���ԋp����܂��B
//
int iotgetb(const char* p_path, char* p_bytes);

//
// �w�肵���m�[�h�ɐ����l���o�͂��܂��B
// ���݂��Ȃ��p�X���w�肵���ꍇ��-1���ԋp����܂��B
//
int iotputi(const char* p_path, int val);

//
// �w�肵���m�[�h�ɕ�����l(�I�[NULL)���o�͂��܂��B
// ���݂��Ȃ��p�X���w�肵���ꍇ��-1���ԋp����܂��B
//
int iotputs(const char* p_path, const char* p_str);

//
// �w�肵���m�[�h�Ƀo�C�g�f�[�^���o�͂��܂��B
// ������Ƃ͈قȂ�NULL���܂񂾏�Ԃł��w�肵�������������M����܂��B
// ���݂��Ȃ��p�X���w�肵���ꍇ��-1���ԋp����܂��B
//
int iotputb(const char* p_path, const char* p_bytes, unsigned char len);

//
// �f�o�C�X�c���[�̃m�[�h�����w�肵�܂��B
// �w�肵�����O�̃f�o�C�X�����݂��Ȃ��ꍇ�̓[���ȊO�̐��l���Ԃ��Ă��܂��B
//
int sendnode(const char* p_path);
