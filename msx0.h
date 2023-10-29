/*
  Copyright 2023 CHIKUWA TEIKOKU
*/
#define IOT_PORT 8

//
// 指定したデバイスパスのノード数を返却します。
// 存在しないパスを指定した場合は-1が返却されます。
//
int iotfindc(const char* p_path);

//
// 指定したデバイスパスのノード名の配列を返却します。
// 二次元配列の親側は呼び出し元で初期化しておいてください。
// 存在しないパスを指定した場合は-1が返却されます。
//
int iotfind(const char* p_path, char** p_list);

//
// 指定したノードから整数値を取得します。
// 存在しないパスを指定した場合は-1が返却されます。
//
int iotgeti(const char* p_path, int* p_ret);

//
// 指定したノードから文字列値(終端NULL)を取得します。
// 戻り値には取得した文字列長が返却されます。
// 存在しないパスを指定した場合は-1が返却されます。
//
int iotgets(const char* p_path, char* p_str);

//
// 指定したノードからバイトデータを取得します。
// 戻り値には取得したデータ数が返却されます。
// 存在しないパスを指定した場合は-1が返却されます。
//
int iotgetb(const char* p_path, char* p_bytes);

//
// 指定したノードに整数値を出力します。
// 存在しないパスを指定した場合は-1が返却されます。
//
int iotputi(const char* p_path, int val);

//
// 指定したノードに文字列値(終端NULL)を出力します。
// 存在しないパスを指定した場合は-1が返却されます。
//
int iotputs(const char* p_path, const char* p_str);

//
// 指定したノードにバイトデータを出力します。
// 文字列とは異なりNULLを含んだ状態でも指定した長さ分が送信されます。
// 存在しないパスを指定した場合は-1が返却されます。
//
int iotputb(const char* p_path, const char* p_bytes, unsigned char len);

//
// デバイスツリーのノード名を指定します。
// 指定した名前のデバイスが存在しない場合はゼロ以外の数値が返ってきます。
//
int sendnode(const char* p_path);
