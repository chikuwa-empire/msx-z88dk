/*
  Copyright 2023 CHIKUWA TEIKOKU
*/
#define SLAVE_ADDR_SHT30			"44"

//
// デバイスを使用可能にします。
//
int env_begin(char* addr);

//
// 気温(℃)を取得します。
//
double env_temperature();

//
// 湿度(％)を取得します。
//
double env_humidity();

//
// 温湿度センサーからデータを取得します。
//
void get_env();
